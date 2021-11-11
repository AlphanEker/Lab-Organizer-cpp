#include <iostream>
#include <string.h>
#include "LabOrganizer.h"
using namespace std;

LabOrganizer::LabOrganizer(){
    this->size = 0;
    this->cabinets = NULL;
    this->alphabet[0] = "A";
    this->alphabet[1] = "B";
    this->alphabet[2] = "C";
    this->alphabet[3] = "D";
    this->alphabet[4] = "E";
    this->alphabet[5] = "F";
    this->alphabet[6] = "G";
    this->alphabet[7] = "H";
    this->alphabet[8] = "I";
}

void LabOrganizer::addCabinet(int id, int rows, int columns){
    if(size == 0){
        if(id >0 && rows > 0 && columns > 0){
            cabinets = new Cabinet*[1];
            cabinets[0] = new Cabinet(id,rows,columns);
            size++;
        }
    }
    else if (size > 0){
        if(id >0 && rows > 0 && columns > 0){
            Cabinet** temp = new Cabinet*[size];
            temp = cabinets;
            cabinets = new Cabinet*[size+1];
            for (int i = 0; i < size; i++)
            {
                cabinets[i] = temp[i];
            }
            cabinets[size] = new Cabinet(id,rows,columns);
            size++;
        }
    }
    
}

void LabOrganizer::removeCabinet(int id){
    int inRem;
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        if(cabinets[i]->getId() == id){
            inRem = i;
            check = true;
        }
    }
    if (check)
    {
        Cabinet** temp = new Cabinet*[size];

        for (int i = 0; i < size; i++){
            temp[i] = cabinets[i];
        }
        
        cabinets = new Cabinet*[size-1];

        for (int i = 0; i < inRem; i++)
        {
            cabinets[i] = temp[i];
        }

        for (int i = inRem+1; i < size; i++)
        {
            cabinets[i-1] = temp[i];
        }
        
        
        for (int i = 0; i < size; i++)
        {
            delete temp[i];
        }
        delete[] temp;
        temp = NULL;
        size--;
        
    }
}

void LabOrganizer::locationFind(string place){
    string firstPlace;
    bool check1 = false;
    bool check2 = false;
    for (int i = 0; i < 9; i++)
    {
        if(place.substr(0,1) == alphabet[i]){
            this->changer[0] = i;
            check1 = true;
        }
    }
    if (0 < stoi(place.substr(1,1)) && stoi(place.substr(1,1))  <=9)
    {
        check2 = true;
        this->changer[1] = stoi(place.substr(1,1))-1;
    }
    
    
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID){
    Cabinet* point;
    bool check1 = false;
    bool check2 = true;
    bool check3 = true;
    string* err = NULL;
    for (int i = 0; i < size; i++)
    {
        if (cabinets[i]->getId() == cabinetId)
        {
            point = cabinets[i];
            locationFind(location);
            check1 = true;
        }
        else{
            cout<<"cabinet not found!"<<endl;
        }
        
    }
    if(check1){
        if(chemType == "combustive"){
            check2 = checkSurrounding(point->getRow(),point->getColumn(),point);
            if(!check2){
                string errreturn;
                int sizeofW;
                err = findClosest(changer[0],changer[1],point,sizeofW);
                delete[] err;
                err = new string[sizeofW];
                err = findClosest(changer[0],changer[1],point,sizeofW);
                errreturn = "COMBUSTIVE NEARBY CLOSEST IS : ";
                cout<<sizeofW<<endl;
                for (int i = 0; i < sizeofW; i++)
                {
                    errreturn = errreturn + err[i]+ ", ";
                }
                cout<<errreturn<<endl;
                check2 = false;
                delete[] err;
            }
            
        }
    }
    if(check1){
        if(point->getTypeChem(changer[0],changer[1]) != "+"){
            check3 = false;

        }
    }
    if(check1 && check2 && check3){
        point->placeChemical(changer[0],changer[1],chemType,chemID);

    }
    
}
void LabOrganizer::listCabinets(){
    string a;
    cout<<"list of all cabinets:"<<endl;
    for (int i = 0; i < size; i++)
    {
        a = a + "ID: "+to_string(cabinets[i]->getId()) + ", ";
        a = a + "DIM: " + to_string(cabinets[i]->getRow()) + "x" + to_string(cabinets[i]->getColumn()) +", ";
        a = a+ "Number of empty slots: " + to_string(cabinets[i]->plusCount())+ "\n";
    }
    cout<<a;
    
}
bool LabOrganizer::checkSurrounding(int row, int wcolumn,Cabinet*& point){
    bool left,right,up,down = true;
    bool cleft,cright,cup,cdown = false;
    if(changer[0]-1 > 0){
        if(point->getTypeChem2(changer[0]-1,changer[1]) == "c"){
            up = false;
            return false;
        }
        cup = true;              
        
    }
    if(changer[0]+1 < point->getRow()){
        if(point->getTypeChem2(changer[0]+1,changer[1]) == "c"){
            down = false;
            return false;
        }
        cdown = true;
        
        
    }
    if(changer[1]-1 > 0){
        if(point->getTypeChem2(changer[0],changer[1]-1) == "c"){
            left = false;
            return false;
        }
        cleft = true;
        
    }
    if(changer[1]+1 < point->getColumn()){
        if(point->getTypeChem2(changer[0],changer[1]+1) == "c"){
            right = false;
            cout<<"entered right";
            return false;
        }
        cright = true;
        
    }
    if(cright && cup){
        if(point->getTypeChem(changer[0]-1,changer[1]+1) == "c"){
            return false;
        }
        
    }
    if(cright && cdown){
        if(point->getTypeChem2(changer[0]+1,changer[1]+1) == "c"){
            right = false;
            return false;
        }
    }
    if(cleft && cup){
        if(point->getTypeChem2(changer[0]-1,changer[1]-1) == "c"){
            right = false;
            return false;
        }
    }
    if(cleft && cdown){
        if(point->getTypeChem2(changer[0]+1,changer[1]-1) == "c"){
            right = false;
            return false;
        }
    }
    return true;

}

