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
    int instanceOption;

    do {
        menu();
        cout << "Escolha o método desejado: ";
        cin >> optionSort;

        system("cls");

        switch(optionSort) {
            case 1: 
               instanceOption = ReadInstanceOption();
               CallUserOption(optionSort, instanceOption);
                break;
            case 2:
                instanceOption = ReadInstanceOption();
                CallUserOption(optionSort, instanceOption);
                break;
            case 3:
                instanceOption = ReadInstanceOption();
                CallUserOption(optionSort, instanceOption);
                break;
            case 4:
                instanceOption = ReadInstanceOption();
                CallUserOption(optionSort, instanceOption);
                break;
            case 5:
                instanceOption = ReadInstanceOption();
                CallUserOption(optionSort, instanceOption);
                break;
            case 6:
                instanceOption = ReadInstanceOption();
                CallUserOption(optionSort, instanceOption);
                break;
        }
    } while (optionSort!= 7);

    system("pause");
    
    return 0;
}