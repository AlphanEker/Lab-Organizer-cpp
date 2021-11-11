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

    delete this->chemicals[row][column];
    this->chemicals[row][column] = new Chemical(chemID, chemType);
    contents();
}
void Cabinet::removeChenical(int row,int column){
    delete this->chemicals[row-1][column-1];
    this->chemicals[row-1][column-1] = new Chemical();
}
void Cabinet::findChemical(int id){
    bool a = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(chemicals[i][j]->getId() == id ){
                cout << alphabet[i] + to_string(j+1)<<endl;
                a = true;
            }
        }
        
    }

    if(!a)
    cout << to_string(id) << " not found"<<endl;
}
int Cabinet::getId(){
    return id_cabinet;
}
void Cabinet::contents(){
    string* arr = new string[rows];
    string out = "         ";
    for (int i = 0; i < columns; i++)
    {
        out = out + to_string(i+1) + "    " ;
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