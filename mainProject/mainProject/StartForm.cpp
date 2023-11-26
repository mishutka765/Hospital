#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;
int barrel;
[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	mainProject::StartForm form;
	Application::Run(% form);
	return 0;
}