#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
#include "Sort.cpp"
#include "Sort.hpp"

using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int optionSort;
    int list[10], n;
    int optionInstances;

    do {
        menu();
        cout << "Escolha o método desejado: ";
        cin >> optionSort;

        system("cls");

        switch(optionSort) {
            case 1: 
               CallMenu(optionSort, optionInstances);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    } while (optionSort!= 7);

    system("pause");
    
    return 0;
}