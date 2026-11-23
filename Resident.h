#ifndef RESIDENT_H
#define RESIDENT_H

class Resident
{

private:
    char *name;
    char *lastName;
    int phoneNumber;
    int apartmentNumber;
    int level;

    static char *copyString(const char *source);

public:
    Resident();
    Resident(const Resident &other);
    Resident(const char *name, const char *lastName, int phoneNumber, int apartmentNumber, int level);
    ~Resident();
    Resident &operator=(const Resident &other);

    const char *getName() const;
    const char *getLastName() const;
    int getPhoneNumber() const;
    int getApartmentNumber() const;
    int getLevel() const;
    void setName(const char *newName);
    void setLastName(const char *newLastName);
    void setPhoneNumber(int newPhoneNumber);
    void setApartmentNumber(int newApartmentNumber);
    void setLevel(int newLevel);
};

#endif
