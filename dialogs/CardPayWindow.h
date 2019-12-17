//
// Created by artem on 14.12.2019.
//

#ifndef PATTERNS_CARDPAYWINDOW_H
#define PATTERNS_CARDPAYWINDOW_H


#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include <gtkmm/builder.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include "../client/IOrder.h"
#include "../client/Client.h"
#include "../log/Logger.h"
#include "MyMessageDialog.h"
#include "../client/commands/CardPay.h"

class CardPayWindow : public Gtk::Window {
private:
    static CardPayWindow *cardWindow;
    static Gtk::Main app;
    static Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Entry *cardHolderField, *cvvField, *numCardField;
    Gtk::Button *addCardButton, *backCardButton;
    IOrder *order = nullptr;
    CardPay *pay = nullptr;
public:
    static CardPayWindow* getInstance(){
        if(cardWindow == nullptr)
             Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade")->get_widget_derived("cardPayWindow", cardWindow);
        return cardWindow;
    }

    CardPay* show(){
        app.run(*cardWindow);
        delete cardWindow;
        cardWindow = nullptr;
        return pay;
    }

    CardPayWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::Window(cobject) {
        /* Retrieve all widgets. */
        builder->get_widget("cardHolderField", cardHolderField);
        builder->get_widget("cvvField", cvvField);
        builder->get_widget("numCardField", numCardField);
        builder->get_widget("addCardButton", addCardButton);
        builder->get_widget("backCardButton", backCardButton);

        /* Connect signals. */
        addCardButton->signal_clicked().connect(sigc::mem_fun(*this, &CardPayWindow::addCard));
        backCardButton->signal_clicked().connect(sigc::mem_fun(*this, &CardPayWindow::hide));
    }

    void addCard() {
        std::string cardHolder = cardHolderField->get_text();
        std::string cvv = cvvField->get_text();
        std::string numCard = numCardField->get_text();
        if(numCard.empty()){
            new MyMessageDialog("Номер карты не указан");
            return;
        }
        if(cvv.empty()){
            new MyMessageDialog("CVV не указан");
            return;
        }
        if(cardHolder.empty()){
            new MyMessageDialog("Владелец карты не указан");
            return;
        }
        pay = new CardPay(numCard, cardHolder, cvv, order);
        order = nullptr;
        hide();
    }

    void setOrder(IOrder *order){
        this->order = order;
    }
};


#endif //PATTERNS_CARDPAYWINDOW_H
