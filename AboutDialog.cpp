#include "AboutDialog.h"

AboutDialog::AboutDialog(wxWindow* parent)
    : wxDialog(parent, wxID_ANY, "About", wxPoint(30,30), wxSize(1,1), wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP)
{
    wxStaticText* text = new wxStaticText(
        this
        , wxID_ANY
        ,   "This is a sample wxWidgets project.\n"
            "It was created to demonstrate some core\n"
            "concepts about how to use wxWidgets."
    );
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    boxSizer->Add(text, 1, wxALL | wxEXPAND, 20);

    // no need to manually add a close button.
    // will use OS compliant close button layout
    boxSizer->Add(this->CreateButtonSizer(wxCLOSE), 0, wxDOWN | wxRIGHT | wxLEFT | wxALIGN_CENTER, 20);

    SetSizerAndFit(boxSizer);
}

AboutDialog::~AboutDialog()
{
}

