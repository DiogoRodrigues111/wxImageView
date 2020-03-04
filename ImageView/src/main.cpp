#include "../include/vw.h"

MainFrame::MainFrame(const wxString title)
: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800,600))
{
    wxKeyboardState* state = new wxKeyboardState();
    menu_bar = new wxMenuBar();
    menu = new wxMenu;
    menu_open = new wxMenuItem(nullptr, ID_MENU_DIALOG, _("Open"));

    menu->SetTitle("Dialog");
    menu_open->SetMenu(menu);
    menu->Append(menu_open);
    menu_bar->Append(menu, _("Dialog"));

    SetMenuBar(menu_bar);

    Centre();
    
    Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnOpenDialog));

    state->SetControlDown(true);
}

void MainFrame::NewImageSetProperty(unsigned int width,
                 unsigned int height, const wxString & _t)
{
    image = new wxImage(_t, wxBITMAP_TYPE_ANY);
    image->LoadFile(_t, wxBITMAP_TYPE_ANY);
}

bool MainFrame::IsDisplayImage(bool t) {
    switch(t) {
        case false:
            t = false;
        break;

        case true:
            NewImageSetProperty(800, 600,
                    file_dialog->GetFilename());
            t = true;
        break;
    }

    return false;
}

void MainFrame::OnOpenDialog(wxCommandEvent& event) {
    file_dialog = new wxFileDialog(this);

    auto hResult = file_dialog->ShowModal();
    auto get_filename = file_dialog->GetFilename();
    auto getPath = file_dialog->GetPath();

    switch(hResult) {
        case wxID_OK:
            IsDisplayImage(true);
        break;

        case wxID_CANCEL:
            IsDisplayImage(false);
            return;
        break;
    }
}

bool MainApp::OnInit() {
    MainFrame *frame = new MainFrame("Image View C++");
    frame->Show(true);

    return true;
}

IMPLEMENT_APP(MainApp);
DECLARE_APP(MainApp);