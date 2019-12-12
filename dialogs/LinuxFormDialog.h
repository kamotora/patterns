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

class LinuxFormDialog : public IDialog,  public Gtk::Window{
private:
    /* виджет окна */
    static LinuxFormDialog *window;
    static Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Entry *nameTextField, *telTextField, *addressTextField;
    Gtk::TextView *goodsList;
    Gtk::RadioButton *courierRadioButton, *dronRadioButton;
    Gtk::CheckButton *smsCheckBox, *telCheckBox, *telegramCheckBox;
    Gtk::Button *addShawarmaButton, *addPizzaButton, *completeButton;
    IOrder *order = nullptr;
    static Gtk::Main app;
public:
    ICommand * showDialogForPay(){
        return nullptr;
    }
    IOrder *showDialogForOrder(){

        app.run(*window);
        delete window;
        window = nullptr;
        return order;
    }
    static LinuxFormDialog* getInstance(){
        if(window == nullptr){
            //app = Gtk::Main();
            //builder = Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade");
            builder->get_widget_derived("window", window);
            if(window == nullptr)
                std::cerr << "ERRRORRRR" << std::endl;
        }
        return window;
    }
    LinuxFormDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::Window(cobject)
    {
        this->builder = builder;
        /* Retrieve all widgets. */
        builder->get_widget("nameTextField", nameTextField);
        builder->get_widget("telTextField", telTextField);
        builder->get_widget("addressTextField", addressTextField);

        builder->get_widget("courierRadioButton", courierRadioButton);
        builder->get_widget("dronRadioButton", dronRadioButton);
        builder->get_widget("smsCheckBox", smsCheckBox);

        builder->get_widget("telCheckBox", telCheckBox);
        builder->get_widget("telegramCheckBox", telegramCheckBox);

        builder->get_widget("addPizzaButton", addPizzaButton);
        builder->get_widget("addShawarmaButton", addShawarmaButton);
        builder->get_widget("completeButton", completeButton);


        builder->get_widget("goodsList", goodsList);

        /* Connect signals. */
        addPizzaButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::addPizza));
        addShawarmaButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::addShawarma));
        completeButton->signal_clicked().connect(sigc::mem_fun(*this, &LinuxFormDialog::createNewOrder));
        /* Actions. */
        //Glib::RefPtr<Gtk::Action>::cast_dynamic(builder->get_object("action_quit"))-> signal_activate().connect(sigc::mem_fun(*this, &LinuxFormDialog::OnQuit));
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
        string tel = telTextField->get_text();
        string address = addressTextField->get_text();
        Client *client = Clients::getClient(name,address,tel);
        TypeDelivery typeDelivery = courierRadioButton->get_active() ? TypeDelivery::COURIER : TypeDelivery::DRONE;
        order = new Order(client, typeDelivery);
        auto text = (goodsList->get_buffer())->get_text();
        std::stringstream ss(text);
        std::string to;
        if (!text.empty())
        {
            while(std::getline(ss,to,'\n')){
                if(to == "Шаурма"){
                    order->addGood(new Shawarma("Шаурма",140,500));
                }
                else if(to == "Пицца"){
                    order->addGood(new Pizza(540,TypePizzaFactory::getTypePizza("Пицца 1","Маленькая",1)));
                }
            }
        }
        else{
            std::cout << "Ошибка при создании заказа" << std::endl;
        }
        OnQuit();
    }

    void addShawarma ()
    {
        GtkTextIter iter;
        auto buffer = goodsList->get_buffer();
        goodsList->set_editable(true);
        buffer->insert_interactive(buffer->get_iter_at_line(buffer->get_line_count()),"Шаурма\n", goodsList->get_editable());
        goodsList->set_editable(false);
    }

    void addPizza ()
    {
        GtkTextIter iter;
        auto buffer = goodsList->get_buffer();
        goodsList->set_editable(true);
        buffer->insert_interactive(buffer->get_iter_at_line(buffer->get_line_count()),"Пицца\n", goodsList->get_editable());
        goodsList->set_editable(false);
    }
};


#endif //PATTERNS_LINUXFORMDIALOG_H
