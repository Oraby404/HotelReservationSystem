//
// Created by mohamed on 8/29/2021.
//

#ifndef C___TRIAL_GUEST_H
#define C___TRIAL_GUEST_H

#include "header.h"
#include "HotelRoom.h"

// abstract class to be inherited by different types of guests
class Guest {

//constructors
public:
    Guest();

    Guest(char *userName, int id);

protected:
    char *userName{};
    int id{};
    int cost{};
    //pointer to current rooms reserved for this guest
    vector<HotelRoom *> reservedRooms;

public:
    virtual void reserveRoom(vector<HotelRoom> &myRooms, int roomsCount, int nightsCount) = 0;

    virtual void extendReservation(int nightsCount) = 0;

    virtual void spaService() = 0;

    vector<HotelRoom *> &getReservedRooms();

    virtual void dryCleaningService() = 0;

    char *getUserName() const;

    int getId() const;

    int getCost() const;

    void setCost(int myCost);

};


#endif //C___TRIAL_GUEST_H
