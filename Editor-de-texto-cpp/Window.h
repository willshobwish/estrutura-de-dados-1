#pragma once
#include <string>
#include "Localizar.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Windows : public System::Windows::Forms::Form
	{
	public:
		Windows(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Windows()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ Editor;
	protected:

	private: System::Windows::Forms::Button^ Enviar;
	private: System::Windows::Forms::TextBox^ TextoEnviar;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	protected:
		String^ anterior;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:




	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Editor = (gcnew System::Windows::Forms::TextBox());
			this->Enviar = (gcnew System::Windows::Forms::Button());
			this->TextoEnviar = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Editor
			// 
			this->Editor->Location = System::Drawing::Point(12, 25);
			this->Editor->Multiline = true;
			this->Editor->Name = L"Editor";
			this->Editor->ReadOnly = true;
			this->Editor->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Editor->Size = System::Drawing::Size(672, 168);
			this->Editor->TabIndex = 0;
			// 
			// Enviar
			// 
			this->Enviar->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Enviar->Location = System::Drawing::Point(12, 225);
			this->Enviar->Name = L"Enviar";
			this->Enviar->Size = System::Drawing::Size(672, 61);
			this->Enviar->TabIndex = 1;
			this->Enviar->Text = L"Enviar";
			this->Enviar->UseVisualStyleBackColor = true;
			this->Enviar->Click += gcnew System::EventHandler(this, &Windows::Enviar_Click);
			// 
			// TextoEnviar
			// 
			this->TextoEnviar->Location = System::Drawing::Point(12, 199);
			this->TextoEnviar->Name = L"TextoEnviar";
			this->TextoEnviar->Size = System::Drawing::Size(672, 20);
			this->TextoEnviar->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 292);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(672, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Voltar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Windows::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 321);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(672, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Avançar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 381);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(672, 20);
			this->textBox1->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 407);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(672, 19);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Localizar";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 365);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Localizar";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Texto";
			// 
			// Windows
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 436);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TextoEnviar);
			this->Controls->Add(this->Enviar);
			this->Controls->Add(this->Editor);
			this->Name = L"Windows";
			this->Text = L"Editor de texto";
			this->Load += gcnew System::EventHandler(this, &Windows::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Enviar_Click(System::Object^ sender, System::EventArgs^ e) {
		anterior = Editor->Text;
		Editor->Text += TextoEnviar->Text;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Editor->Text = anterior;
	}

};
}
