#include "Building.h"
#include <cstring>
using namespace std;

Building::Building():residentArray(nullptr), size(0){
}

Building::Building(const Building& other):size(other.size){
    residentArray = new Resident[other.size];
    
    for(int i = 0; i< other.size; i++){
        residentArray[i] = other.residentArray[i];
    }
}
Building& Building::operator=(const Building& other){
    if(this == &other){
        return *this;
    }
    Resident* newArray = new Resident[other.size];
    
    for(int i = 0; i< other.size; i++){
        newArray[i] = other.residentArray[i];
    }
    delete[] residentArray;
    residentArray = newArray;
    size = other.size;
    return *this;
}

Building::~Building(){
    delete[] residentArray;
}

bool Building::addResident(const Resident& resident){
    Resident* newArray = new Resident[size + 1];
    for (int i =0; i<size; i++){
        newArray[i] = residentArray[i];
    }
    newArray[size] = resident;
    delete[] residentArray;
    residentArray = newArray;
    size++;
    return true;

}
bool Building::deleteResident(int index){
    if(index < 0 || index >= size){
        return false;
    }
    Resident* newArray = new Resident[size-1];
    int flag = 0;
    for (int i = 0; i< size; i++){
        if(i == index){
            flag = 1;
        }
        if(i != index){
            newArray[i - flag] = residentArray[i];
        }
    }
    delete[] residentArray;
    residentArray = newArray;
    size--;
    return true;

}
Resident& Building::getResident(int index){
    return residentArray[index];

}
const Resident& Building::getResident(int index) const{
    const Resident& currResident =  residentArray[index];
    return currResident;
}
int Building::getSize() const{
    return size;
}