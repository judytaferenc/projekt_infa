#pragma once

#include <wx/wx.h>

class User {
public:
    User();
    User(const wxString& username, const wxString& password);
    wxString getUsername() const;
    wxString getPassword() const;
    void setUsername(const wxString& username);
    void setPassword(const wxString& password);

    bool saveToFile(const wxString& filename) const;
    static bool authenticate(const wxString& username, const wxString& password, const wxString& filename);


private:
    wxString username;
    wxString password;
};