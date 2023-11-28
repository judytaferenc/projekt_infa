#include "app.h"
#include "mainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);
bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("Aplikacja");
    mainFrame->SetClientSize(200, 150);
    mainFrame->Center();
    mainFrame->Show();
    return true;

}