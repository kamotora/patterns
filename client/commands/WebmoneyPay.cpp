//
// Created by artem on 07.12.2019.
//

#include "WebmoneyPay.h"

#include <utility>

WebmoneyPay::WebmoneyPay(string from, string to, IOrder *order) : from(std::move(from)), to(std::move(to)), order(order) {}

void WebmoneyPay::execute() {
    if(order == nullptr){
        Logger::getLogger()->message("Ошибка при оплате", Logger::ERR);
        return;
    }
    double sum = order->countPrice();
    cout.precision(2);

    std::cout << "Платим за заказ № "<< order->getNumber() << " c Webmoney кошелька "<< from <<". Сумма оплаты: " << sum << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Оплачен заказ № "<< order->getNumber() << std::endl;
    order->setStatus(Status::PAID);
}
