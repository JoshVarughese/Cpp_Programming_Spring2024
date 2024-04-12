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
void requestRoomService(vector<Room> &rooms);
void displayOccupancy(const vector<Room> &rooms);

int main()
{
    vector<Room> rooms;

    // Initialize rooms
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
            requestRoomService(rooms);
            break;
        case 4:
            displayOccupancy(rooms);
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
    cout << "3. Request Room Service\n";
    cout << "4. Display Room Occupancy\n";
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
        rooms[roomNum - 1].roomServiceRequested = false; // Initialize room service request flag to false
        cout << "Guest added to room " << roomNum << ".\n";
    }
}

void removeGuest(vector<Room> &rooms)
{
    int roomNum;
    cout << "Enter room number: ";
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

void requestRoomService(vector<Room> &rooms)
{
    int roomNum;
    cout << "Enter room number: ";
    cin >> roomNum;

    if (roomNum < 1 || roomNum > rooms.size())
    {
        cout << "Invalid room number.\n";
        return;
    }

    if (rooms[roomNum - 1].occupied)
    {
        rooms[roomNum - 1].roomServiceRequested = true;
        cout << "Room service requested for room " << roomNum << ".\n";
    }
    else
    {
        cout << "Room " << roomNum << " is empty. No room service can be requested.\n";
    }
}

void displayOccupancy(const vector<Room> &rooms)
{
    cout << "===== Room Occupancy =====\n";
    for (const auto &room : rooms)
    {
        cout << "Room " << room.roomNumber << ": ";
        if (room.occupied)
        {
            cout << "Occupied by " << room.guestName;
            if (room.roomServiceRequested)
            {
                cout << " (Room Service Requested)";
            }
            cout << endl;
        }
        else
        {
            cout << "Empty\n";
        }
    }
}
