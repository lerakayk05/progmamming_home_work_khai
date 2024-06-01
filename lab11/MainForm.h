#pragma once

namespace FunctionCalculator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ labelInput;
    private: System::Windows::Forms::TextBox^ textBoxInput;
    private: System::Windows::Forms::Button^ buttonCalculate;
    private: System::Windows::Forms::Label^ labelResult;

    private:
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelInput = (gcnew System::Windows::Forms::Label());
            this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
            this->buttonCalculate = (gcnew System::Windows::Forms::Button());
            this->labelResult = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // labelInput
            //
            this->labelInput->AutoSize = true;
            this->labelInput->Location = System::Drawing::Point(13, 13);
            this->labelInput->Name = L"labelInput";
            this->labelInput->Size = System::Drawing::Size(48, 13);
            this->labelInput->TabIndex = 0;
            this->labelInput->Text = L"Enter x:";
            //
            // textBoxInput
            //
            this->textBoxInput->Location = System::Drawing::Point(67, 10);
            this->textBoxInput->Name = L"textBoxInput";
            this->textBoxInput->Size = System::Drawing::Size(100, 20);
            this->textBoxInput->TabIndex = 1;
            //
            // buttonCalculate
            //
            this->buttonCalculate->Location = System::Drawing::Point(16, 36);
            this->buttonCalculate->Name = L"buttonCalculate";
            this->buttonCalculate->Size = System::Drawing::Size(75, 23);
            this->buttonCalculate->TabIndex = 2;
            this->buttonCalculate->Text = L"Calculate";
            this->buttonCalculate->UseVisualStyleBackColor = true;
            this->buttonCalculate->Click += gcnew System::EventHandler(this, &MainForm::buttonCalculate_Click);
            //
            // labelResult
            //
            this->labelResult->AutoSize = true;
            this->labelResult->Location = System::Drawing::Point(16, 66);
            this->labelResult->Name = L"labelResult";
            this->labelResult->Size = System::Drawing::Size(40, 13);
            this->labelResult->TabIndex = 3;
            this->labelResult->Text = L"Result:";
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 111);
            this->Controls->Add(this->labelResult);
            this->Controls->Add(this->buttonCalculate);
            this->Controls->Add(this->textBoxInput);
            this->Controls->Add(this->labelInput);
            this->Name = L"MainForm";
            this->Text = L"Function Calculator";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            double x = Convert::ToDouble(textBoxInput->Text);
            double y = 4 * Math::Pow((x - 3), 6) - 7 * Math::Pow((x - 3), 3) + 2;
            labelResult->Text = "Result: " + y.ToString();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Invalid input. Please enter a numeric value.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}
