#ifndef BUILDING_H
#define BUILDING_H
#include "Resident.h"

class Building
{

private:
    Resident *residentArray;
    int size;

public:
    Building();

    Building(const Building& other);
    Building &operator=(const Building& other);

    ~Building();

    bool addResident(const Resident& resident);
    bool deleteResident(int index);
    Resident& getResident(int index);
    const Resident& getResident(int index) const;
    int getSize() const;
};

#endif
