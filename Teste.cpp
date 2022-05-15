#include <iostream>
#include <windows.h>
#include <fstream>
#define tam 1000

using namespace std;

int ReadFile1000(ifstream &arq, int v[tam]) {
    int count = 0;

    arq.open("ListaOrdenada-1000.txt");

    if (arq.fail()) {
        cerr << "Houve um problema ao abrir o arquivo!\n";
        arq.clear();
    } else {
        while(!arq.eof()) {
            arq >> v[count]; 
            count++;
        }
    }

    arq.close();
} 

void ImprimeVetor(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ifstream arq;
    int v[tam];

    ReadFile1000(arq, v); 
    ImprimeVetor(v, tam);
    return 0;
}