#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/application.h>
#pragma clang diagnostic pop

using namespace std;

class buttons_t: public Gtk::Window {

public:

  buttons_t() {
    m_button.add_pixlabel("info.xpm", "cool button");

    set_title("Pixmap'd buttons!");
    set_border_width(10);

    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                &buttons_t::on_button_clicked) );

    add(m_button);

    show_all_children();
  }

  virtual ~buttons_t() = default;

protected:

  //Signal handlers:
  void on_button_clicked(){
    std::cout << "The Button was clicked." << std::endl;
  }

  //Child widgets:
  Gtk::Button m_button;

};  // buttons_t

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  buttons_t buttons;

  //Shows the window and returns when it is closed.
  return app->run(buttons);
} // main
