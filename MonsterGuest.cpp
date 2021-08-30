//
// Created by mohamed on 8/29/2021.
//

#include "header.h"
#include "MonsterGuest.h"

MonsterGuest::MonsterGuest() = default;

MonsterGuest::MonsterGuest(char *userName, int id) : Guest(userName, id) {}

void MonsterGuest::reserveRoom(vector<HotelRoom> &myRooms, int roomsCount, int nightsCount) {
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
        cost += 200 * nightsCount * roomsCount;
        cout << "\nTotal Cost : " << cost << "$\n" << endl;
    }

}

void MonsterGuest::extendReservation(int nightsCount) {
    //make sure the guest have a reservation
    if (!reservedRooms.empty()) {
        for (auto &myRoom : reservedRooms) {
            //add the extra nights in each room
            myRoom->setNights(myRoom->getNights() + nightsCount);
            cost += (200 * nightsCount);
        }
        cout << "\nTotal Cost : " << cost << "$\n" << endl;
    }
}


void MonsterGuest::spaService() {
    cout << "\nAdded Spa Service";
    cost += 50;
    cout << "\nTotal Cost : " << cost << "$\n" << endl;
}

void MonsterGuest::dryCleaningService() {
    cout << "\nAdded Dry Cleaning Service";
    cost += 30;
    cout << "\nTotal Cost : " << cost << "$\n" << endl;
}




