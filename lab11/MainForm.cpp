private: System::Windows::Forms::Button^ buttonLoad;
private: System::Windows::Forms::Button^ buttonSave;
//
// buttonLoad
//
this->buttonLoad->Location = System::Drawing::Point(97, 36);
this->buttonLoad->Name = L"buttonLoad";
this->buttonLoad->Size = System::Drawing::Size(75, 23);
this->buttonLoad->TabIndex = 4;
this->buttonLoad->Text = L"Load";
this->buttonLoad->UseVisualStyleBackColor = true;
this->buttonLoad->Click += gcnew System::EventHandler(this, &MainForm::buttonLoad_Click);
//
// buttonSave
//
this->buttonSave->Location = System::Drawing::Point(178, 36);
this->buttonSave->Name = L"buttonSave";
this->buttonSave->Size = System::Drawing::Size(75, 23);
this->buttonSave->TabIndex = 5;
this->buttonSave->Text = L"Save";
this->buttonSave->UseVisualStyleBackColor = true;
this->buttonSave->Click += gcnew System::EventHandler(this, &MainForm::buttonSave_Click);

private: System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Text Files|*.txt|All Files|*.*";
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        StreamReader^ reader = gcnew StreamReader(openFileDialog->FileName);
        textBoxInput->Text = reader->ReadLine();
        reader->Close();
    }
}

private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
    SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
    saveFileDialog->Filter = "Text Files|*.txt|All Files|*.*";
    if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        StreamWriter^ writer = gcnew StreamWriter(saveFileDialog->FileName);
        writer->WriteLine(labelResult->Text);
        writer->Close();
    }
}
