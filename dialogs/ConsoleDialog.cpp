//
// Created by artem on 26.11.2019.
//

#include "ConsoleDialog.h"

IOrder *ConsoleDialog::showDialog() {
    std::string name =  ask("Введите имя : ");
    std::string address =  ask("Введите адрес доставки : ");
    std::string tel =  ask("Введите номер телефона : ");
    std::string email =  ask("Введите email : ");
    TypeDelivery typeDelivery = TypeDelivery::NONE;
    do{
        std::cout << "Тип доставки:\n\t1) Курьер\n\t2) Дрон\nВведите 1 или 2: ";
        int answ;
        std::cin >> answ;
        switch(answ){
            case 1:
                typeDelivery = TypeDelivery::COURIER;
                break;
            case 2:
                typeDelivery = TypeDelivery::DRONE;
                break;
            default:
                typeDelivery = TypeDelivery::NONE;
                std::cout << "Некорректный ввод. Повторите ввод" << std::endl;
        }
    }while(typeDelivery == TypeDelivery::NONE);
    //order = new Order(Clients::getClient(name,address,tel,email),typeDelivery);
    orderBuilder.setClient(Clients::getClient(name,address,tel,email));
    orderBuilder.setTypeDelivery(typeDelivery);
    askAboutGoods();
    //return order;
    return orderBuilder.build();
}

std::string ConsoleDialog::ask(std::string question){
    std::string answer;
    do{
        std::cout << question;
        std::cin >> answer;
        if(answer.empty())
            std::cout << "Некорректный ввод. Повторите ввод" << std::endl;
    }while(answer.empty());
    return answer;
}

void ConsoleDialog::askAboutGoods(){
    bool exit = false;
    do{
        std::cout << "Тип продукта:\n\t1) Пицца\n\t2) Шаурма\n\t3) Завершить оформление заказа\nВведите 1 или 2 или 3: ";
        int answ;
        std::cin >> answ;
        switch(answ){
            case 1:
                //order->addGood(new Pizza("Пицца",540,700));
                askAboutPizza();
                break;
            case 2:
                orderBuilder.addGood(new Shawarma("Шаурма",140,500));
                break;
            case 3:
                exit = true;
                break;
            default:
                std::cout << "Некорректный ввод. Повторите ввод" << std::endl;
        }
    }while(!exit);
}

void ConsoleDialog::askAboutPizza(){
    int answ1;
    do {
        std::cout << "Варианты:\n\t1) Пицца 1\n\t2) Пицца 2\n\t3) Назад\nВведите 1 или 2 или 3: ";
        std::cin >> answ1;
        switch (answ1) {
            case 1:
                if(askAboutTypeConcrPizza("Пицца 1"))
                    return;
                break;
            case 2:
                if(askAboutTypeConcrPizza("Пицца 2"))
                    return;
                break;
            case 3:
                return;
            default:
                std::cout << "Некорректный ввод. Повторите ввод" << std::endl;
        }
    }
    while(true);
}

bool ConsoleDialog::askAboutTypeConcrPizza(string namePizza){
    int answ1;
    do{
    std::cout << "Тип пиццы:\n\t1) Маленькая\n\t2) Большая\n\t3) Назад\nВведите 1 или 2 или 3: ";
    std::cin >> answ1;
        switch(answ1){
            case 1:
                //order->addGood(new Pizza(340,TypePizzaFactory::getTypePizza(namePizza, "Маленькая", 1)));
                orderBuilder.addGood(new Pizza(340,TypePizzaFactory::getTypePizza(namePizza, "Маленькая", 1)));
                return true;
            case 2:
                orderBuilder.addGood(new Pizza(340,TypePizzaFactory::getTypePizza(namePizza, "Большая", 1.5)));
                return true;
            case 3: return false;
            default:
                std::cout << "Некорректный ввод. Повторите ввод" << std::endl;
        }
    }
    while(true);
}