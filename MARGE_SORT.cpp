#include <iostream>
using namespace std;

//funcao para intercalar
void intercala(int A[],int p,int q,int r){
    //declaracao de variaveis temporarias para ordenacao
    int n1 = q-p+1;
    int n2= r- q;
    int A_um[n1], A_dois[n2];
    int i,j,k;

    //copia dos valores do vetor para a primeira parte
    for(i = 0; i < n1; i++){
        A_um[i]=A[p+i];
    }
    //copia dos valores do vetor para a segunda parte
    for(j = 0;j<n2;j++){
        A_dois[j]=A[q+1+j];
    }
    //zerando valores para repeticao
    i = 0;
    j = 0;
    k = p;

    //estrutura para percorrer o vetor
    while(i<n1 && j<n2){
        //estrutura de condicao para montar o vetor ordenado
        if(A_um[i]<=A_dois[j]){
            A[k]=A_um[i];
            i++;
        }else{
            A[k]=A_dois[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = A_um[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = A_dois[j];
        j++;
        k++;
    }
    }
    //marge sort
    int marge_sort(int A[],int p,int r){
    if(p<r)
    {
        int q=(p+r)/2;
            marge_sort(A,p,q);
            marge_sort(A,q+1,r);
            intercala(A,p,q,r);
    }
}
int main()
{
    int n,i;

    //criacao do vetor
    cout<<"Informe o numero do vetor: ";
    do
    {
        cin>>n;
        if(n<=0 || n>=100){
            cout<<"Valor invalido, informe novamente: ";
        }
    }while(n<=0 || n>=100);

    int A[n];
    for(i=0;i<n;i++){
        cout<<"Informe o numero do vetor da posicao "<<i<<" :";
        cin>>A[i];
    }

    cout<<"Vetor original: ";
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }cout << endl;

    marge_sort(A, 0, n - 1);

    cout<<"Vetor Apos MargeSort: ";
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }cout << endl;
}
