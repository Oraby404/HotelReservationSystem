//
// Created by mohamed on 8/29/2021.
//

#include "header.h"
#include "HumanGuest.h"

HumanGuest::HumanGuest() = default;

HumanGuest::HumanGuest(char *userName, int id) : Guest(userName, id) {}

void HumanGuest::reserveRoom(vector<HotelRoom> &myRooms, int roomsCount, int nightsCount) {
    int count = 0;
    //count the number of available rooms
    for (auto it : myRooms) {
        if (it.isAvailable())
            count++;
    }

    if (count < roomsCount)
        cout << "Sorry, Only" << count << "Rooms Available.\nReservation Failed" << endl;
    else {
        count = 0;
        //reserve the rooms for this guest
        for (auto &myRoom : myRooms) {
            if (myRoom.isAvailable()) {
                //set it as unavailable in this period of nights
                myRoom.setAvailable(false);
                myRoom.setNights(nightsCount);
                //add the pointer to the list of pointers in guest
                reservedRooms.push_back(&myRoom);
                count++;
            }
            if (count == roomsCount)
                break;
        }
        //add the cost
        cost += 500 * nightsCount * roomsCount;
        cout << "\nTotal Cost : " << cost << "$\n" << endl;
    }
}

void HumanGuest::extendReservation(int nightsCount) {
    //make sure the guest have a reservation
    if (!reservedRooms.empty()) {
        for (auto &myRoom : reservedRooms) {
            //add the extra nights in each room
            myRoom->setNights(myRoom->getNights() + nightsCount);
            cost += (500 * nightsCount);
        }
        cout << "\nTotal Cost : " << cost << "$\n" << endl;
    }
}

void HumanGuest::spaService() {
    cout << "\nAdded Spa Service";
    cost += 100;
    cout << "\nTotal Cost : " << cost << "$\n" << endl;
}

void HumanGuest::dryCleaningService() {
    cout << "\nAdded Dry Cleaning Service";
    cost += 70;
    cout << "\nTotal Cost : " << cost << "$\n" << endl;
}



