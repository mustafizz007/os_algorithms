#include<bits/stdc++.h>
using namespace std;
int main(){
    int *pntr = (int*) malloc(5 * sizeof(int));

    if (pntr == NULL){
        cout << "Failed" << endl;
        return 1;
    }

    for (int i =0; i< 5; i++){
        pntr[i] = i + 1;
    }
    for (int i =0; i< 5; i++){
        cout << pntr[i] << " ";
    }
    cout << endl;

    free(pntr);

    return 0;
}
