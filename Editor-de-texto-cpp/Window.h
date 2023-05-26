#pragma once
#include <string>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
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



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Editor = (gcnew System::Windows::Forms::TextBox());
			this->Enviar = (gcnew System::Windows::Forms::Button());
			this->TextoEnviar = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Editor
			// 
			this->Editor->Location = System::Drawing::Point(12, 12);
			this->Editor->Multiline = true;
			this->Editor->Name = L"Editor";
			this->Editor->ReadOnly = true;
			this->Editor->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Editor->Size = System::Drawing::Size(641, 168);
			this->Editor->TabIndex = 0;
			// 
			// Enviar
			// 
			this->Enviar->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Enviar->Location = System::Drawing::Point(12, 212);
			this->Enviar->Name = L"Enviar";
			this->Enviar->Size = System::Drawing::Size(641, 61);
			this->Enviar->TabIndex = 1;
			this->Enviar->Text = L"Enviar";
			this->Enviar->UseVisualStyleBackColor = true;
			this->Enviar->Click += gcnew System::EventHandler(this, &MyForm::Enviar_Click);
			// 
			// TextoEnviar
			// 
			this->TextoEnviar->Location = System::Drawing::Point(12, 186);
			this->TextoEnviar->Name = L"TextoEnviar";
			this->TextoEnviar->Size = System::Drawing::Size(641, 20);
			this->TextoEnviar->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 333);
			this->Controls->Add(this->TextoEnviar);
			this->Controls->Add(this->Enviar);
			this->Controls->Add(this->Editor);
			this->Name = L"MyForm";
			this->Text = L"Editor de texto";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Enviar_Click(System::Object^ sender, System::EventArgs^ e) {
		Editor->Text += TextoEnviar->Text;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
