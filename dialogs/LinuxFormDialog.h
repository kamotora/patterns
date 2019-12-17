//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_LINUXFORMDIALOG_H
#define PATTERNS_LINUXFORMDIALOG_H


#include "IDialog.h"
#include <gtkmm.h>
#include <cairomm/cairomm.h>
#include <iostream>

#include "../goods/Shawarma.h"
#include "../goods/TypePizzaFactory.h"
#include "../goods/Pizza.h"
#include "../client/TypeDelivery.h"
#include "../client/Order.h"
#include "../client/Clients.h"
#include "PizzaDialog.h"
#include "ShawarmaDialog.h"
#include "WebmoneyPayWindow.h"
#include "CardPayWindow.h"


class LinuxFormDialog : public IDialog,  public Gtk::Window{
private:

    static LinuxFormDialog *window;
    Gtk::Entry *nameTextField, *telTextField, *addressTextField, *emailTextField;
    Gtk::TextView *goodsList;
    Gtk::RadioButton *courierRadioButton, *dronRadioButton, *cardRB, *webmoneyRB;
    Gtk::CheckButton *smsCheckBox, *telCheckBox, *telegramCheckBox;
    Gtk::Button *addShawarmaButton, *addPizzaButton, *completeButton;
    Gtk::Label *sumOrder;
    IOrder *order;
    static Gtk::Main app;
public:
    ICommand * showDialogForPay(IOrder *payOrder){
        ICommand *res;
        if(cardRB->get_active()){
            CardPayWindow::getInstance()->setOrder(payOrder);
            res =  CardPayWindow::getInstance()->show();
        }
        else{
            WebmoneyPayWindow::getInstance()->setOrder(payOrder);
            res = WebmoneyPayWindow::getInstance()->showWindow();
        }
        app.quit();
        return res;
    }
    IOrder *showDialogForOrder(){
        order = new Order(nullptr, NONE);
        app.run(*window);
        return order;
    }
    static LinuxFormDialog* getInstance(){
        delete window;
        Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade")->get_widget_derived("window", window);
        return window;
    }
    LinuxFormDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::Window(cobject)
    {
        builder->get_widget("nameTextField", nameTextField);
        builder->get_widget("telTextField", telTextField);
        builder->get_widget("addressTextField", addressTextField);
        builder->get_widget("emailTextField", emailTextField);

        builder->get_widget("courierRadioButton", courierRadioButton);
        builder->get_widget("dronRadioButton", dronRadioButton);
        builder->get_widget("smsCheckBox", smsCheckBox);

        builder->get_widget("telCheckBox", telCheckBox);
        builder->get_widget("telegramCheckBox", telegramCheckBox);

        builder->get_widget("addPizzaButton", addPizzaButton);
        builder->get_widget("addShawarmaButton", addShawarmaButton);
        builder->get_widget("completeButton", completeButton);

        builder->get_widget("cardRB", cardRB);
        builder->get_widget("webmoneyRB", webmoneyRB);

        builder->get_widget("sumOrder", sumOrder);

        builder->get_widget("goodsList", goodsList);

        addPizzaButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::addPizza));
        addShawarmaButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::addShawarma));
        completeButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::createNewOrder));

    }

private:
    /** "quit" action handler. */
    void
    OnQuit()
    {
        hide();
    }

    void createNewOrder(){
        string name = nameTextField->get_text();
        if(name.empty()) {
            new MyMessageDialog("Укажите имя клиента");
            return;
        }
        string tel = telTextField->get_text();
        if(tel.empty()) {
            new MyMessageDialog("Укажите номер телефона");
            return;
        }
        string address = addressTextField->get_text();
        if(address.empty()) {
            new MyMessageDialog("Укажите адрес");
            return;
        }
        string email = emailTextField->get_text();
        Client *client;
        if(email.empty())
             client = Clients::getClient(name,address,tel);
        else
            client = Clients::getClient(name,address,tel, email);
        TypeDelivery typeDelivery = courierRadioButton->get_active() ? TypeDelivery::COURIER : TypeDelivery::DRONE;
        if(order == nullptr || order->getGoods().empty()){
            new MyMessageDialog("В заказе нет ни одного продукта");
            return;
        }
        else{
            order->setClient(client);
            order->setTypeDelivery(typeDelivery);
        }
        OnQuit();
    }

    void addShawarma ()
    {
        ShawarmaDialog::getInstance()->setOrder(order);
        ShawarmaDialog::getInstance()->showWindow();
        updateInfo();
    }

    void addPizza ()
    {
        PizzaDialog::getInstance()->setOrder(order);
        PizzaDialog::getInstance()->show();
        updateInfo();
    }

    void updateInfo(){
        GtkTextIter iter;
        auto buffer = goodsList->get_buffer();
        goodsList->set_editable(true);
        buffer->erase(buffer->begin(),buffer->end());
        goodsList->set_editable(false);
        for(auto product : order->getGoods()){
            goodsList->set_editable(true);
            buffer->insert_interactive(buffer->get_iter_at_line(buffer->get_line_count()),product->toString(), goodsList->get_editable());
            goodsList->set_editable(false);
        }
        sumOrder->set_text("Итого: "+to_string(order->countPrice())+" руб.");
    }
};


#endif //PATTERNS_LINUXFORMDIALOG_H
