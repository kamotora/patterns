//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_SHAWARMADIALOG_H
#define PATTERNS_SHAWARMADIALOG_H

#include <gtkmm/window.h>
#include <gtkmm/textview.h>
#include <gtkmm/builder.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/main.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/listbox.h>
#include "../goods/Shawarma.h"
#include "../goods/Stock.h"
#include "../goods/SizeShawarmaFactory.h"
#include "../log/Logger.h"
#include "../client/IOrder.h"
#include "../goods/ShawarmaFactory.h"


class ShawarmaDialog : public Gtk::Window{
private:
    static ShawarmaDialog *shawarmaWindow;
    Gtk::ComboBoxText *shawarmasList;
    Gtk::ComboBoxText *ingredientsListShawarma, *sizesShawarmaList;
    Gtk::Button *addShawarmaButton, *backShawarmaButton,*addShawarmaIngredient;
    Gtk::Label *sumShawarma;
    Shawarma *shawarma = nullptr;
    static Gtk::Main app;
    IOrder *order;
public:
    static ShawarmaDialog* getInstance(){
        if(shawarmaWindow == nullptr)
            Gtk::Builder::create_from_file("/home/artem/patterns/dialogs/test.glade")->get_widget_derived("shawarmaWindow", shawarmaWindow);
        return shawarmaWindow;
    }

    void showWindow(){
        shawarma = nullptr;
        app.run(*shawarmaWindow);
        delete shawarmaWindow;
        shawarmaWindow = nullptr;
    }

    ShawarmaDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
            Gtk::Window(cobject)
    {
        /* Retrieve all widgets. */
        builder->get_widget("shawarmasList", shawarmasList);
        builder->get_widget("ingredientsListShawarma", ingredientsListShawarma);
        builder->get_widget("sizesShawarmaList", sizesShawarmaList);
        builder->get_widget("addShawarmaButto", addShawarmaButton);
        builder->get_widget("backShawarmaButton", backShawarmaButton);
        builder->get_widget("sumShawarma", sumShawarma);
        builder->get_widget("addShawarmaIngredient", addShawarmaIngredient);

        /* Connect signals. */
        addShawarmaButton->signal_clicked().connect(sigc::mem_fun(*this, &ShawarmaDialog::addShawarma));
        addShawarmaIngredient->signal_clicked().connect(sigc::mem_fun(*this, &ShawarmaDialog::addIngredient));
        backShawarmaButton->signal_clicked().connect(sigc::mem_fun(*this, &ShawarmaDialog::back));
        shawarmasList->signal_changed().connect(sigc::mem_fun(*this, &ShawarmaDialog::shawarmaChanged));
        sizesShawarmaList->signal_changed().connect(sigc::mem_fun(*this, &ShawarmaDialog::sizeShawarmaChanged));

        /* Actions. */
        //Glib::RefPtr<Gtk::Action>::cast_dynamic(builder->get_object("action_quit"))-> signal_activate().connect(sigc::mem_fun(*this, &LinuxFormDialog::OnQuit));
        for(auto ingred : Stock::getIngerdients()){
            ingredientsListShawarma->append(ingred->toString());
        }
        for(auto product: ShawarmaFactory::getAll()){
            shawarmasList->append(product->getName());
        }
        for(auto size: SizeShawarmaFactory::getAllTypes()){
            sizesShawarmaList->append(size->getNameSize());
        }
        sizesShawarmaList->set_active(0);
    }

    void addShawarma() {
        sizeShawarmaChanged();
        order->addGood(shawarma);
        order = nullptr;
        back();
    }

    void back() {
        OnQuit();
    }

    void addIngredient() {
        sizeShawarmaChanged();
        auto index = ingredientsListShawarma->get_active_row_number();
        if(index < 0){
            Logger::getLogger()->message("Ингредиент не выбран", Logger::DEBUG);
        }else{
            auto ingred = Stock::getIngerdients().at(index);
            shawarma->addIngredient(ingred);
            sumShawarma->set_text(to_string(shawarma->getSaleCost()));
        }
    }

    void shawarmaChanged(){
        auto num = shawarmasList->get_active_row_number();
        if(shawarma != nullptr)
            shawarma = nullptr;
        if(num < 0)
            Logger::getLogger()->message("Тип шаурмы не выбран", Logger::NOTIF);
        else{
            shawarma = dynamic_cast<Shawarma *>(ShawarmaFactory::getAll().at(num)->clone());
            sizeShawarmaChanged();
            sumShawarma->set_text(to_string(shawarma->getSaleCost()));
        }
    }

    void setOrder(IOrder *order){
        this->order = order;
    }
    void sizeShawarmaChanged(){
        if(shawarma != nullptr){
            auto num = sizesShawarmaList->get_active_row_number();
            if(num < 0)
                Logger::getLogger()->message("Размер шаурмы не выбран", Logger::NOTIF);
            else{
                auto size = SizeShawarmaFactory::getAllTypes().at(num);
                shawarma->setSizeShawarma(size);
                sumShawarma->set_text(to_string(shawarma->getSaleCost()));
            }
        }
    }
private:
    /** "quit" action handler. */
    void
    OnQuit()
    {
        hide();
    }
};


#endif //PATTERNS_SHAWARMADIALOG_H
