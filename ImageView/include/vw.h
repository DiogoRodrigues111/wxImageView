#include <wx/wx.h>
#include <wx/image.h>

#define ID_MENU_DIALOG      1

class MainFrame : public wxFrame {
    public:
        MainFrame(const wxString title);

    private:
        void OnOpenDialog(wxCommandEvent& event);
        bool IsDisplayImage(bool t);
        void NewImageSetProperty(unsigned int width,
                 unsigned int height, const wxString & _t);

    private:
        wxImage* image;
        wxFileDialog* file_dialog;
        wxMenu *menu;
        wxMenuItem *menu_open;
        wxMenuBar *menu_bar;
        wxPanel *panel;
        //wxImagePanel *panelImage;
};

class MainPanel : wxPanel {
    public:
        MainPanel(wxFrame *parent, wxString file, wxBitmapType format);

    public: 
        wxBitmap bitmap;

        void PaintEvent(wxPaintEvent & evt);
        void PaintNow();
        
        void Render(wxDC & dc);

    DECLARE_EVENT_TABLE()
};

class MainApp : public wxApp {
    public:
        virtual bool OnInit() override;
};