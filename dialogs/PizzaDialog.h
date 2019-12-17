//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_PIZZADIALOG_H
#define PATTERNS_PIZZADIALOG_H


#include <gtkmm/window.h>
#include <gtkmm/textview.h>
#include <gtkmm/builder.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/main.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/listbox.h>
#include "../goods/Pizza.h"
#include "../goods/Stock.h"
#include "../goods/TypePizzaFactory.h"
#include "../log/Logger.h"
#include "../client/IOrder.h"
#include "MyMessageDialog.h"

class PizzaDialog : public Gtk::Window {
private:
    static PizzaDialog *pizzaWindow;
    Gtk::ComboBoxText *pizzasTypesList;
    Gtk::ComboBoxText *ingredientsListPizza;
    Gtk::Button *addPizzaButton, *backPizzaButton,*AddPizzaIngredient;
    Gtk::Label *sumPizza;
    Pizza *pizza;
    static Gtk::Main app;
    IOrder *order;
public:
    static PizzaDialog* getInstance(){
        if(pizzaWindow == nullptr)
            Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade")->get_widget_derived("pizzaWindow", pizzaWindow);
        return pizzaWindow;
    }

    void show(){
        pizza = nullptr;
        app.run(*pizzaWindow);
        delete pizzaWindow;
        pizzaWindow = nullptr;
    }

    PizzaDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::Window(cobject)
    {
        /* Retrieve all widgets. */
        builder->get_widget("pizzasTypesList", pizzasTypesList);
        builder->get_widget("ingredientsListPizza", ingredientsListPizza);
        builder->get_widget("addPizzaButto", addPizzaButton);
        builder->get_widget("backPizzaButton", backPizzaButton);
        builder->get_widget("sumPizza", sumPizza);
        builder->get_widget("AddPizzaIngredient", AddPizzaIngredient);

        /* Connect signals. */
        addPizzaButton->signal_clicked().connect(sigc::mem_fun(*this, &PizzaDialog::addPizza));
        AddPizzaIngredient->signal_clicked().connect(sigc::mem_fun(*this, &PizzaDialog::AddIngredient));
        backPizzaButton->signal_clicked().connect(sigc::mem_fun(*this, &PizzaDialog::back));
        pizzasTypesList->signal_changed().connect(sigc::mem_fun(*this, &PizzaDialog::typePizzaChanged));
                /* Actions. */
                //Glib::RefPtr<Gtk::Action>::cast_dynamic(builder->get_object("action_quit"))-> signal_activate().connect(sigc::mem_fun(*this, &LinuxFormDialog::OnQuit));
        for(auto ingred : Stock::getIngerdients()){
            ingredientsListPizza->append(ingred->toString());
        }
        for(auto type: TypePizzaFactory::getAllTypes()){
            pizzasTypesList->append(type->getNamePizza() + " " + type->getNameType());
        }
    }

    void addPizza() {
        if(pizza == nullptr){
            typePizzaChanged();
            if(pizza == nullptr){
                new MyMessageDialog("Выбраны не все параметры.");
                return;
            }
        }
        order->addGood(pizza);
        order = nullptr;
        back();
    }

    void back() {
        OnQuit();
    }

    void AddIngredient() {
        auto index = ingredientsListPizza->get_active_row_number();
        if(index < 0){
            Logger::getLogger()->message("Ингредиент не выбран", Logger::DEBUG);
        }else{
            auto ingred = Stock::getIngerdients().at(index);
            pizza->addIngredient(ingred);
            sumPizza->set_text(to_string(pizza->getSaleCost()));
        }
    }

    void typePizzaChanged(){
        auto num = pizzasTypesList->get_active_row_number();
        if(pizza != nullptr)
            delete pizza;
        if(num < 0)
            Logger::getLogger()->message("Тип пиццы не выбран", Logger::NOTIF);
        else{
            pizza = new Pizza(0,TypePizzaFactory::getAllTypes().at(num));
            sumPizza->set_text(to_string(pizza->getSaleCost()));
        }
    }

    void setOrder(IOrder *order){
        this->order = order;
    }
private:
    /** "quit" action handler. */
    void
    OnQuit()
    {
        hide();
    }
};


#endif //PATTERNS_PIZZADIALOG_H
