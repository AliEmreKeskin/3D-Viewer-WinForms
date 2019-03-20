#pragma once

#include "OpenGL.h"
//#include <atlstr.h>
#include <fstream>
#include "imge_bmp.h"

using namespace System::Runtime::InteropServices;

int zoomRatio_int;

int * LoadZ(const char * filePath, int size)
{
	std::ifstream inData;
	inData.open(filePath);
	int* buffer = new int[size];
	for (int i = 0; i < size; i++) {
		inData >> buffer[i];
	}
	inData.close();
	return buffer;
}

namespace OpenGL_on_a_Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			OpenGL = gcnew COpenGL(this, 640, 480);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolStripMenuItem^  openTxtToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::Button^  button9;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTxtToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(795, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->openTxtToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->openToolStripMenuItem->Text = L"Open BMP";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// openTxtToolStripMenuItem
			// 
			this->openTxtToolStripMenuItem->Name = L"openTxtToolStripMenuItem";
			this->openTxtToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->openTxtToolStripMenuItem->Text = L"Open txt";
			this->openTxtToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openTxtToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(702, 425);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(23, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"◀";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button1_MouseDown);
			this->button1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button1_MouseUp);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(731, 425);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(23, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"●";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(760, 425);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(23, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"▶";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button3_MouseDown);
			this->button3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button3_MouseUp);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(731, 454);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(23, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"▼";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button4_MouseDown);
			this->button4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button4_MouseUp);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(731, 396);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(23, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"▲";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button5_MouseDown);
			this->button5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button5_MouseUp);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(731, 367);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(23, 23);
			this->button6->TabIndex = 6;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button6_MouseDown);
			this->button6->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button6_MouseUp);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(731, 338);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(23, 23);
			this->button7->TabIndex = 7;
			this->button7->Text = L"0";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(731, 309);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(23, 23);
			this->button8->TabIndex = 8;
			this->button8->Text = L"+";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button8_MouseDown);
			this->button8->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button8_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(690, 343);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"%";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(702, 343);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"100";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(708, 28);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 11;
			this->button9->Text = L"button9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 489);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"OpenGL on a Windows Form using Managed C++";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->Render();
				 OpenGL->SwapOpenGLBuffers();
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ str0 = openFileDialog1->FileName;
			const char* str1 = (const char*)(Marshal::StringToHGlobalAnsi(str0)).ToPointer();
			LPCTSTR str2 = (LPCTSTR)str1;

			//LPCTSTR str2 = L"D://staj//resim.bmp";

			image = LoadBMP(width, height, size, str2);
		}
		timer1->Enabled = true;
		label2->Text = width.ToString();
	}
private: System::Void button1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_y = 1.0f;
}
private: System::Void button1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_y = 0.0f;
}
private: System::Void button5_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_x = 1.0f;
}
private: System::Void button5_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_x = 0;
}
private: System::Void button3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_y = -1;
}
private: System::Void button3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_y = 0;
}
private: System::Void button4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_x = -1;
}
private: System::Void button4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaWorldAngle_x = 0;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	WorldAngle_x = 0;
	WorldAngle_y = 0;
}
private: System::Void button6_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaCamPos_z = 30.0f;
	zoomRatio_int = zoomRatio;
	label2->Text = zoomRatio_int.ToString();
}
private: System::Void button6_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaCamPos_z = 0;
	zoomRatio_int = zoomRatio;
	label2->Text = zoomRatio_int.ToString();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	camPos_z = DEFAULTH_ZOOM;
	zoomRatio_int = zoomRatio;
	label2->Text = zoomRatio_int.ToString();
}
private: System::Void button8_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaCamPos_z = -30.0f;
	zoomRatio_int = zoomRatio;
	label2->Text = zoomRatio_int.ToString();
}
private: System::Void button8_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	deltaCamPos_z = 0;
	zoomRatio_int = zoomRatio;
	label2->Text = zoomRatio_int.ToString();
}
private: System::Void openTxtToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::String^ path = openFileDialog2->FileName;
		const char* str = (const char*)(Marshal::StringToHGlobalAnsi(path)).ToPointer();
		
	}
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	LPCTSTR str2 = L"resim.bmp";
	image = LoadBMP(width, height, size, str2);

	const char* zPath = "derinlik.txt";
	zData = LoadZ(zPath, size);

	timer1->Enabled = true;
}
};
}

