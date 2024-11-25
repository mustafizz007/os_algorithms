#include<bits/stdc++.h>
using namespace std;
#define MAX_RESOURCES 10
#define MAX_PROCESSES 10
int numprocess;
int numresources;
int maxx[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int availabe[MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int safe_sequence[MAX_PROCESSES];
bool finish[MAX_PROCESSES] = {false};

bool canallocate(int need[], int work[]){
    for (int i =0; i< numresources; i++){
        if (need[i] > work[i]) {
            return false;
        }
    }
    return true;
}
bool is_safe(){

    for (int i =0; i< numprocess; i++){
        for (int j =0; j< numresources; j++){
            need[i][j] = maxx[i][j] - allocation[i][j];
        }
    }

    for (int i =0; i< numresources; i++){
        work[i] = availabe[i];
    }

    int cnt =0;

    while(cnt < numprocess){
        bool found_process = false;
        for (int i =0; i < numprocess; i++){
            if (!finish[i] && canallocate(need[i], work)){
                for (int j = 0; j< numresources; j++){
                    work [j] += allocation[i][j];
                }
                    safe_sequence[cnt++] = i;
                    found_process = true;
                    finish[i] = true;
                }
            }

        if (!found_process) return false;
    }
    return true;

}
bool req_resource(int pid, int req[]){

     // Check if request is within need and available resources
    for (int i =0; i< numresources; i++){
        if (req[i] > availabe[i]) return false;
        if (req[i] > need[pid][i]) return false;
    }
    // Simulate allocation
    for (int i =0; i< numresources; i++){
        availabe[i] -= req[i];
        allocation[pid][i] += req[i];
        need[pid][i] -= req[i];
    }
    // Check if the system is in a safe state
    if (!is_safe()){
         // revert allocation
         for (int i =0; i< numresources; i++){
            availabe[i] -= req[i];
            allocation[pid][i] += req[i];
            need[pid][i] -= req[i];
         }
         return false;
    }
    return true;
}
int main(){
    cout << "enter no. of process: ";
    //int numprocess, numresources;
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
    cout << "enter the available resources vector" << endl;
    for (int i = 0; i < numresources; i++){
        cin >> availabe[i];
    }
    int pid, req[numresources];
    cout << "enter the process id making the request: ";
    cin >> pid;
    cout << "enter the req vector: " << endl;
    for (int i =0; i< numresources; i++){
        cin >> req[i];
    }

    if (req_resource(pid, req)){
        cout << "system is in safe state after acc. req." << endl;
    }
    else cout << "system would be unsafe" << endl;







}
