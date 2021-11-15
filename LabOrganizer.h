#include <iostream>
#include <string>
#include "Cabinet.h"
using namespace std;

class LabOrganizer{
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    //void findChemical(int id);
    void removeChemical(int id);
    void locationFind(string place);
    bool checkSurrounding(int row, int wcolumn,Cabinet* point);
    bool checkSurrounding2(int wrow, int wcolumn,Cabinet*& point);
    void findClosest(int row, int wcolumn,int cabinetIndex);
    string reverseLocation(int row,int column);
    int getSize();

private:
    string alphabet [9];
    int changer[2];
    int size;
    Cabinet** cabinets;
    Cabinet* adder;
};