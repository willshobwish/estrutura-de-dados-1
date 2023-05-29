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
	private: System::Windows::Forms::Button^ Voltar;
	private: System::Windows::Forms::Button^ Avancar;





	protected:
		String^ anterior;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ TextoLocalizar;

	private: System::Windows::Forms::Button^ Localizar;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Apagar;
	private: System::Windows::Forms::Button^ ApagarTudo;


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
			this->Voltar = (gcnew System::Windows::Forms::Button());
			this->Avancar = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->TextoLocalizar = (gcnew System::Windows::Forms::TextBox());
			this->Localizar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Apagar = (gcnew System::Windows::Forms::Button());
			this->ApagarTudo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Editor
			// 
			this->Editor->Location = System::Drawing::Point(12, 25);
			this->Editor->Multiline = true;
			this->Editor->Name = L"Editor";
			this->Editor->ReadOnly = true;
			this->Editor->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Editor->Size = System::Drawing::Size(600, 200);
			this->Editor->TabIndex = 0;
			// 
			// Enviar
			// 
			this->Enviar->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Enviar->Location = System::Drawing::Point(12, 257);
			this->Enviar->Name = L"Enviar";
			this->Enviar->Size = System::Drawing::Size(600, 30);
			this->Enviar->TabIndex = 1;
			this->Enviar->Text = L"Enviar";
			this->Enviar->UseVisualStyleBackColor = true;
			this->Enviar->Click += gcnew System::EventHandler(this, &Windows::Enviar_Click);
			// 
			// TextoEnviar
			// 
			this->TextoEnviar->Location = System::Drawing::Point(12, 231);
			this->TextoEnviar->Name = L"TextoEnviar";
			this->TextoEnviar->Size = System::Drawing::Size(600, 20);
			this->TextoEnviar->TabIndex = 2;
			// 
			// Voltar
			// 
			this->Voltar->Location = System::Drawing::Point(12, 293);
			this->Voltar->Name = L"Voltar";
			this->Voltar->Size = System::Drawing::Size(300, 30);
			this->Voltar->TabIndex = 3;
			this->Voltar->Text = L"Voltar";
			this->Voltar->UseVisualStyleBackColor = true;
			this->Voltar->Click += gcnew System::EventHandler(this, &Windows::button1_Click);
			// 
			// Avancar
			// 
			this->Avancar->Location = System::Drawing::Point(312, 293);
			this->Avancar->Name = L"Avancar";
			this->Avancar->Size = System::Drawing::Size(300, 30);
			this->Avancar->TabIndex = 4;
			this->Avancar->Text = L"Avançar";
			this->Avancar->UseVisualStyleBackColor = true;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// TextoLocalizar
			// 
			this->TextoLocalizar->Location = System::Drawing::Point(12, 381);
			this->TextoLocalizar->Name = L"TextoLocalizar";
			this->TextoLocalizar->Size = System::Drawing::Size(600, 20);
			this->TextoLocalizar->TabIndex = 5;
			// 
			// Localizar
			// 
			this->Localizar->Location = System::Drawing::Point(12, 407);
			this->Localizar->Name = L"Localizar";
			this->Localizar->Size = System::Drawing::Size(600, 30);
			this->Localizar->TabIndex = 6;
			this->Localizar->Text = L"Localizar";
			this->Localizar->UseVisualStyleBackColor = true;
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
			// Apagar
			// 
			this->Apagar->Location = System::Drawing::Point(12, 329);
			this->Apagar->Name = L"Apagar";
			this->Apagar->Size = System::Drawing::Size(300, 30);
			this->Apagar->TabIndex = 9;
			this->Apagar->Text = L"Apagar";
			this->Apagar->UseVisualStyleBackColor = true;
			// 
			// ApagarTudo
			// 
			this->ApagarTudo->Location = System::Drawing::Point(312, 329);
			this->ApagarTudo->Name = L"ApagarTudo";
			this->ApagarTudo->Size = System::Drawing::Size(300, 30);
			this->ApagarTudo->TabIndex = 10;
			this->ApagarTudo->Text = L"Apagar tudo";
			this->ApagarTudo->UseVisualStyleBackColor = true;
			this->ApagarTudo->Click += gcnew System::EventHandler(this, &Windows::button5_Click);
			// 
			// Windows
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 449);
			this->Controls->Add(this->ApagarTudo);
			this->Controls->Add(this->Apagar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Localizar);
			this->Controls->Add(this->TextoLocalizar);
			this->Controls->Add(this->Avancar);
			this->Controls->Add(this->Voltar);
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

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Editor->Text = "";
}
};
}
