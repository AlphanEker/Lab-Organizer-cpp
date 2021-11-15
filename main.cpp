#include <iostream>
#include <stdlib.h>
#include "LabOrganizer.h"
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    LabOrganizer L;
    L.listCabinets();
    // Testing add cabinet
    cout << "Testing add cabinet" << endl;
    cout << endl;
    L.addCabinet(101, 3, 4);
    L.addCabinet(102, 5, 3);
    L.addCabinet(103, 8, 8);
    cout << endl;
    L.addCabinet(103, 3, 3);
    L.addCabinet(104, 9, 19);
    L.addCabinet(201, 9, 9);
    cout << endl;
    L.addCabinet(203, 9, 3);
    L.addCabinet(205, 4, 4);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing remove cabinet
    cout << endl;
    cout << "Testing remove cabinet" << endl;
    cout << endl;
    L.removeCabinet(452);
    L.removeCabinet(101);
    L.removeCabinet(205);
    cout << endl;
    L.removeCabinet(203);
    L.removeCabinet(347);
    L.removeCabinet(201);
    cout << endl;
    L.addCabinet(101, 7, 7);
    cout << endl;
    L.listCabinets();
    cout << endl;
    // Testing place Chemical
    cout << endl;
    cout << "Testing place chemical" << endl;
    cout << endl;
    L.placeChemical( 101, "C1", "combustive", 200);
    L.placeChemical( 101, "C1", "retardant", 139);
    L.placeChemical( 101, "D3", "retardant", 139);
    cout << endl;
    L.placeChemical( 101, "E3", "combustive", 188);
    L.placeChemical( 101, "D2", "combustive", 888);
    L.placeChemical( 101, "E1", "combustive", 888);
    L.placeChemical( 102, "A2","combustive", 188);
    L.cabinetContents(101);
    L.removeChemical(139);
    L.removeChemical(189);
    L.removeChemical(200);
    L.cabinetContents(101);
    return 0;
}
