
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

int choise;

void LoadFile();
void Edit();
void DispCont();
void OpnFile();
void some();

struct MyStruct
{
    int number;
    char type[15];
    char* content[100];
};



int main()
{
    printf("\n---------File with structure----------\n");
    printf("\nThe File of format contains data structure of elements:\n- Number\n- Type/description of max 15 characters\n- Content of text\n\n---------------------------------------\n");
    printf("\nChoose from the menu.\n");
    
    do {
        printf("\n1 Load a file.\n2 Edit the file.\n3 Display the content of a file.\n4 Open a file.\n5 some\n");
        
        printf("\nChoise: "); scanf_s("%d", &choise);
        
    } while (choise < 1 || choise > 5);
   
    switch (choise)
    {
    case 1: LoadFile();
        break;
    case 2: Edit();
        break;
    case 3: DispCont();
       break;
    case 4: OpnFile();
        break;
    case 5: some();
        break;
    default: printf("\nChoose from 1 to 5\n");
        break;
    };
};

void LoadFile()
{
      
    
}

void Edit()
{
    
        std::ofstream File2("File2.txt");
        File2 << "Hello1";

  
    
};

void DispCont()
{
    
};

void OpnFile()
{
    
};

void some()
{
    
};