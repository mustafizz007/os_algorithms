#include<bits/stdc++.h>
using namespace std;
#define MAX_RESOURCES 10
#define MAX_PROCESSES 10
int numresources;
int numprocess;
int maxx[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int availabe[MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int safe_sequence[MAX_PROCESSES];
bool finish[MAX_PROCESSES] = {false};
// Function to check if resources can be allocated to a process
bool canallocate(int need[], int work[]){
    for (int i =0; i< numresources; i++){
        if (need[i] > work[i]) {
            return false;
        }
    }
    return true;
}
bool is_safe(){
    int need[numprocess][numresources];
    for (int i =0; i< numprocess; i++){
        for (int j =0; j< numresources; j++){
            need[i][j] = maxx[i][j] - allocation[i][j];
        }
    }
    // Initialize work with available resources
    for (int i =0; i< numresources; i++){
        work[i] = availabe[i];
    }

    int cnt =0;

    while(cnt < numprocess){
        bool found_process = false;
        for (int i =0; i < numprocess; i++){
            if (!finish[i] && canallocate(need[i], work)){
                // If we can allocate to process i, work vector will increase
                for (int j = 0; j< numresources; j++){
                    work [j] += allocation[i][j];
                }
                    safe_sequence[cnt++] = i;
                    found_process = true;
                    finish[i] = true;
                }
            }
        // If no process was found in this round, we are not in a safe state
        if (!found_process) return false;
    }
    return true;

}
int main(){
    cout << "enter no. of process: ";
    cin >> numprocess;
    cout << "enter no. of resources: ";
    cin >> numresources;

    cout << "enter the max matrix: " << endl;
    for (int i =0; i< numprocess; i++){
        for (int j = 0; j < numresources; j++){
            cin >> maxx[i][j];
        }
    }

    cout << "enter the allocation matrix: " << endl;
    for (int i =0; i< numprocess; i++){
        for (int j = 0; j < numresources; j++){
            cin >> allocation[i][j];
        }
    }

    cout << "enter no. of no. of resources" << endl;
    for (int i = 0; i < numresources; i++){
        cin >> availabe[i];
    }

    if (is_safe()){
        cout << "in safe state" << endl;
        for (int i =0; i< numprocess; i++){
            cout << "p" << safe_sequence[i] << " ";
        }
        cout << endl;
    }

    else {
        cout << "no safe seq" << endl;
    }







}
