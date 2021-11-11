using namespace std;
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Chemical.h"

class Cabinet{
private:
    int rows;
    int id_cabinet;
    int columns;
    Chemical*** chemicals;
    string alphabet [9];
public:   
    Cabinet(int id = 0, int rows = 0, int columns = 0);
    ~Cabinet();
    string getTypeChem(int row,int column);
    void contents();
    void placeChemical(int row, int column, string chemType, int chemID);
    void removeChenical(int row, int column);
    void findChemical(int id);
    int getId();
    string getTypeChem2(int row, int column);
    int getRow();
    int getColumn();
    int plusCount();

};