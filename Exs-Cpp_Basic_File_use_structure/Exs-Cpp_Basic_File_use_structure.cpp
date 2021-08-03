/*For code revisioning:
* Add function for structure nulling and reviewing DispElement() for syntax errors on adding 1st element*/

#include <iostream>
#include <fstream>

int choise,i,m,elements,fil=0;
void SelectFile();
void DisplayFile();
void DispElement();
void AddStruct();
void Save();
int quit();
FILE* orgFile;
struct MyStruct
{
    int number;
    char type[15];
    char text[100];
};
MyStruct initFile[100];
char nameFile[10];

int main()
{    
    printf("\n---------File with structure----------\n");
    printf("\nThe File contains structure of elements:\n- Number\n- Type\n- Text\n\n---------------------------------------\n");
    printf("\nChoose from the menu.\n");
    do {
        printf("\n1 Load a file.\n2 Display the file.\n3 Display exact element from the structures.\n4 Add structure element.\n5 Save the structure to new file.\n6 quit\n");
        printf("\nChoise: "); scanf_s("%d", &choise);
        switch (choise)
        {
        case 1: SelectFile(); break;
        case 2: DisplayFile(); break;
        case 3: DispElement(); break;
        case 4: AddStruct(); break;
        case 5: Save(); break;
        case 6: quit(); break;
        default: printf("\nChoose from 1 to 6\n"); break;
        };
    }
    while (choise != 6);
};

void SelectFile()
{
    errno_t err;
    std::cout << "\nSelect the file you want to use.\nChoose between File.txt and File2.txt\n";
    std::cin >> nameFile;
    err = fopen_s(&orgFile, nameFile, "r");
    if (err == 0)
    {
       printf("\nFile selected: %s\n", nameFile);
       for (;;) {
           char arrFile[200];
           fgets(arrFile, 200, orgFile);
           if (arrFile[0] == '.') break;
           initFile[i].number = atoi(arrFile);
           fgets(arrFile, 200, orgFile);
           strcpy_s(initFile[i].type, arrFile);
           fgets(arrFile, 200, orgFile);
           strcpy_s(initFile[i].text, arrFile);
           elements = i + 1;
           i = i + 1;
       };
       std::cout << "File initialized.\n";
       printf("\nNumber of structures in the file: %d\n", elements);
    }
    else
    {
        printf("\nNo such file.\n");
    };
    fclose(orgFile);
    fil = 1;
};

void DisplayFile()
{ 
    for (i=0;i<elements;i++)
    {
        printf("\n%d\n%s%s", initFile[i].number, initFile[i].type, initFile[i].text);
    };
};

void DispElement()
{
    int el;
    do{
        std::cout << "Element to display:\n1 numer\n2 type\n3 text\n";
        std::cin >> el;
        switch (el)
        {
        case 1: for (i = 0; i < elements; i++) printf("%d\n", initFile[i].number); break;
        case 2: for (i = 0; i < elements; i++) printf("%s", initFile[i].type); std::cout << "\n"; break;
        case 3: for (i = 0; i < elements; i++) printf("%s", initFile[i].text); std::cout << "\n"; break;
        default: printf("\nChoose from 1 to 3\n"); break;
        };
     }
    while (el < 1 || el>3);
};

void AddStruct()
{
    int floop = elements;
    printf("\nCurrent structures in the file: %d", i);
    for (i = floop; i < 100; i++)
    {
        char input[20];
        printf("\nEnter structure: %d\n", i+1);
        printf("\nEnter element - number: "); 
        gets_s(input);
        if (input[0] == '.') break;
        initFile[i].number = atoi(input);
        printf("\nEnter element - type: "); gets_s(initFile[i].type);
        printf("\nEnter element - text: "); gets_s(initFile[i].text);
        elements += 1;
        std::cout << "\n";
    }
};

void Save()
{
    char name[20];
    printf("Insert name of the file .txt:\n");
    std::cin >> name;
    std::ofstream myfile(name);
    printf("\nThe name is: %s\n", name);
    if (myfile.is_open())
    {
        for (i = 0; i < elements; i++)
        {
            myfile << initFile[i].number;
            myfile << initFile[i].type;
            myfile << initFile[i].text;
        }
        myfile << ".";
        printf("\nNew structure saved to file: %s.\n", name);
    }
    else
    {
        printf("\nCan't open file %s.\n", name);
    }
    myfile.close();
    printf("\nHello World. :)\n");
};

int quit()
{
    if (fil)
    {
        std::cout << "\nquake :D\n"; return 0;
    };
    std::cout << "\nNo file selected, quake :D\n"; return 0;
};