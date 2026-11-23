#include "Resident.h"
#include <cstring>

char *Resident::copyString(const char *source)
{
    char *copy = new char[std::strlen(source) + 1];
    std::strcpy(copy, source);
    return copy;
}

int Resident::getPhoneNumber() const
{
    return phoneNumber;
}

Resident::Resident()
    : name(new char[1]{'\0'}),
      lastName(new char[1]{'\0'}),
      phoneNumber(0),
      apartmentNumber(0),
      level(0)
{
}

Resident::Resident(const char *name, const char *lastName, int phoneNumber, int apartmentNumber, int level)
    : name(copyString(name)),
      lastName(copyString(lastName)),
      phoneNumber(phoneNumber),
      apartmentNumber(apartmentNumber),
      level(level)
{
}
