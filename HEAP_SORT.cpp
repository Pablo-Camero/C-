#include <iostream>
using namespace std;

//funcao para realizar a Heapify
void heapify(int A[], int n, int i) {
    //declarar o maior valor
    int maior = i;
    //variaveis para calcular o filho esquerdo e direito
    int fEsq = 2 * i + 1;
    int fDir = 2 * i + 2;

    //condicoes para decidir o maior valor
    if (fEsq < n && A[fEsq] >= A[maior])
        maior = fEsq;

    if (fDir < n && A[fDir] >= A[maior])
        maior = fDir;

    //condicao de troca (swap) funcao de troca, chamado fancao novamente
    if (maior != i) {
        swap(A[i], A[maior]);
        heapify(A, n, maior);
    }
}
//contrucao da heap
void ContrHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
}

//codigo principal
int main() {
    int n,i,j,arm;

//criacao e aliemntacao do vetor
    do {
        cout << "Informe o tamanho do vetor: ";
        cin >> n;
        if(n <= 0 || n > 100) cout << "\nValor incorreto. Tente novamente.\n";
    } while(n <= 0 || n > 100);

    int A[n];

    for(i = 0; i < n; i++) {
        cout << "Informe o valor da posicao "<<i<<" :";
        cin >> A[i];
    }

    // Construcao a Heap
    ContrHeap(A, n);

    //apreentacao da heap
    cout<<"Heap: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}
