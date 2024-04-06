#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for a hotel room defined
struct Room
{
    int roomNumber;
    bool occupied;
    string guestName;
    bool roomServiceRequested;
};

void displayMenu();
void addGuest(vector<Room> &rooms);
void removeGuest(vector<Room> &rooms);

int main()
{
    vector<Room> rooms;

    // Initializing rooms
    for (int i = 0; i < 10; ++i)
    {
        Room room;
        room.roomNumber = i + 1;
        room.occupied = false;
        room.roomServiceRequested = false;
        rooms.push_back(room);
    }

    int choice;
    do
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addGuest(rooms);
            break;
        case 2:
            removeGuest(rooms);
            break;
        case 3:
            // To be added later
            cout << "Room Service Request (will be added later).\n";
            break;
        case 4:
            // To be added later
            cout << "Display Room Occupancy (will be added later).\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void displayMenu()
{
    cout << "\n===== Josh's Hotel Management System Menu =====\n";
    cout << "1. Add Guest\n";
    cout << "2. Remove Guest\n";
    cout << "3. Room Service Request (will be added later)\n";
    cout << "4. Display Room Occupancy (will be added later)\n";
    cout << "0. Exit\n";
    cout << "\n";
    cout << "Enter your choice: ";
}

void addGuest(vector<Room> &rooms)
{
    int roomNum;
    cout << "Enter room number (1-10): ";
    cin >> roomNum;

    if (roomNum < 1 || roomNum > rooms.size())
    {
        cout << "Invalid room number.\n";
        return;
    }

    if (rooms[roomNum - 1].occupied)
    {
        cout << "Room " << roomNum << " is already occupied.\n";
    }
    else
    {
        cout << "Enter guest name: ";
        cin.ignore(); // Clear the input
        getline(cin, rooms[roomNum - 1].guestName);
        rooms[roomNum - 1].occupied = true;
        cout << "Guest added to room " << roomNum << ".\n";
    }
}

void removeGuest(vector<Room> &rooms)
{
    int roomNum;
    cout << "Enter room number (1-10): ";
    cin >> roomNum;

    if (roomNum < 1 || roomNum > rooms.size())
    {
        cout << "Invalid room number.\n";
        return;
    }

    if (rooms[roomNum - 1].occupied)
    {
        rooms[roomNum - 1].occupied = false;
        rooms[roomNum - 1].guestName = "";
        rooms[roomNum - 1].roomServiceRequested = false; // Reset room service request
        cout << "Guest removed from room " << roomNum << ".\n";
    }
    else
    {
        cout << "Room " << roomNum << " is already empty.\n";
    }
}