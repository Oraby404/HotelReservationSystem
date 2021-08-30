//
// Created by mohamed on 8/29/2021.
//

#include "header.h"
#include "Guest.h"
#include "HumanGuest.h"
#include "MonsterGuest.h"

int main() {
    char name[100];
    int id;
    int newID = 500;
    int nightsCount;
    int roomsCount;
    int guestClass;

    //pointer to the current guest to serve
    Guest *guest;
    //pointer to current rooms avaliable for the guest
    vector<HotelRoom> *myRooms;
    //list of all guests
    vector<Guest *> myGuests;
    vector<HotelRoom> humanRooms(5, HotelRoom(Human, true));
    vector<HotelRoom> monsterRooms(15, HotelRoom(Monster, true));


    int option;
    bool found = false;

    while (1) {

        do {
            cout << "Choose an option :\n1)Log in\n2)Create new account\n3)Exit\nOption :";
            cin >> option;

            //main menu options
            switch (option) {
                //Log in
                case 1 :
                    cout << "\nEnter Your ID : ";
                    cin >> id;
                    found = false;
                    //linear search by id
                    for (auto it : myGuests)
                        if (id == it->getId()) {
                            found = true;
                            cout << "\nWelcome " << it->getUserName() << "!\n" << endl;
                            guest = it;
                            break;
                        }
                    //if the id is not found , display main menu again
                    if (!found) {
                        cout << "\nID not Found!\n" << endl;
                        option = 0;
                    }
                    break;

                    //Create Account
                case 2 :
                    cout << "\nEnter Your User Name :";
                    cin >> name;
                    cout << "\nEnter Your Class :\n1)Human\n2)Monster\nOption : ";
                    cin >> guestClass;

                    //Human
                    if (guestClass == Human) {
                        //assign the guest to the pointer (Polymorphism)
                        guest = new HumanGuest(name, ++newID);
                        cout << "\nYour ID is : " << guest->getId() << "\n" << endl;
                        //add the guest to the list of guests
                        myGuests.push_back(guest);
                        //assign the human rooms as the avaliable rooms
                        myRooms = &humanRooms;

                        //Monster
                    } else {
                        //assign the guest to the pointer (Polymorphism)
                        guest = new MonsterGuest(name, ++newID);
                        cout << "\nYour ID is : " << guest->getId() << "\n" << endl;
                        //add the guest to the list of guests
                        myGuests.push_back(guest);
                        //assign the monster rooms as the avaliable rooms
                        myRooms = &monsterRooms;
                    }
                    break;

                    //Exit
                case 3:
                    exit(0);
                    break;

                default:
                    cout << "\nInvalid Option!" << endl;
                    break;
            }
        } while (option > 3 || option < 1);


        //Avaliable services menu
        do {
            cout << "How Can We Serve You?\n1)New reservation\n2)Extend reservation";
            cout << "\n3)Additional services\n4)Cancel reservation\n5)Back To Main Menu\nOption :";
            cin >> option;

            switch (option) {
                //make new reservation
                case 1 :
                    cout << "\nEnter Number of Rooms :";
                    cin >> roomsCount;
                    if (roomsCount < 1) roomsCount = 1;
                    cout << "\nEnter Number of Nights :";
                    cin >> nightsCount;
                    if (nightsCount < 1) nightsCount = 1;
                    guest->reserveRoom(*myRooms, roomsCount, nightsCount);
                    break;
                    //extend nights
                case 2 :
                    cout << "\nEnter Number of Extra Nights :";
                    cin >> nightsCount;
                    if (nightsCount < 1) nightsCount = 1;
                    guest->extendReservation(nightsCount);
                    break;
                    //Additional services
                    //doesnt require a room reservation and can be made multiple times
                case 3 :
                    cout << "\nChoose Service :\n1)Spa\n2)Dry Cleaning\nOption :";
                    cin >> option;

                    if (option == 1)
                        guest->spaService();
                    else
                        guest->dryCleaningService();

                    break;
                    //Cancel reservation
                case 4 :
                    cout << "\nCancel All Reservations?\n1)Yes\n2)No\nOption :";
                    cin >> option;
                    if (option == 1) {
                        guest->setCost(0);
                        //free the reserved rooms
                        for (auto it : guest->getReservedRooms()) {
                            it->setAvailable(true);
                            it->setNights(0);
                        }
                        //free the guest's pointer to rooms
                        guest->getReservedRooms().clear();
                        cout << "\nAll Reservations Canceled.\n" << endl;
                    }
                    break;

                    //skip
                case 5:
                    break;

                default:
                    cout << "\nInvalid Option!" << endl;
                    break;
            }
        } while (option != 5);

        cout << "\n\n";
        system("cls");
        system("pause");
    }

    return 0;
}
