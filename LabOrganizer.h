#include <iostream>
#include <string>
#include "Cabinet.h"
using namespace std;

class LabOrganizer{
public:
    LabOrganizer();
    //~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    //void findChemical(int id);
    //void removeChemical(int id);
    void locationFind(string place);
    bool checkSurrounding(int row, int wcolumn,Cabinet*& point);
    string* findClosest(int row, int wcolumn,Cabinet*& point,int& sizeofW);
    string reverseLocation(int row,int column);

private:
    string alphabet [9];
    int changer[2];
    int size;
    Cabinet** cabinets;
    Cabinet* adder;
};