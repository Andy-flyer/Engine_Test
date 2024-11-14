#pragma once
#include "AirSpeedSettings.h"
#include "CDrawOpenGL.h"
#include "EngineData.h"


namespace EngineTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// summary for EWD
	/// </summary>


	public ref class EWD : public System::Windows::Forms::Form
	{
	private:
		Point staticLocation;
		Point formOffSetLocation;

		int groupBoxWidth;
		int groupBoxHeight;

		bool first_load;

	public:
		double stepHeight;
		double stepSpeed;
		double stepTemperature;
		double minTemperature;
		double realTemperature;
		double frequency;
		double step;
		
		int fps;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Required constructor variable
		/// </summary>
		CDrawOpenGL^ DrawOpenGL;

	public:
		EWD(void)
		{
			InitializeComponent();
			//
			//TODO: add the code to constructor
			//
			staticLocation.X = 0;
			staticLocation.Y = 0;
			formOffSetLocation.X = 0;
			formOffSetLocation.Y = 0;
			first_load = true;

			groupBoxWidth = this->groupBox1->Size.Width;
			groupBoxHeight = this->groupBox1->Size.Height;

			stepHeight = 1.;
			stepSpeed = 0.1;
			stepTemperature = 10.;
			minTemperature = -25.;
			realTemperature = 0.;
			frequency = 10000000.;
			step = 0.2;
			fps = 0;

			DrawOpenGL = gcnew CDrawOpenGL(this, groupBoxWidth, groupBoxHeight);
		}

	protected:
		/// <summary>
		/// Release all used resources.
		/// </summary>
		~EWD()
		{
			if (components)
			{
				delete components;
			}
		}

		void Update(double step);
		void SetDataHeight();
		void SetDataSpeed();
		void SetDataTemperature();
		void SetMaxTLA();


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for constructor support - do not change
		/// the contents of this method using a code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(529, 846);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->button4);
			this->groupBox5->Controls->Add(this->textBox1);
			this->groupBox5->Location = System::Drawing::Point(7, 720);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(515, 119);
			this->groupBox5->TabIndex = 27;
			this->groupBox5->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(11, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 25);
			this->label5->TabIndex = 27;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 16);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Maximum angle of Thrust Levelers Angle:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(130, 37);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 25;
			this->button4->Text = L"Set";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &EWD::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 24;
			this->textBox1->Text = L"50";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_TLA_TextChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->textBox11);
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Controls->Add(this->label18);
			this->groupBox4->Controls->Add(this->trackBar3);
			this->groupBox4->Controls->Add(this->label17);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->button7);
			this->groupBox4->Controls->Add(this->textBox8);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Location = System::Drawing::Point(7, 484);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(515, 230);
			this->groupBox4->TabIndex = 23;
			this->groupBox4->TabStop = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(252, 43);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(35, 16);
			this->label21->TabIndex = 25;
			this->label21->Text = L"Step";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Current temperature [dT]: ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(194, 136);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 25);
			this->label9->TabIndex = 17;
			this->label9->Text = L"0";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(257, 62);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 22);
			this->textBox11->TabIndex = 24;
			this->textBox11->Text = L"10";
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Temperature_TextChanged);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(398, 168);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Select";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &EWD::button3_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(135, 43);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(32, 16);
			this->label18->TabIndex = 15;
			this->label18->Text = L"Max";
			// 
			// trackBar3
			// 
			this->trackBar3->Enabled = false;
			this->trackBar3->LargeChange = 1;
			this->trackBar3->Location = System::Drawing::Point(23, 168);
			this->trackBar3->Maximum = 6;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(369, 56);
			this->trackBar3->TabIndex = 9;
			this->trackBar3->Value = 2;
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &EWD::trackBar3_ValueChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(13, 43);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(28, 16);
			this->label17->TabIndex = 15;
			this->label17->Text = L"Min";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(13, 18);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(149, 16);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Range of Temperature: ";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(371, 62);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Set";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &EWD::button7_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(138, 62);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 19;
			this->textBox8->Text = L"35";
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Temperature_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(16, 62);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"-25";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Temperature_TextChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->trackBar2);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Location = System::Drawing::Point(7, 248);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(515, 230);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(252, 43);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(35, 16);
			this->label20->TabIndex = 24;
			this->label20->Text = L"Step";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(194, 136);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 25);
			this->label8->TabIndex = 16;
			this->label8->Text = L"0.0";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(257, 62);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 22);
			this->textBox10->TabIndex = 23;
			this->textBox10->Text = L"0.1";
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Speed_TextChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(398, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Select";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EWD::button2_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(135, 43);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 16);
			this->label16->TabIndex = 15;
			this->label16->Text = L"Max";
			// 
			// trackBar2
			// 
			this->trackBar2->Enabled = false;
			this->trackBar2->LargeChange = 1;
			this->trackBar2->Location = System::Drawing::Point(23, 168);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(369, 56);
			this->trackBar2->TabIndex = 3;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &EWD::trackBar2_ValueChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(13, 43);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(28, 16);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Min";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 136);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Current speed [M]: ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 18);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(112, 16);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Range of Speed: ";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(371, 62);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Set";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &EWD::button6_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(138, 62);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 18;
			this->textBox6->Text = L"1.0";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Speed_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(16, 62);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 17;
			this->textBox5->Text = L"0.0";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Speed_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Location = System::Drawing::Point(7, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(515, 230);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(252, 43);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(35, 16);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Step";
			// 
			// trackBar1
			// 
			this->trackBar1->Enabled = false;
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(23, 168);
			this->trackBar1->Maximum = 15;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(369, 56);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &EWD::trackBar1_ValueChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(257, 62);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 22);
			this->textBox9->TabIndex = 23;
			this->textBox9->Text = L"1";
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Height_TextChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(398, 168);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EWD::button1_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(135, 43);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(32, 16);
			this->label14->TabIndex = 15;
			this->label14->Text = L"Max";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(194, 136);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 25);
			this->label7->TabIndex = 15;
			this->label7->Text = L"0";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(13, 43);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(28, 16);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Min";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Current Height [km]: ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 18);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(107, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Range of Height:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(371, 62);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 20;
			this->button5->Text = L"Set";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &EWD::button5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(138, 62);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"11";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Height_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(16, 62);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &EWD::textBox_Height_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &EWD::MyForm_Update);
			// 
			// EWD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1540, 846);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1558, 893);
			this->MinimumSize = System::Drawing::Size(1558, 893);
			this->Name = L"EWD";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EWD";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EWD::MyForm_Paint);
			this->Move += gcnew System::EventHandler(this, &EWD::EWD_Move);
			this->groupBox1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);

		}


	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		DrawOpenGL->Render();
		Update();
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		DrawOpenGL->ReSizeGLScene(this->Size.Width, this->Size.Height);
	}

	private: System::Void MyForm_Update(System::Object^ sender, System::EventArgs^ e) {
		Stopwatch^ stopwatch = gcnew Stopwatch();
		frequency = stopwatch->Frequency; //frequency of timer

		stopwatch->Start();

		Update(step);

		stopwatch->Stop();

		step = (double)stopwatch->ElapsedTicks / frequency; //converting tacts to secs
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		SetDataHeight();
		button1->Enabled = false;
	}

	private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		double value;

		value = (trackBar1->Value) * stepHeight;
		label7->Text = Convert::ToString(value);

		button1->Enabled = true;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		SetDataSpeed();
		button2->Enabled = false;
	}

	private: System::Void trackBar2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		double value;

		value = ((trackBar2->Value) * stepSpeed);
		label8->Text = Convert::ToString(value);

		button2->Enabled = true;
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		SetDataTemperature();
		button3->Enabled = false;
	}

	private: System::Void trackBar3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		double value;

		value = ((trackBar3->Value) * stepTemperature) + minTemperature;
		label9->Text = Convert::ToString(value);

		button3->Enabled = true;
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		double value_min, value_max, value_step;

		Double::TryParse(textBox9->Text, value_step);

		Double::TryParse(textBox3->Text, value_min);
		value_min = (float)(value_min / value_step);
		trackBar1->Minimum = value_min;

		Double::TryParse(textBox4->Text, value_max);
		value_max = (float)(value_max / value_step);
		trackBar1->Maximum = value_max;

		trackBar1->Value = trackBar1->Minimum;
		label7->Text = Convert::ToString(value_min * value_step);

		stepHeight = value_step;

		trackBar1->Enabled = true;
		button5->Enabled = false;
	}

	private: System::Void textBox_Height_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button5->Enabled = true;
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		double value_min, value_max, value_step;

		Double::TryParse(textBox10->Text, value_step);

		Double::TryParse(textBox5->Text, value_min);
		value_min = (float)(value_min / value_step);
		trackBar2->Minimum = value_min;

		Double::TryParse(textBox6->Text, value_max);
		value_max = (float)(value_max / value_step);
		trackBar2->Maximum = value_max;

		trackBar2->Value = trackBar2->Minimum;
		label8->Text = Convert::ToString(value_min * value_step);

		stepSpeed = value_step;

		trackBar2->Enabled = true;
		button6->Enabled = false;
	}

	private: System::Void textBox_Speed_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button6->Enabled = true;
	}

	private: System::Void textBox_Temperature_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button7->Enabled = true;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		double value_min, value_max, value_step;

		Double::TryParse(textBox11->Text, value_step);

		Double::TryParse(textBox7->Text, value_min);
		minTemperature = value_min;
		value_min = (float)(value_min / value_step);
		trackBar3->Minimum = ((value_min * 10.) - (value_min * 10.)) / 10.;

		Double::TryParse(textBox8->Text, value_max);
		value_max = (float)(value_max / value_step);
		trackBar3->Maximum = ((value_max * 10.) - (value_min * 10.)) / 10.;

		trackBar3->Value = trackBar3->Minimum;

		realTemperature = value_min * 10.;
		label9->Text = Convert::ToString(value_min * value_step);

		stepTemperature = value_step;

		trackBar3->Enabled = true;
		button7->Enabled = false;
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		SetMaxTLA();

		button4->Enabled = false;

	}
	private: System::Void textBox_TLA_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button4->Enabled = true;
	}

	private: System::Void EWD_Move(System::Object^ sender, System::EventArgs^ e) {

		if (!this->first_load) {
			formOffSetLocation.X = staticLocation.X;
			formOffSetLocation.Y = staticLocation.Y;
			this->Location = formOffSetLocation;
		}

		this->first_load = false;
	}
	};

}
#pragma endregion
