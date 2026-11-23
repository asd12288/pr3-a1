#ifndef BUILDING_H
#define BUILDING_H
#include "resident.h"

namespace Building
{

    class Building
    {

    private:
        Resident::Resident *residentArray;
        int size;

    public:
        Building();
        Building(const Building &other);

        ~Building();

        bool addResident(int index);
        bool deleteResident(int index);
        Resident::Resident *getResident(int index);
        Resident::Resident *getResident(int index) const;
        int getSize() const;
    };

}

#endif