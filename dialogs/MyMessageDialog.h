//
// Created by artem on 14.12.2019.
//

#ifndef PATTERNS_MYMESSAGEDIALOG_H
#define PATTERNS_MYMESSAGEDIALOG_H


#include <gtkmm/messagedialog.h>

class MyMessageDialog : public Gtk::MessageDialog{
public:
    MyMessageDialog(std::string msg): MessageDialog(msg,false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_CLOSE, true){
        this->set_tooltip_text("Ошибка");
        //this->signal_button_release_event().connect(sigc::mem_fun(*this, close));
        this->set_deletable(true);
        this->run();
        delete this;
    }
    void closeDialog() {
        this->hide();
        delete this;
    }
    /*
    void showMsg(std::string msg){
        if(dialog == nullptr)
            dialog = new MessageDialog(msg,false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, true);
        dialog->set_tooltip_text("Ошибка");
        dialog->set_message(msg);
        dialog->show();
        dialog->signal_button_press_event().connect(sigc::mem_fun(*dialog, dialog->hide));
    }
    */
};


#endif //PATTERNS_MYMESSAGEDIALOG_H
