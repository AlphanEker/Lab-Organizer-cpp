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
LabOrganizer::~LabOrganizer(){
    delete[] adder;
    for (int i = 0; i < size; i++)
    {
        delete cabinets[i];
    }
    delete[] cabinets;
    
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
        for (int i = 0; i < size; i++)
        {
            if(cabinets[i]->getId() == id){
                cout<<"ID already exists, cabinet couldnt be created!"<<endl;
                return;
            }
        }
        
        if(id >0 && rows > 0 && columns > 0){
            
            Cabinet** temp = new Cabinet*[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = new Cabinet();
                *temp[i] = *cabinets[i];
                
            }
            
            for (int i = 0; i < size; i++)
            {
                delete cabinets[i];
            }
            delete[] cabinets;
            

            cabinets = new Cabinet*[size+1];

            for (int i = 0; i < size; i++)
            {
                cabinets[i] = new Cabinet();
                *cabinets[i] = *temp[i];
            }
            
            cabinets[size] = new Cabinet(id,rows,columns);

            for (int i = 0; i < size; i++)
            {
                delete temp[i];
            }
            delete[] temp;
            size++;
        }
        
        
    }
    
}

void LabOrganizer::removeCabinet(int id){
    int inx;
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        if(cabinets[i]->getId() == id){
            inx = i;
            check = true;
        }
    }
    if(check){
        Cabinet** temp = new Cabinet*[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = new Cabinet();
            *temp[i] = *cabinets[i];
            
        }
        for (int i = 0; i < size; i++)
        {
            delete cabinets[i];
        }
        delete[] cabinets;

        cabinets = new Cabinet*[size-1];
        for (int i = 0; i < inx; i++)
        {
            cabinets[i] = new Cabinet();
            *cabinets[i] = *temp[i];
        }
        for (int i = inx; i < size-1; i++)
        {
            cabinets[i] = new Cabinet();
            *cabinets[i] = *temp[i+1];
        }
        for (int i = 0; i < size; i++)
        {
            delete temp[i];
        }
        delete[] temp;
        size--;
    
        
    }
    else{
        cout<<id<<" Cabinet Not Found!"<<endl;
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
    int inx;
    int row;
    int column;
    bool check1 = false;
    bool check2 = true;
    bool check3 = true;

    for (int i = 0; i < size; i++)
    {
        if(cabinets[i]->getId() == cabinetId){
            inx = i;
            check1 = true;
            for (int i = 0; i < 9; i++)
            {
                if(alphabet[i] == location.substr(0,1)){
                    row = i;
                }

            }
            column = stoi(location.substr(1,1))-1;
        }
    }
   
    
    if(check1){
        for (int i = 0; i < size; i++)
        {
            if(cabinets[i]->checkId(chemID)){
                cout<<"Chemical With ID"<<chemID<<" Already Exists in Cabinet: "<<cabinets[i]->getId()<<endl;
                return;
            }
        }
        if(cabinets[inx]->getRow() > row && row>-1 && cabinets[inx]->getColumn()> column && column > -1 ){
            if(cabinets[inx]->getTypeChem(row,column) == "+"){
                if(chemType == "combustive"){
                    if(checkSurrounding(row,column,cabinets[inx])){
                        cabinets[inx]->placeChemical(row,column,chemType,chemID);
                    }
                    else{
                        cout<<"Can not place chemical due to combustive chemicals closesency here are the closest available spots :"<<endl;
                        findClosest(row,column,inx);
                    }
                }
                else if (chemType == "retardant")
                {
                    cabinets[inx]->placeChemical(row,column,chemType,chemID);
                }
                else{
                    cout<<"not readable chemical type"<<endl;
                }
                
            }
            else{
                cout<<"location unavailable, chemical in place"<<endl;
            }
        }
        else{
            cout<<"location does not exsists"<<endl;
        }
    }
    else{
        cout<<"cabinet does not exsists"<<endl;
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

void LabOrganizer::findClosest(int row, int column,int cabinetIndex){
    int cabinetRow = cabinets[cabinetIndex]->getRow();
    int cabinetColumn = cabinets[cabinetIndex]->getColumn();
    int count = 0;
    int rr;
    int cc;
    int smallest;


    for (int l = 0; l < cabinetRow; l++)
    {
        for (int j = 0; j < cabinetColumn; j++)
        {
            if(l != row || j != column){
                cout<<"";
                if(checkSurrounding(l,j,cabinets[cabinetIndex]) && cabinets[cabinetIndex]->getTypeChem(l,j) == "+"){
                    count++;
                }
            }
        }

    }    

    if(count == 0){
        cout<<"no available spots for you !"<<endl;
        return;
    }
    

    string* arr1 = new string[count];
    int* arr2 = new int[count];
    count = 0;
    
     for (int l = 0; l < cabinetRow; l++)
    {
        for (int j = 0; j < cabinetColumn; j++)
        {
            if(l != row || j != column){
                cout<<"";
                if(checkSurrounding(l,j,cabinets[cabinetIndex]) && cabinets[cabinetIndex]->getTypeChem(l,j) == "+"){
                    arr1[count] = reverseLocation(l,j);
                    count++;
                }
            }
        }

    }    


    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 9; j++)
            {
                if(alphabet[j] == arr1[i].substr(0,1)){
                    rr = j;
                }

            }

        cc = stoi(arr1[i].substr(1,1))-1;
        if(abs(rr-row)>=abs(cc-column)){
            arr2[i] = abs(rr-row);
        }
        if(abs(cc-column)>abs(rr-row)){
            arr2[i] = abs(cc-column);
        }
    }
    smallest = arr2[0];
    for (int i = 0; i < count; i++)
    {
        if(smallest>arr2[i]){
            smallest = arr2[i];
        }
    }
    for (int i = 0; i < count; i++)
    {
        if(arr2[i] == smallest){
            cout<<arr1[i]<<", "<<"";
        }
    }
    cout<<endl;
    
    delete [] arr1;
    delete [] arr2;
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
    if(wantedIndex == -1){
        cout<<"Cabinet with ID: "<<id<<"is not available"<<endl;
    }
    
}

