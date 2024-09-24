#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MainFrame* frame = new MainFrame("Hello World");
	frame->SetClientSize(400, 300);
	frame->Center();
	frame->Show();
	return true;
}
