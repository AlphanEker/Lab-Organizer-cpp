#include <iostream>
#include <string>
#include "Cabinet.h"
using namespace std;


Cabinet::Cabinet( int id, const int row, const int column){
    this->id_cabinet = id;
    this->rows = row;
    this->columns = column;
    /////////////////
    alphabet[0] = "A";
    alphabet[1] = "B";
    alphabet[2] = "C";
    alphabet[3] = "D";
    alphabet[4] = "E";
    alphabet[5] = "F";
    alphabet[6] = "G";
    alphabet[7] = "H";
    alphabet[8] = "I";

    /////////////////

    if(row > 0 && column > 0){
        this->chemicals = new Chemical**[row];
        for (int i = 0; i < row; i++){
            this->chemicals[i] = new Chemical*[column]; 
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                this->chemicals[i][j] = new Chemical();
            }
            
        }
        
    }
    

}

Cabinet::~Cabinet(){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete chemicals[i][j];
        }
        
    }
    for (int i = 0; i < rows; i++)
    {
        delete [] chemicals[i];
    }
    delete [] chemicals;
    
    
}
string Cabinet::getTypeChem(int row,int column){

    return this->chemicals[row][column]->getType();
    
}
string Cabinet::getTypeChem2(int row,int column){

    return this->chemicals[row][column]->getType();
    
}
void Cabinet::placeChemical(int row, int column, string chemType, int chemID){
    delete chemicals[row][column];
    this->chemicals[row][column] = new Chemical(chemID, chemType);
}
void Cabinet::removeChenical(int row,int column){
    delete chemicals[row][column];
    this->chemicals[row][column] = new Chemical();
}
void Cabinet::findChemical(int id){
    bool a = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(chemicals[i][j]->getId() == id ){
                cout << alphabet[i] << j+1<<endl;
                a = true;
            }
        }
        
    }

    if(!a)
    cout << id<< " not found"<<endl;
}
int Cabinet::getId(){
    return id_cabinet;
}
void Cabinet::contents(){
    cout<<"Cabinet with ID: "<<id_cabinet<<" and with DIM: "<<rows<<"x"<<columns<<" Contains the Chemicals: "<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(chemicals[i][j]->getId() != 0){
                cout<<" chemical:"<<chemicals[i][j]->getId()<<" is in location: "<<alphabet[i]<<j+1;
            }
        }
        
    }
    cout<<endl;
    
    string* arr = new string[rows];
    string out = "         ";
    for (int i = 0; i < columns; i++)
    {
        out = out + (char)(i+1+48) + "    " ;
    }
    out = out + "\n"+ "\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i] = arr[i] +"    "+ getTypeChem(i,j);
        }
        arr[i] = arr[i] + "\n";        
    }
    
    for (int i = 0; i < rows; i++)
    {
        out = out+ alphabet[i] + "    " + arr[i];
    }
    
    cout << out;
    delete[] arr;
}
int Cabinet::getRow(){
    return this->rows;
}
int Cabinet::getColumn(){
    return this->columns;
}
int Cabinet::plusCount(){
    int a = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(chemicals[i][j]->getType() == "+"){
                a++;
            }
        }
        
    }
    return a;
    
}
Cabinet& Cabinet::operator=( Cabinet& right ) {
    if(&right != this && right.getColumn()>0 && right.getRow()>0){

////PROBLEM TO SOLVEEEEEEEEEE44EEEEEEEEEEEEEEEEEEEEEEEEEEEE
        
        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < columns; j++)
        //     {
        //         delete this->chemicals[i][j];
        //     }
        //     delete[] this->chemicals[i];
        //     delete[] this->chemicals;
        // }
        
        this->changeRow(right.getRow());
        this->changeColumn(right.getColumn());
        this->changeId(right.getId());
        
        this->chemicals = new Chemical**[rows];
        for (int i = 0; i < rows; i++){
            this->chemicals[i] = new Chemical*[columns]; 
        }
        for (int i = 0; i < right.rows; i++)
        {
            for (int j = 0; j < right.columns; j++)
            {
                this->chemicals[i][j] = new Chemical();
                (*this->chemicals[i][j]).changeID((right.chemicals[i][j]->getId()));
                (*this->chemicals[i][j]).changeType((right.chemicals[i][j]->getType2()));
            }
            
        }
        
        
        
    }
    return *this;
    
}
void Cabinet::changeId(int id){
    this->id_cabinet = id;
}

void Cabinet::changeColumn(int column){
    this->columns = column;
}

void Cabinet::changeRow(int row){
    this->rows = row;
}
bool Cabinet::checkId(int id){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(chemicals[i][j]->getId()==id)
            return true;
        }
        
    }
    return false;
    
}
int Cabinet::getChemicalId(int row, int column){
    return chemicals[row][column]->getId();
}