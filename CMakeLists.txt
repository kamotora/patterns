cmake_minimum_required(VERSION 3.15)
project(patterns)
set(CMAKE_CXX_STANDARD 17)
FIND_PACKAGE(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-2.54)
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
link_directories(
        ${GTKMM_LIBRARY_DIRS}  )

include_directories(
        ${GTKMM_INCLUDE_DIRS}  )

add_executable(patterns main.cpp client/IOrder.h client/Status.cpp client/Status.h client/Client.cpp client/Client.h client/Order.cpp client/Order.h client/ProxyOrder.cpp client/ProxyOrder.h workers/Worker.cpp workers/Worker.h goods/Product.cpp goods/Product.h workers/Courier.cpp workers/Courier.h workers/Manager.cpp workers/Manager.h workers/cook/Cook.cpp workers/cook/Cook.h workers/Drone.cpp workers/Drone.h workers/IDeliver.h client/TypeDelivery.h workers/Delivers.cpp workers/Delivers.h notifications/INotifier.cpp notifications/INotifier.h notifications/NotifDecorator.cpp notifications/NotifDecorator.h notifications/EmailNotif.cpp notifications/EmailNotif.h notifications/TelNotif.cpp notifications/TelNotif.h notifications/TelegramNotif.cpp notifications/TelegramNotif.h notifications/NotifierAdapter.cpp notifications/NotifierAdapter.h goods/CookingGood.cpp goods/CookingGood.h goods/Ingredient.cpp goods/Ingredient.h goods/Iterator.cpp goods/Iterator.h goods/ProductIterator.cpp goods/ProductIterator.h workers/ICaller.cpp workers/ICaller.h workers/Caller.cpp workers/Caller.h dialogs/IDialog.cpp dialogs/IDialog.h dialogs/LinuxFormDialog.cpp dialogs/LinuxFormDialog.h dialogs/ConsoleDialog.cpp dialogs/ConsoleDialog.h dialogs/CreatorOrder.cpp dialogs/CreatorOrder.h goods/Pizza.cpp goods/Pizza.h goods/Shawarma.cpp goods/Shawarma.h goods/TypePizza.cpp goods/TypePizza.h goods/TypePizzaFactory.cpp goods/TypePizzaFactory.h client/Clients.cpp client/Clients.h client/OrderBuilder.cpp client/OrderBuilder.h  goods/ICloneable.cpp goods/ICloneable.h workers/cook/IState.h workers/cook/FreeCookState.h workers/cook/BusyCookState.cpp workers/cook/BusyCookState.h workers/cook/FreeCookState.cpp client/IObservable.cpp client/IObservable.h client/IObserver.cpp client/IObserver.h client/ClientCareTaker.cpp client/ClientCareTaker.h client/ClientSnap.cpp client/ClientSnap.h client/commands/ICommand.cpp client/commands/ICommand.h client/commands/CardPay.cpp client/commands/CardPay.h client/commands/WebmoneyPay.cpp client/commands/WebmoneyPay.h workers/PrepareWorkersVisitor.cpp workers/PrepareWorkersVisitor.h workers/IVisitorElement.cpp workers/IVisitorElement.h workers/IVisitor.cpp workers/IVisitor.h log/Logger.cpp log/Logger.h log/ConsoleLogger.cpp log/ConsoleLogger.h log/EmailLogger.cpp log/EmailLogger.h log/SmsLogger.cpp log/SmsLogger.h goods/sort/IStrategy.cpp goods/sort/IStrategy.h goods/sort/BubbleSort.cpp goods/sort/BubbleSort.h goods/sort/InsertionSort.cpp goods/sort/InsertionSort.h)
find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${GTKMM_LIBRARIES})