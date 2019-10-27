cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(patterns main.cpp client/IOrder.h client/Status.cpp client/Status.h client/Client.cpp client/Client.h client/Order.cpp client/Order.h client/ProxyOrder.cpp client/ProxyOrder.h workers/Worker.cpp workers/Worker.h goods/Good.cpp goods/Good.h workers/Courier.cpp workers/Courier.h workers/Manager.cpp workers/Manager.h workers/Cook.cpp workers/Cook.h workers/Drone.cpp workers/Drone.h workers/IDeliver.h client/clientClasses.h)