#include "MainFrame.h"
#include "AboutDialog.h"
#include "AskUser.h"

// segfaults/bugs with simple constants, needs to be static
const char* MainFrame::TITLE = "My awesome title!";
const int MainFrame::PX = 30;
const int MainFrame::PY = 30;
const int MainFrame::SX = 400;
const int MainFrame::SY = 300;

MainFrame::MainFrame()
    : wxFrame(nullptr, static_cast<wxWindowID>(IDs::MainFrame), wxString(TITLE), wxPoint(PX, PY), wxSize(SX, SY))
{
    // create bar
    // no need to call delete. new is overloaded for wx elements.
    menuBar = new wxMenuBar();
    // create menues
    menuFile = new wxMenu();
    menuConfig = new wxMenu();
    menuHelp = new wxMenu();

    // Tip is shown in status bar if it exists
    menuFile->Append(static_cast<int>(IDs::MenuItemClose), "Exit", "Close the application");

    menuConfig->Append(static_cast<int>(IDs::MenuItemTooltips), "Tooltips", "Enable or Disable tooltips", true);
    menuConfig->FindChildItem(static_cast<int>(IDs::MenuItemTooltips))->Check(true);
    menuConfig->Append(static_cast<int>(IDs::MenuItemAskUserTest), "Test Modal", "Opens a Modal to test user interaction.");

    menuHelp->Append(static_cast<int>(IDs::MenuItemAbout), "About...", "Information about the application");

    // Use Bind instead of Connect
    Bind(
        wxEVT_COMMAND_MENU_SELECTED             // type of command handled
        , &MainFrame::onClickMenuItem           // callback function pointer
        , this                                  // parent
        , static_cast<int>(IDs::_MenuItemFirst)  // first id to bind for
        , static_cast<int>(IDs::_MenuItemLast)-1 // last id to bind for
    );

    // construct menu bar from menues
    menuBar->Append(menuFile, "File");
    menuBar->Append(menuConfig, "Config");
    menuBar->Append(menuHelp, "Help");

    SetMenuBar(menuBar);

    // misc
    lbl_Text = new wxStaticText(this, static_cast<wxWindowID>(IDs::lbl_Text), "Press a button!");

    // create sizers
    gridSizer = new wxGridSizer(1, 5, wxSize(5,5));

    boxSizer = new wxBoxSizer(wxVERTICAL);
    boxSizer->Add(lbl_Text,
                    0, // make vectically un-stretchable
                    wxALL, // implicit top alignment, border all around
                    10 // border 10 px
    );

    boxSizer->Add(gridSizer, 1, wxEXPAND, 0);

    // create buttons
    v_btn_Buttons = std::make_unique<std::vector<wxButton*>>(5);
    for (int i = 0; i < 5; i++)
    {
        int id = static_cast<int>(IDs::Button1) + i;
        wxString txt = wxString(fmt::format("Button{0}", (i+1)).c_str());
        wxButton* btn = new wxButton(this, id, txt);
        btn->SetToolTip(fmt::format("Change text to reflect that this button (#{}) has been pressed.", i+1));
        // Use Bind instead of Connect
        btn->Bind(
            wxEVT_BUTTON                    // event type
            , &MainFrame::onClickButton     // callback
            , this                          // parent
        );
        v_btn_Buttons->push_back(btn);
        gridSizer->Add(btn);
    }

    // status bar
    statusBar = new wxStatusBar(this, wxID_ANY /*, style, name*/);
    // status bar can contain elements!
    statusBar->SetFieldsCount(2);


    this->SetStatusBar(statusBar);
    this->SetSizerAndFit(boxSizer);
}

MainFrame::~MainFrame()
{
}

void MainFrame::onClickMenuItem(wxCommandEvent& evt)
{
    switch (static_cast<IDs>(evt.GetId()))
    {
        case IDs::MenuItemClose:
        {
            Close();
            break;
        }
        case IDs::MenuItemTooltips:
        {
            wxMenuItem* mi = FindItemInMenuBar(evt.GetId());
            if(mi->IsChecked())
            {
                this->SetStatusBar(statusBar);
            }
            else
            {
                this->SetStatusBar(nullptr);
            }
            break;
        }
        case IDs::MenuItemAbout:
        {
            AboutDialog* dialog = new AboutDialog(this);
            // dialog->Show(); // wrong, doesn't block inputs on main window
            dialog->ShowModal(); // blocks inputs on main window

            // with new needs destroy call
            // with stack variable, doesn't need destroy call
            dialog->Destroy();
            break;
        }
        case IDs::MenuItemAskUserTest:
        {
            AskUser* dialog = new AskUser(this, "Test Question", "Answer will be displayed in Main Window.");
            int result = dialog->ShowModal();

            lbl_Text->SetLabel(fmt::format("You clicked {} (raw: {})", (result == wxID_OK ? "Ok" : "Cancel"), result));

            dialog->Destroy();
            break;
        }
        default:
        {
            evt.Skip(); // we didn't handle the event, pass through to parents
            break;
        }
    }
}

void MainFrame::onClickButton(wxCommandEvent& evt)
{
    wxString txt = wxString(fmt::format(
        "Pressed Button #{0} (ID: {1})",
        evt.GetId() - static_cast<int>(IDs::Button1) + 1,
        evt.GetId()
    ));
    lbl_Text->SetLabelText(txt);
}
