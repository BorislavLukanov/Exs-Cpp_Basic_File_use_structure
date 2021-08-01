
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


int choise,i,m,elements;

void SelectFile();
void DisplayFile();
void DispElement();
void OpnFile();
int quit();
FILE* orgFile;
struct MyStruct
{
    int number;
    char type[15];
    char content[100];
};
MyStruct initFile[100];



int main()
{
    
    printf("\n---------File with structure----------\n");
    printf("\nThe File of format contains data structure of elements:\n- Number\n- Type/description of max 15 characters\n- Content of text\n\n---------------------------------------\n");

    printf("\nChoose from the menu.\n");
    
    do {
        printf("\n1 Load a file.\n2 Display the file.\n3 Display exact element from the structures.\n4 some\n5 quit\n");
        printf("\nChoise: "); scanf_s("%d", &choise);
        
    switch (choise)
    {
    case 1: SelectFile();
        break;
    case 2: DisplayFile();
        break;
    case 3: DispElement();
       break;
    case 4: OpnFile();
        break;
    case 5: quit();
        break;
    default: printf("\nChoose from 1 to 5\n");
        break;
    };
    } while (choise != 5);
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
       printf("\nFile selected: %s\n", nameFile);       
    }
    else
    {
        printf("\nNo such file.\n");
    };
    for (;;) {
        char arrFile[200];
        fgets(arrFile, 200, orgFile);
        if (arrFile[0] == '.') break;
        initFile[i].number = atoi(arrFile);        
        fgets(arrFile, 200, orgFile);
        strcpy_s(initFile[i].type, arrFile);
        fgets(arrFile, 200, orgFile);
        strcpy_s(initFile[i].content, arrFile);
        elements = i+1;
        i = i + 1;
    };
    std::cout << "File initialized.\n";
    printf("\nStructures: %d\n", elements);
};

void DisplayFile()
{ 
    
    for (i=0;i<elements;i++){
        printf("\n%d\n%s%s", initFile[i].number, initFile[i].type, initFile[i].content);
    };
};

void DispElement()
{
    MyStruct DispEl[20];
    char arrDisp[20], el[10];
    std::cout << "Element to display: numer ; type ; text\n";
    std::cin >> el;
    for (i = 0; i < 100; i++)
    {
        fgets(arrDisp, 100, orgFile);
        if (arrDisp[0] == '.') 
        {
            std::cout << "\nEnd of file"; return;
        };
        DispEl[i].number = atoi(arrDisp);
        fgets(arrDisp, 100, orgFile);
        strcpy_s(DispEl[i].type, arrDisp);
        fgets(arrDisp, 100, orgFile);
        strcpy_s(DispEl[i].content, arrDisp);
        //printf("\n%s", DispEl->type);
        if (el == "1") {
            for (i = 0; i < 100; i++)
            {
                printf("\n%d", DispEl->number);
            };
        };
        if (el == "type")
        {
            for (i = 0; i < 100; i++)
            {
                printf("\n%s", DispEl->type);
            };
        }
        if (el == "text")
        {
            for (i = 0; i < 100; i++)
            {
                printf("\n%s", DispEl->content);
            };
        }
    };
    
   
    
    
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
        //    std::ofstream File2("File1.txt");
        //File2 << "Hello";

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

int quit()
{
    std::cout << "\nquake :D\n"; return 0;
};