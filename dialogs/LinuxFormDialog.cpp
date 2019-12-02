//
// Created by artem on 26.11.2019.
//

#include "LinuxFormDialog.h"

LinuxFormDialog* LinuxFormDialog::window = nullptr;
Gtk::Main LinuxFormDialog::app = Gtk::Main();
Glib::RefPtr<Gtk::Builder> LinuxFormDialog::builder = Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade");