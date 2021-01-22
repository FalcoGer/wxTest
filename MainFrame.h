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
#pragma once
#include "pch.h"

class MainFrame : public wxFrame
{
private:
    // constants
    static const char* TITLE;
    static const int PX;
    static const int PY;
    static const int SX;
    static const int SY;

private:
    // member variables

private:
    // Layout and Windows

    // layout using sizers
    /*
     * +-----------------+
     * | MENU            |
     * +-----------------+
     * |+---------------+|
     * ||BoxSizer (col) ||
     * ||TextLabel      ||
     * |+---------------+|
     * ||+-------------+||
     * |||GridSizer    |||
     * |||BTN|BTN|...  |||
     * ||+-------------+||
     * |+---------------+|
     * +-----------------+
    */

    // wxMenuBar { wxMenu {wxMenuItem,...}, ... }
    wxStatusBar*                                statusBar       = nullptr;

    wxMenuBar*                                  menuBar         = nullptr;
    wxMenu*                                     menuFile        = nullptr;
    wxMenu*                                     menuConfig      = nullptr;
    wxMenu*                                     menuHelp        = nullptr;

    wxBoxSizer*                                 boxSizer        = nullptr;
    wxGridSizer*                                gridSizer       = nullptr;

    wxStaticText*                               lbl_Text        = nullptr;
    std::unique_ptr<std::vector<wxButton*>>     v_btn_Buttons   = nullptr;

protected:
    // Event handlers
    void onClickMenuItem(wxCommandEvent& evt);
    void onClickButton(wxCommandEvent& evt);

public:
    MainFrame();
    virtual ~MainFrame();

    // used to identify elements
    // can be extracted from events
    enum class IDs : wxWindowID
    {
        MainFrame       = 10000,
        lbl_Text,
        _MenuItemFirst  = 10100,
        MenuItemClose   = _MenuItemFirst,
        MenuItemTooltips,
        MenuItemAskUserTest,
        MenuItemAbout,
        _MenuItemLast,
        Button1         = 10500,
        Button2,
        Button3,
        Button4,
        Button5
    };
};

