//
// Created by artem on 07.12.2019.
//


#include "CardPay.h"

#include <utility>

CardPay::CardPay(string numCard, string cardholder, string cvv, IOrder *order) : numCard(std::move(numCard)),
                                                                                                    cardholder(std::move(
                                                                                                            cardholder)),
                                                                                                    cvv(std::move(cvv)),
                                                                                                    order(order) {}

void CardPay::execute() {
    if(order == nullptr){
        Logger::getLogger()->message("Ошибка при оплате", Logger::ERR);
        return;
    }
    double sum = order->countPrice();
    cout.precision(2);
    std::cout << "Платим за заказ № "<< order->getNumber() << " с карты "<< numCard <<" . Сумма оплаты: " << sum << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "Оплачен заказ № "<< order->getNumber() << std::endl;
    order->setStatus(Status::PAID);
}

