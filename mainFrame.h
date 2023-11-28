#pragma once
#include "User.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    void onRegisterClicked(wxCommandEvent& evt);
    void onCreateClicked(wxCommandEvent& evt);
    void onLoginClicked(wxCommandEvent& evt);
    void onLogClicked(wxCommandEvent& evt);
    void showRegistrationUI(bool show);
    void showLogOrSignUI(bool show);
    void showLoginUI(bool show);
    wxPanel* panel;
    wxStaticText* textWelcome;
    wxButton* buttonLogIn;
    wxButton* buttonRegister;

    wxStaticText* textRegister;
    wxTextCtrl* ctrlLogin;
    wxTextCtrl* ctrlPasswd;
    wxStaticText* textLogin;
    wxStaticText* textPasswd;
    wxButton* buttonCreate;

    wxStaticText* textLog;
    wxTextCtrl* ctrlLogin2;
    wxTextCtrl* ctrlPasswd2;
    wxStaticText* textLogin2;
    wxStaticText* textPasswd2;
    wxButton* buttonLog;

    User newUser;
};

