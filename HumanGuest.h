//
// Created by mohamed on 8/29/2021.
//

#ifndef C___TRIAL_HUMANGUEST_H
#define C___TRIAL_HUMANGUEST_H

#include "Guest.h"
#include "HotelRoom.h"

class HumanGuest : public Guest {

public:
    HumanGuest();

    HumanGuest(char *userName, int id);

public:
    void reserveRoom(vector<HotelRoom> &myRooms, int roomsCount, int nightsCount) override;

    void extendReservation(int nightsCount) override;

    void spaService() override;

    void dryCleaningService() override;
};


#endif //C___TRIAL_HUMANGUEST_H
