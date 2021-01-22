/*

MIT License

Copyright (c) 2021 FalcoGer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
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

