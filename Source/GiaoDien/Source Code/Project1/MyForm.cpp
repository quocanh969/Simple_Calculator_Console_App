#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
[STAThread]
void main(cli::array<System::String ^>^ args)
{
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
Project1::MyForm form;

Application::Run(%form);
}