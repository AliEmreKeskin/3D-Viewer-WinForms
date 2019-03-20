#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define DEFAULTH_ZOOM 1000

using namespace System::Windows::Forms;

float deltaWorldAngle_x = 0.0f;
float WorldAngle_x = 0.0f;
float deltaWorldAngle_y = 0.0f;
float WorldAngle_y = 0.0f;

float camPos_z = DEFAULTH_ZOOM;
float deltaCamPos_z = 0;
float zoomRatio = (DEFAULTH_ZOOM/camPos_z) * 100;

int width, height;
long size;
BYTE* image;
int* zData;

void ComputeWorld() {
	WorldAngle_x += deltaWorldAngle_x;
	WorldAngle_y += deltaWorldAngle_y;
}

namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}

			rtri = 0.0f;
			rquad = 0.0f;
		}


		System::Void Render(System::Void)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
			
			camPos_z += deltaCamPos_z;
			gluLookAt(0, 0, camPos_z, 0, 0, 0, 0, 1, 0);
			zoomRatio= (DEFAULTH_ZOOM / camPos_z) * 100;

			ComputeWorld();
			glRotatef(WorldAngle_y, 0, 1, 0);
			glRotatef(WorldAngle_x, 1, 0, 0);

			//glBegin(GL_TRIANGLES);								// Start drawing a triangle
			//glColor3f(1.0f, 0.0f, 0.0f);						// Red
			//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (front)
			//glColor3f(0.0f, 1.0f, 0.0f);						// Green
			//glVertex3f(-1.0f, -1.0f, 1.0f);					// Left of triangle (front)
			//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
			//glVertex3f(1.0f, -1.0f, 1.0f);					// Right of triangle (front)
			//glColor3f(1.0f, 0.0f, 0.0f);						// Red
			//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (right)
			//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
			//glVertex3f(1.0f, -1.0f, 1.0f);					// Left of triangle (right)
			//glColor3f(0.0f, 1.0f, 0.0f);						// Green
			//glVertex3f(1.0f, -1.0f, -1.0f);					// Right of triangle (right)
			//glColor3f(1.0f, 0.0f, 0.0f);						// Red
			//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (back)
			//glColor3f(0.0f, 1.0f, 0.0f);						// Green
			//glVertex3f(1.0f, -1.0f, -1.0f);					// Left of triangle (back)
			//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
			//glVertex3f(-1.0f, -1.0f, -1.0f);					// Right of triangle (back)
			//glColor3f(1.0f, 0.0f, 0.0f);						// Red
			//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (left)
			//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
			//glVertex3f(-1.0f, -1.0f, -1.0f);					// Left of triangle (left)
			//glColor3f(0.0f, 1.0f, 0.0f);						// Green
			//glVertex3f(-1.0f, -1.0f, 1.0f);					// Right of triangle (left)
			//glEnd();											// Done drawing the pyramid

			//bmp
			glBegin(GL_POINTS);
			float red;
			float green;
			float blue;
			float z;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					//RGB
					blue = image[y * width * 3 + x * 3];
					green = image[y * width * 3 + x * 3 + 1];
					red = image[y * width * 3 + x * 3 + 2];
					glColor3f(red / 255.0, green / 255.0, blue / 255.0);

					//Coordinates
					z = zData[y*width + x];
					glVertex3f(x - width / 2, y - height / 2, z);
				}
			}
			glEnd();

			rtri+=0.2f;											// Increase the rotation variable for the triangle
			rquad-=0.15f;										// Decrease the rotation variable for the quad
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}

	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
				{
					sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
					1,											// Version Number
					PFD_DRAW_TO_WINDOW |						// Format Must Support Window
					PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
					PFD_DOUBLEBUFFER,							// Must Support Double Buffering
					PFD_TYPE_RGBA,								// Request An RGBA Format
					16,										// Select Our Color Depth
					0, 0, 0, 0, 0, 0,							// Color Bits Ignored
					0,											// No Alpha Buffer
					0,											// Shift Bit Ignored
					0,											// No Accumulation Buffer
					0, 0, 0, 0,									// Accumulation Bits Ignored
					16,											// 16Bit Z-Buffer (Depth Buffer)  
					0,											// No Stencil Buffer
					0,											// No Auxiliary Buffer
					PFD_MAIN_PLANE,								// Main Drawing Layer
					0,											// Reserved
					0, 0, 0										// Layer Masks Ignored
				};
			
			GLint  iPixelFormat; 
		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height==0)										// Prevent A Divide By Zero By
			{
				height=1;										// Making Height Equal One
			}

			glViewport(0,0,width,height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,10000.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	};
}