#include "Window.h"
#include "Localizar.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThread]


void main(){

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::Windows editor;
    Project1::Localizar localizar;
    Application::Run(% editor);
    Application::Run(% localizar);

}