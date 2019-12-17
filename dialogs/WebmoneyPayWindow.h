//
// Created by artem on 14.12.2019.
//

#ifndef PATTERNS_WEBMONEYPAYWINDOW_H
#define PATTERNS_WEBMONEYPAYWINDOW_H


#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include <gtkmm/builder.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include "../client/IOrder.h"
#include "../client/Client.h"
#include "../client/commands/WebmoneyPay.h"
#include "MyMessageDialog.h"

class WebmoneyPayWindow : public Gtk::Window{
private:
    static WebmoneyPayWindow *webmoneyWindow;
    static Gtk::Main app;
    static Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Entry *senderField, *takerField;
    Gtk::Button *addWebmoneyButton, *backWebmobeyButton;
    IOrder *order = nullptr;
    WebmoneyPay *pay = nullptr;
public:
    static WebmoneyPayWindow* getInstance(){
        if(webmoneyWindow == nullptr)
            Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade")->get_widget_derived("webmoneyPayWindow", webmoneyWindow);
        return webmoneyWindow;
    }

    WebmoneyPay* showWindow(){
        app.run(*webmoneyWindow);
        delete webmoneyWindow;
        webmoneyWindow = nullptr;
        return pay;
    }

    WebmoneyPayWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::Window(cobject)
    {
        /* Retrieve all widgets. */
        builder->get_widget("senderField", senderField);
        builder->get_widget("takerField", takerField);
        builder->get_widget("addWmButton", addWebmoneyButton);
        builder->get_widget("backWmButton", backWebmobeyButton);

        /* Connect signals. */
        addWebmoneyButton->signal_clicked().connect(sigc::mem_fun(*this, &WebmoneyPayWindow::addWebmoney));
        backWebmobeyButton->signal_clicked().connect(sigc::mem_fun(*this, &WebmoneyPayWindow::hide));
   }

    void addWebmoney() {
        std::string senderPocket = senderField->get_text();
        std::string takerPocket = takerField->get_text();
        if(senderPocket.empty() || takerPocket.empty()){
            Logger::getLogger()->message("Один из кошельков не указан", Logger::NOTIF);
            new MyMessageDialog("Один из кошельков не указан");
            return;
        }
        pay = new WebmoneyPay(senderPocket, takerPocket, order);
        order = nullptr;
        hide();
    }
    void setOrder(IOrder *order){
        this->order = order;
    }

};


#endif //PATTERNS_WEBMONEYPAYWINDOW_H
