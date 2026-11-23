#ifndef RESIDENT_H
#define RESIDENT_H

namespace Resident
{

    class Resident
    {

    private:
        char *name;
        char *lastName;
        int phoneNumber;
        int apartmentNumber;
        int level;

    public:
        Resident();
        Resident(const char *name, const char *lastName, int phoneNumber, int apartmentNumber, int lever);
        ~Resident();

        char *getName() const;
        char *getLastName() const;
        int getPhoneNumber() const;
        int getApartmentNumber() const;
        int getLevel() const;
        void setName(const char *newName);
        void setLastName(const char *lastName);
        void setPhoneNumber(int newPhoneNumber);
        void setApartmentNumber(int newApartmentNumber);
        void setLevel(int level);
    };
}

#endif