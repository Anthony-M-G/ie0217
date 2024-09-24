#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP



#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private: // Eventos del frame
	void OnButtonClicked(wxCommandEvent& event); // Evento de click en el botón
	void OnCheckBoxClicked(wxCommandEvent& event); // Evento de click en el checkbox
	void onMouseMove(wxMouseEvent& event);
	// wxDECLARE_EVENT_TABLE(); // Macro para declarar la tabla de eventos
};

#endif // 0