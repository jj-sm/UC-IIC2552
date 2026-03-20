#include <iostream>

using namespace std;

int main(){

    vector<int> A = {1, 2, 2, 2, 3, 5, 7};
    int x = 2;

    int n = A.size();

    //BUSCAR PRIMER INDICE >= x

    int l = 0;
    int r = n-1;

    while(l < r){

        //mid
        int mid = (l + r)/2;

        //si a[mid] es >= x entonces el primer >= x puede estar en mid o a la izquierda
        if(A[mid] >= x){
            r = mid;
        }
        // si a[mid] < x entonces el primer >= x está a la derecha
        else{
            l = mid + 1;
        }
    }

    int first = l;

    //BUSCAR ULTIMO INDICE <= x

    l = 0;
    r = n-1;

    while(l < r){

        //usamos +1 para evitar loop infinito
        int mid = (l+r+1)/2;

        //si a[mid] <= x entonces el ultimo <= x puede estar en mid o a la derecha
        if(A[mid] <= x){
            l = mid;
        }
        //si a[mid] > x entonces está a la izquierda
        else{
            r = mid - 1;
        }
    }

    int last = l;

    cout<<"primer indice >= x: "<<first<<endl;
    cout<<"ultimo indice <= x: "<<last<<endl;
    
    return 0;
}
