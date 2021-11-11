# Lab-Organizer-cpp
A pure cpp program to organize lab chemicals.

  Here i have used the knowladge of pointers, oop, pointer manipulation, multidimensional arrays, memory management, string manipulation, dynamic array usage, dynamic multidimensional array usage. And put them to use.


  Scientists in the chemistry lab need a software tool to keep track of combustible and retardant chemicals that are stored in the lab cabinets. In ordinary circumstances this software would simply be required to keep the location of each chemical in the cabinets. However, since some of the chemicals are combustible, scientists need to employ a specific strategy to minimize the risk of fire. That is since combustive materials are likely to ignite if in contact, no two combustive chemicals can be placed next to each other. Therefore the software designed for the lab needs to account for this rule.
The cabinets in the lab have varying heights and widths which are measured with the number of individual storage slots. The rows in the cabinet are marked with the English alphabet, while columns are numbered with integers starting from 1. Below is an illustration of a cabinet with three rows and three columns.

               1       2       3       4       5        
        --------------------------------------------
         A |       |       |       |       |       |    
        --------------------------------------------
         B |       |       |       |       |       |
        --------------------------------------------
         C |       |       |       |       |       |
        --------------------------------------------
The general rule for placing chemicals is as follows: retardant chemicals can be placed at any free location. However, combustive chemicals cannot be next to each other in horizontal, vertical or diagonal directions. If a combustive chemical can not be placed program should display the closest available slots.
        
App has these main functions for the lab organizer:

● Add a cabinet
● Remove a cabinet
● Show the list of cabinets
● Show the contents of a cabinet
● Place a chemical
● Find a chemical
● Remove the chemical

Also for overloading and developing purposes cabinet and chemical classes are made public

For Cabinet class these functions exists for writing custom functions and behaviours:

constructor for the Cabinet;
    Cabinet(int id = 0, int rows = 0, int columns = 0);
    ---Destructor for Cabinet---
    ~Cabinet();
    ---Function thet gets the type of chem in a specific point in thecabinet---
    string getTypeChem(int row,int column);
    ---Function that writes the insides in console,in a readable form---
    void contents();
    ---Function that places checmical with some rules(stated above)---
    void placeChemical(int row, int column, string chemType, int chemID);
    ---Function that removes checmical with some rules(stated above)---
    void removeChenical(int row, int column);
    ---Function that finds checmical with some id---
    void findChemical(int id);
    ---gets id of the cabinet---
    int getId();
    ---gets the number of rows in that cabinet---
    int getRow();
    ---gets the number of columns in that cabinet---
    int getColumn();
    ---gets the number of empty slots in that cabinet---
    int plusCount();
