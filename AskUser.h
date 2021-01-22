#pragma once


class AskUser : public wxDialog
{
public:
    AskUser(wxWindow* parent, wxString title, wxString text);
    virtual ~AskUser();

};

