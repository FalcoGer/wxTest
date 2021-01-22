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

