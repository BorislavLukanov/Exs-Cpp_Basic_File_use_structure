
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


int choise,i,m;

void SelectFile();
void Edit();
void DispCont();
void OpnFile();
void some();
FILE* orgFile;
struct MyStruct
{
    int number;
    char type[15];
    char content[100];
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
    case 1: SelectFile();
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
void SelectFile()
{
    errno_t err;
    char nameFile[10];
    std::cout << "\nSelect the file you want to use.\nChoose between File.txt and File2.txt\n";
    std::cin >> nameFile;
    err = fopen_s(&orgFile, nameFile, "r");
    if (err == 0)
    {
        char a[100]; int i = 0;
        printf("\nFile selected: %s\n", nameFile);       
    }

    else
    {
        printf("\nNo such file.\n");
    };
};

void Edit()
{
    
    std::ofstream File2("File1.txt");
    File2 << "Hello";

  
    
};

void DispCont()
{
    FILE* File;
    char a[50];
    MyStruct g[10];
    i = 0;
    m = 100;
    fopen_s(&File, "File.txt", "rt");


    for (;;)
    {

        fgets(a, m, File);
        if (a[0] == '.') break;
        printf("\n"); // :D

        g[i].number = atoi(a);
        fgets(a, m, File);
        strcpy_s(g[i].type, a);
        fgets(a, m, File);
        strcpy_s(g[i].content, a);

        printf("%s", g[i].type);

        //printf("%s", g[i].content);
        //strcpy_s(g[i].type, a[i]);
        // 
        //g[i].type[(strlen(g[i].type)) - 1] = '\0';
        /*
        std::fgets(a, m, File);
        strcpy_s(g[i].content, a);
        g[i].type[(strlen(g[i].content)) - 1] = '\0';
        printf("\n%c", a[i]);



        std::fgets(a, m, File);
        strcpy_s(g[i].type, a);
        printf("\n%c", a[i]);
        */
    };
    /*
    for (i = 0; i < 10; i++) {
        printf("\n%c", a[i]);
    };

std::ifstream File("File.txt");
char a[100];
File >> a;
std::cout << a;
*/
};

void OpnFile()
{
    
};

void some()
{
    
};