#include <iostream>
using namespace std;

int main() {
    int n,i,j,arm;

//montagem do vetor
    do {
        cout << "Informe o tamanho do vetor: ";
        cin >> n;
        if(n <= 0 || n > 100) cout << "\nValor incorreto. Tente novamente.\n";
    } while(n <= 0 || n > 100);

    int vetA[n];


    for(i = 0; i < n; i++) {
        cout << "Informe o valor da posicao "<<i<<" :";
        cin >> vetA[i];
    }

    //estrutura de repeticao para ordenar de maneira crescente o vetor olhando de tras pra frente
    for(i = n - 1; i > 0; i--) {
        arm = i;
        for(j = 0; j < i; j++) {
            if(vetA[j] > vetA[arm]) {
                arm = j;
            }
        }
        //temp para troca temporaria
        int temp = vetA[i];
        vetA[i] = vetA[arm];
        vetA[arm] = temp;
    }

    //apresentacao do vetor
    cout << "Vetor ordenado: ";
    for(i = 0; i < n; i++) {
        cout << vetA[i] << " ";
    }

    return 0;
}