bool LabOrganizer::checkSurrounding(int row, int column, Cabinet* point){
    int matrixRow = point->getRow();
    int matrixColumn = point->getColumn();
    bool right, left, up, down = false;
    up = false;
    if(row-1 >= 0){
        if(point->getTypeChem(row-1,column) == "c"){
            return false;

        }
        up = true;
    }

    if (row+1<matrixRow)
    {
        if (point->getTypeChem(row+1,column) == "c")
        {
            return false;
        }
        down = true;
    }

    if (column+1<matrixColumn)
    {
        if (point->getTypeChem(row,column+1) == "c")
        {
            return false;
        }
        right = true;
        
    }

    if (column-1>=0)
    {
        if (point->getTypeChem(row,column-1) == "c")
        {
            return false;
        }
        left = true;
        
    }

    if(right && up){
        if (point->getTypeChem(row-1,column+1) == "c")
        {
            return false;
        }
    }

    if(right && down){
        if (point->getTypeChem(row+1,column+1) == "c")
        {
            return false;
        }
    }

    if(left && up){
        if (point->getTypeChem(row-1,column-1) == "c")
        {
            return false;
        }
    }

    if(left && down){
        if (point->getTypeChem(row+1,column-1) == "c")
        {
            return false;
        }
    }

    return true;
}

int LabOrganizer::getSize(){
    return size;
}

void LabOrganizer::removeChemical(int id){
    int inx = -1;
    for (int i = 0; i < size; i++)
    {
        if(cabinets[i]->checkId(id)){
            inx = i;
        }
    }
    if(inx >= 0){
        for (int i = 0; i < cabinets[inx]->getRow(); i++)
        {
            for (int j = 0; j < cabinets[inx]->getColumn(); j++)
            {
                if(cabinets[inx]->getChemicalId(i,j) == id){
                    if(cabinets[inx]->getTypeChem(i,j) != "+"){
                        cabinets[inx]->removeChenical(i,j);
                        cout<<"chemical with ID: "<<id<< " succesfully removed"<<endl;
                        return;
                    }
                    else{
                        cout<<"No chemical in place!"<<endl;
                    }
                }
            }
            
        }
        cout<<"chemical couldnt be removed!"<<endl;
        
    }
    else{
        cout<<"Id: "<<id<<" Does Not EXSISTS!!"<<endl;
    }
    
}