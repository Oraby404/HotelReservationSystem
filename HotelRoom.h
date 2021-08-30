//
// Created by mohamed on 8/29/2021.
//

#ifndef C___TRIAL_HOTELROOM_H
#define C___TRIAL_HOTELROOM_H

#include "header.h"

// can be an abstract class just like Guest in case we want
//different behaviors for each room
class HotelRoom {

public:
    HotelRoom(GuestClass guestClass, bool available);

private:
    //redundant , just to distinguish human rooms from monster rooms
    GuestClass guestClass;
    //mark if a room is available
    bool available;
    int nights{};

public:
    bool isAvailable() const;

    void setAvailable(bool availability);

    int getNights() const;

    void setNights(int myNights);
};


#endif //C___TRIAL_HOTELROOM_H
