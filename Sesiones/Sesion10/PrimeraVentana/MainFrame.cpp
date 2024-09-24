#include "MainFrame.hpp"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/gauge.h>
#include <wx/choice.h>





MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);

	this->CreateStatusBar(); // Barra de estado

    panel->Bind(wxEVT_MOTION, &MainFrame::onMouseMove, this); // Evento dinámico

    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	button->SetBackgroundColour(wxColour(0, 255, 0));
    
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this, button->GetId()); // Manejo de evento dinámico

    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55));
    checkBox->Bind(wxEVT_CHECKBOX, &MainFrame::OnCheckBoxClicked, this, checkBox->GetId()); // Evento dinámico
    
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(120, 150));

    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(100, -1));

    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));

    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
    gauge->SetValue(50);

    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
    choice->Select(0);

    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));
    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);
}

void MainFrame::OnButtonClicked(wxCommandEvent& event) { // Método que se ejecuta al hacer click en el botón
	this->SetTitle("Button clicked");
	wxMessageBox("Button clicked", "Info", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnCheckBoxClicked(wxCommandEvent& event) { // Método que se ejecuta al hacer click en el checkbox
	wxCheckBox* checkBox = (wxCheckBox*)event.GetEventObject();
	wxString state = checkBox->GetValue() ? "checked" : "unchecked";
	wxMessageBox("CheckBox " + state, "Info", wxOK | wxICON_INFORMATION);
}

void MainFrame::onMouseMove(wxMouseEvent& event) {
    wxPoint point = event.GetPosition();
    wxString position = wxString::Format("Mouse position: x = %d, Y = %d", point.x, point.y);
	wxLogStatus(position);
}

//wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) // Macro para definir la tabla de eventos estáticos
//    EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked) 
//    EVT_CHECKBOX(wxID_ANY, MainFrame::OnCheckBoxClicked)
//wxEND_EVENT_TABLE()