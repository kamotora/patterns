//
// Created by artem on 14.12.2019.
//

#ifndef PATTERNS_MYMESSAGEDIALOG_H
#define PATTERNS_MYMESSAGEDIALOG_H


#include <gtkmm/messagedialog.h>

class MyMessageDialog : public Gtk::MessageDialog{
private:
   static MessageDialog *dialog;
public:
    static void showMsg(std::string msg){
        if(dialog == nullptr)
            dialog = new MessageDialog(msg,false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK_CANCEL, true);
        dialog->set_tooltip_text("Ошибка");
        dialog->set_message(msg);
    }
};


#endif //PATTERNS_MYMESSAGEDIALOG_H
