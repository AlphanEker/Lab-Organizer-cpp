#include <iostream>
#include <string>
using namespace std;

class Chemical{
private:
    int chemID;
    string chemType;
public:
    Chemical (int id = 0, string type = "+");
    ~Chemical();
    int getId();
    void changeID(int newId);
    string getType();
    void changeType(string type);
    string getType2();
};