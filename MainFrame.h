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