string* LabOrganizer::findClosest(int wrow, int wcolumn,Cabinet*& point,int& sizeofW){
    int matrisRow = point->getRow();
    int matrisColumn = point->getColumn();
    int count1 = 0;
    int count2 = 0;
    string* arr1 = new string[matrisRow*matrisColumn];
    int* arr2 = new int[matrisRow*matrisColumn];
    int* arr3 = new int[matrisRow*matrisColumn];
    


    for (int i = 0; i < matrisColumn; i++)
    {
        for (int j = 0; j < matrisRow; j++)
        {
            if(checkSurrounding(i,j,point)){
                if(abs(i-wrow) != 0 && abs(j-wcolumn)!= 0){
                    arr1[count1] = reverseLocation(i,j);
                    if(abs(i-wrow) > abs(j-wcolumn)){
                        arr2[count1] = abs(i-wrow);
                        arr3[count1] = abs(i-wrow);
                    }
                    else if(abs(j-wcolumn) > abs(i-wrow)){
                        arr2[count1] = abs(j-wcolumn);
                        arr3[count1] = abs(j-wcolumn);
                    }
                    else if(abs(j-wcolumn) == abs(i-wrow)){
                        arr2[count1] = abs(j-wcolumn)-1;
                        arr3[count1] = abs(j-wcolumn)-1;
                    }
                    
                    count1++;
                }
            }
        }
        
    }
    int temp;
    for (int j = 0; j < count1; j++)
    {
        for (int i = 0; i < count1-1; i++)
        {
            if(arr3[i] > arr3[i+1]){
                temp = arr3[i+1];
                arr3[i+1] = arr3[i];
                arr3[i] = temp;
            }
        }
    }
    
    for (int i = 0; i < count1; i++)
    {
        if(arr2[i] == arr3[0]){
            count2++;
        }
    }

    string* returner = new string[count2];
    int last = 0;
    for (int i = 0; i < count1; i++)
    {
        if(arr2[i] == arr3[0]){
            returner[last] = arr1[i];
            last++;
        }
    }
    sizeofW = last;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    return returner;

}

string LabOrganizer::reverseLocation(int row,int column){
    string a = "";
    a = a + alphabet[row];
    a = a + to_string(column + 1);
    return a;
}
void LabOrganizer::cabinetContents(int id){
    int wantedIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if(cabinets[i]->getId() == id){
            wantedIndex = i;
        }
    }
    if (wantedIndex >= 0){
        cabinets[wantedIndex]->contents();
    }
    
}

