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

void Chemical::changeID(int newId){
    this->chemID = newId;
}