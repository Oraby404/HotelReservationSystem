//
// Created by mohamed on 8/29/2021.
//

#include "HotelRoom.h"

HotelRoom::HotelRoom(GuestClass guestClass, bool available) : guestClass(guestClass), available(available) {}

bool HotelRoom::isAvailable() const {
    return available;
}

void HotelRoom::setAvailable(bool availability) {
    HotelRoom::available = availability;
}

int HotelRoom::getNights() const {
    return nights;
}

void HotelRoom::setNights(int myNights) {
    HotelRoom::nights = myNights;
}
