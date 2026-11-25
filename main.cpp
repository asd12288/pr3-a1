#include <iostream>
#include <string>
#include "Resident.h"
#include "Building.h"

using namespace std;

const int BUILDING_COUNT = 2;

// Building ids in the input are 1 and 2
bool isValidBuildingId(int id)
{
    return id >= 1 && id <= BUILDING_COUNT;
}

bool isValidIndex(const Building &building, int index)
{
    return index >= 0 && index < building.getSize();
}

void printResident(int index, const Resident &resident)
{
    cout << index << " | " << resident.getName() << " | " << resident.getLastName()
         << " | " << resident.getPhoneNumber() << " | " << resident.getApartmentNumber()
         << " | " << resident.getLevel() << endl;
}

void printBuilding(int id, const Building &building)
{
    cout << "BUILDING " << id << " " << building.getSize() << endl;
    for (int i = 0; i < building.getSize(); i++)
    {
        printResident(i, building.getResident(i));
    }
}

// Command 1: b name lastName phone apartment level
void addCommand(Building *buildings[])
{
    int id, phone, apartment, level;
    string name, lastName;
    if (!(cin >> id >> name >> lastName >> phone >> apartment >> level))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    Resident resident(name.c_str(), lastName.c_str(), phone, apartment, level);
    buildings[id - 1]->addResident(resident);
    cout << "OK" << endl;
}

// Command 2: b index
void deleteCommand(Building *buildings[])
{
    int id, index;
    if (!(cin >> id >> index))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    if (buildings[id - 1]->deleteResident(index))
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "INVALID_INDEX" << endl;
    }
}

// Command 3: b
void printCommand(Building *buildings[])
{
    int id;
    if (!(cin >> id))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    printBuilding(id, *buildings[id - 1]);
}

// Command 4: b index name lastName phone apartment level
void updateCommand(Building *buildings[])
{
    int id, index, phone, apartment, level;
    string name, lastName;
    if (!(cin >> id >> index >> name >> lastName >> phone >> apartment >> level))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    Building &building = *buildings[id - 1];
    if (!isValidIndex(building, index))
    {
        cout << "INVALID_INDEX" << endl;
        return;
    }
    Resident &resident = building.getResident(index);
    resident.setName(name.c_str());
    resident.setLastName(lastName.c_str());
    resident.setPhoneNumber(phone);
    resident.setApartmentNumber(apartment);
    resident.setLevel(level);
    cout << "OK" << endl;
}

// Command 5: destination source - replace destination with a copy-constructed building
void copyBuildingCommand(Building *buildings[])
{
    int destination, source;
    if (!(cin >> destination >> source))
    {
        return;
    }
    if (!isValidBuildingId(destination) || !isValidBuildingId(source))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    if (destination == source)
    {
        cout << "SAME_BUILDING" << endl;
        return;
    }
    Building *copy = new Building(*buildings[source - 1]);
    delete buildings[destination - 1];
    buildings[destination - 1] = copy;
    cout << "OK" << endl;
}

// Command 6: destination source - assign source to destination (self-assignment allowed)
void assignBuildingCommand(Building *buildings[])
{
    int destination, source;
    if (!(cin >> destination >> source))
    {
        return;
    }
    if (!isValidBuildingId(destination) || !isValidBuildingId(source))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    *buildings[destination - 1] = *buildings[source - 1];
    cout << "OK" << endl;
}

// Commands 7 and 8: b index newName - copy a resident (copy constructor or
// assignment), rename the copy, and print the original and the copy
void copyResidentCommand(Building *buildings[], bool useAssignment)
{
    int id, index;
    string newName;
    if (!(cin >> id >> index >> newName))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    const Building &building = *buildings[id - 1];
    if (!isValidIndex(building, index))
    {
        cout << "INVALID_INDEX" << endl;
        return;
    }
    const Resident &original = building.getResident(index);
    if (useAssignment)
    {
        Resident copy;
        copy = original;
        copy.setName(newName.c_str());
        printResident(index, original);
        printResident(index, copy);
    }
    else
    {
        Resident copy(original);
        copy.setName(newName.c_str());
        printResident(index, original);
        printResident(index, copy);
    }
}

// Command 9: b - building self-assignment
void selfAssignBuildingCommand(Building *buildings[])
{
    int id;
    if (!(cin >> id))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    Building &building = *buildings[id - 1];
    Building &sameBuilding = building; // a second reference avoids -Wself-assign-overloaded
    building = sameBuilding;
    cout << "OK" << endl;
}

// Command 10: b index - resident self-assignment
void selfAssignResidentCommand(Building *buildings[])
{
    int id, index;
    if (!(cin >> id >> index))
    {
        return;
    }
    if (!isValidBuildingId(id))
    {
        cout << "INVALID_BUILDING" << endl;
        return;
    }
    Building &building = *buildings[id - 1];
    if (!isValidIndex(building, index))
    {
        cout << "INVALID_INDEX" << endl;
        return;
    }
    Resident &resident = building.getResident(index);
    Resident &sameResident = resident;
    resident = sameResident;
    cout << "OK" << endl;
}

int main()
{
    // Held as pointers so command 5 can replace a building using the copy constructor
    Building *buildings[BUILDING_COUNT];
    for (int i = 0; i < BUILDING_COUNT; i++)
    {
        buildings[i] = new Building();
    }

    int command;
    bool running = true;
    while (running && cin >> command)
    {
        switch (command)
        {
        case 0:
            running = false;
            break;
        case 1:
            addCommand(buildings);
            break;
        case 2:
            deleteCommand(buildings);
            break;
        case 3:
            printCommand(buildings);
            break;
        case 4:
            updateCommand(buildings);
            break;
        case 5:
            copyBuildingCommand(buildings);
            break;
        case 6:
            assignBuildingCommand(buildings);
            break;
        case 7:
            copyResidentCommand(buildings, false);
            break;
        case 8:
            copyResidentCommand(buildings, true);
            break;
        case 9:
            selfAssignBuildingCommand(buildings);
            break;
        case 10:
            selfAssignResidentCommand(buildings);
            break;
        default:
            cout << "INVALID_COMMAND" << endl;
            break;
        }
    }

    for (int i = 0; i < BUILDING_COUNT; i++)
    {
        delete buildings[i];
    }
    return 0;
}
