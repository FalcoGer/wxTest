#include "AskUser.h"

AskUser::AskUser(wxWindow* parent, wxString title, wxString text)
    : wxDialog(parent, wxID_ANY, title, wxPoint(30, 30), wxSize(1,1), wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* label = new wxStaticText(
        this
        , wxID_ANY
        , text
    );
    sizer->Add(label, 1, wxALL | wxEXPAND, 20);
    // valid flags: wxOK, wxCANCEL, wxYES, wxNO, wxAPPLY, wxCLOSE, wxHELP, wxNO_DEFAULT
    sizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxDOWN | wxRIGHT | wxLEFT | wxALIGN_CENTER, 20);

    SetSizerAndFit(sizer);
}

AskUser::~AskUser()
{
}

