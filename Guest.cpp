//
// Created by mohamed on 8/29/2021.
//

#include "Guest.h"

Guest::Guest() = default;

Guest::Guest(char *userName, int id) : userName(userName), id(id) {}

char *Guest::getUserName() const {
    return userName;
}

int Guest::getId() const {
    return id;
}

int Guest::getCost() const {
    return cost;
}

void Guest::setCost(int myCost) {
    Guest::cost = myCost;
}

vector<HotelRoom *> &Guest::getReservedRooms() {
    return reservedRooms;
}

