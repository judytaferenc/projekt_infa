#include "User.h"
#include <wx/file.h>

User::User() {}

User::User(const wxString& username, const wxString& password)
    : username(username), password(password) {}

wxString User::getUsername() const {
    return username;
}

wxString User::getPassword() const {
    return password;
}

void User::setUsername(const wxString& username) {
    this->username = username;
}

void User::setPassword(const wxString& password) {
    this->password = password;
}

bool User::saveToFile(const wxString& filename) const {
    wxFile file(filename, wxFile::write_append);

    if (!file.IsOpened()) {
        wxLogError("Could not open file for writing: %s", filename);
        return false;
    }

    wxString userData = "Username: " + username + "\nPassword: " + password + "\n";
    if (file.Write(userData.ToUTF8())) {
        return true;
    }
    else {
        wxLogError("Failed to write user data to file: %s", filename);
        return false;
    }
}
bool User::authenticate(const wxString& username, const wxString& password, const wxString& filename) {
    wxFile file(filename, wxFile::read);
    if (!file.IsOpened()) {
        wxLogError("Failed to open user data file for reading.");
        return false;
    }

    wxString fileContent;
    file.ReadAll(&fileContent);

    wxString userData = "Username: " + username + "\nPassword: " + password;
    return (fileContent.find(userData) != wxString::npos);
}