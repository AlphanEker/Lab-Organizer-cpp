#include "Chemical.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Chemical::Chemical(int id, string type)
{
    this->chemID = id;
    this->chemType = type;
}

Chemical::~Chemical(){
}

int Chemical::getId(){
    return this->chemID;
}

string Chemical::getType(){
    if(this->chemType == "retardant"){
        return "r";
    }

    else if (this->chemType == "combustive")
    {
        return "c";
    }

    else{
        return "+";
    }
    
}
string Chemical::getType2(){
    return chemType;
}

void Chemical::changeID(int newId){
    this->chemID = newId;
}
void Chemical::changeType(string type){
    this->chemType = type;
}