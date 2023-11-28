#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    panel = new wxPanel(this);

    textWelcome = new wxStaticText(panel, wxID_ANY, "Welcome", wxPoint(75, -1));
    buttonLogIn = new wxButton(panel, wxID_ANY, "Log in", wxPoint(50, 50), wxSize(100, 35));
    buttonRegister = new wxButton(panel, wxID_ANY, "Create account", wxPoint(50, 100), wxSize(100, 35));

    buttonLogIn->Bind(wxEVT_BUTTON, &MainFrame::onLoginClicked, this);
    buttonRegister->Bind(wxEVT_BUTTON, &MainFrame::onRegisterClicked, this);


    textLog = new wxStaticText(panel, wxID_ANY, "Log in", wxPoint(65, -1));
    textLogin2 = new wxStaticText(panel, wxID_ANY, "Username:", wxPoint(65, 20));
    ctrlLogin2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 40), wxSize(100, -1));
    textPasswd2 = new wxStaticText(panel, wxID_ANY, "Password:", wxPoint(65, 65));
    ctrlPasswd2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 85), wxSize(100, -1), wxTE_PASSWORD);
    buttonLog = new wxButton(panel, wxID_ANY, "Log in", wxPoint(50, 115), wxSize(100, -1));

    buttonLog->Bind(wxEVT_BUTTON, &MainFrame::onLogClicked, this);
    textLog->Hide();
    ctrlLogin2->Hide();
    ctrlPasswd2->Hide();
    textLogin2->Hide();
    textPasswd2->Hide();
    buttonLog->Hide();



    textRegister = new wxStaticText(panel, wxID_ANY, "Create account", wxPoint(65, -1));
    textLogin = new wxStaticText(panel, wxID_ANY, "Username:", wxPoint(65, 20));
    ctrlLogin = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 40), wxSize(100, -1));
    textPasswd = new wxStaticText(panel, wxID_ANY, "Password:", wxPoint(65, 65));
    ctrlPasswd = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 85), wxSize(100, -1), wxTE_PASSWORD);
    buttonCreate = new wxButton(panel, wxID_ANY, "Create your account", wxPoint(50, 115), wxSize(100, -1));

    buttonCreate->Bind(wxEVT_BUTTON, &MainFrame::onCreateClicked, this);

    textRegister->Hide();
    ctrlLogin->Hide();
    ctrlPasswd->Hide();
    textLogin->Hide();
    textPasswd->Hide();
    buttonCreate->Hide();
}

void MainFrame::showLogOrSignUI(bool show) {
    textWelcome->Show(show);
    buttonLogIn->Show(show);
    buttonRegister->Show(show);
}

void MainFrame::showLoginUI(bool show)
{
    textLog->Show(show);
    ctrlLogin2->Show(show);
    ctrlPasswd2->Show(show);
    textLogin2->Show(show);
    textPasswd2->Show(show);
    buttonLog->Show(show);
}

void MainFrame::showRegistrationUI(bool show) {
    textRegister->Show(show);
    ctrlLogin->Show(show);
    ctrlPasswd->Show(show);
    textLogin->Show(show);
    textPasswd->Show(show);
    buttonCreate->Show(show);
}


void MainFrame::onRegisterClicked(wxCommandEvent& evt) {
    showLogOrSignUI(false);
    showRegistrationUI(true);
}
void MainFrame::onLoginClicked(wxCommandEvent& evt)
{
    showLogOrSignUI(false);
    showLoginUI(true);
}

void MainFrame::onCreateClicked(wxCommandEvent& evt) {
    wxString login = ctrlLogin->GetValue();
    wxString passwd = ctrlPasswd->GetValue();

    if (login.IsEmpty() || passwd.IsEmpty()) {
        wxLogError("Username and password cannot be empty.");
        return;
    }

    newUser = User(login, passwd);

    if (!newUser.saveToFile("user_data.txt")) {
        wxLogError("Failed to save user data to file.");
    }
    else {
        wxLogMessage("Congratulations! Your account has been created! Now you can log in.");
        showRegistrationUI(false);
        showLogOrSignUI(true);

    }
}
void MainFrame::onLogClicked(wxCommandEvent& evt) {
    wxString login = ctrlLogin2->GetValue();
    wxString passwd = ctrlPasswd2->GetValue();

    if (login.IsEmpty() || passwd.IsEmpty()) {
        wxLogError("Username and password cannot be empty.");
        return;
    }

    if (User::authenticate(login, passwd, "user_data.txt")) {
        wxLogMessage("Login successful!");
    }
    else {
        wxLogError("Invalid username or password.");
    }
}