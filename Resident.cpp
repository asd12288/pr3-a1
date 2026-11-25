#include "Resident.h"
#include <cstring>
using namespace std;

char *Resident::copyString(const char *source)
{
    char *copy = new char[strlen(source) + 1];
    strcpy(copy, source);
    return copy;
}

Resident::Resident()
    : name(new char[1]), lastName(new char[1]), phoneNumber(0), apartmentNumber(0), level(0)
{

    *name = '\0';
    *lastName = '\0';
}

Resident::Resident(const char *name, const char *lastName, int phoneNumber, int apartmentNumber, int level)
    : name(copyString(name)),
      lastName(copyString(lastName)),
      phoneNumber(phoneNumber),
      apartmentNumber(apartmentNumber),
      level(level)
{
}

Resident::Resident(const Resident &other)
    : name(copyString(other.name)), lastName(copyString(other.lastName)),
      phoneNumber(other.phoneNumber), apartmentNumber(other.apartmentNumber),
      level(other.level) {}

Resident &Resident::operator=(const Resident &other)
{
    if (this == &other)
    {
        return *this;
    }

    char *newName = copyString(other.name);
    char *newLastName = copyString(other.lastName);
    delete[] name;
    delete[] lastName;
    name = newName;
    lastName = newLastName;
    phoneNumber = other.phoneNumber;
    apartmentNumber = other.apartmentNumber;
    level = other.level;
    return *this;
}

Resident::~Resident()
{
    delete[] name;
    delete[] lastName;
}
int Resident::getApartmentNumber() const
{
    return apartmentNumber;
}
int Resident::getLevel() const
{
    return level;
}
int Resident::getPhoneNumber() const
{
    return phoneNumber;
}
const char *Resident::getName() const
{
    return name;
}
const char *Resident::getLastName() const
{
    return lastName;
}

void Resident::setName(const char *newName)
{
    char *copy = copyString(newName);
    delete[] name;
    name = copy;
}
void Resident::setLastName(const char *newLastName)
{
    char *copy = copyString(newLastName);
    delete[] lastName;
    lastName = copy;
}
void Resident::setPhoneNumber(int newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}
void Resident::setApartmentNumber(int newApartmentNumber)
{
    apartmentNumber = newApartmentNumber;
}
void Resident::setLevel(int newLevel)
{
    level = newLevel;
}
