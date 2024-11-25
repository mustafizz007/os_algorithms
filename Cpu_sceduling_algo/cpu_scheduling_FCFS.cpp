/*FCFS is a non-preemptive scheduling algorithm.
- Processes are executed in the order of their arrival time.
- There is no interruption, and each process is executed until completion before the next process starts.*/
#include<bits/stdc++.h>
using namespace std;

void find_waiting_time(int process[], int n, int bt[], int wt[]){
    wt[0] = 0;
    for (int i = 1; i< n; i++){
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void find_turn_around_time(int process[], int n, int bt[], int wt[], int tat[]){

    for (int i =0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }
}

void find_avg_time(int process[], int n, int bt[]){

    int wt[n], tat[n];

    find_waiting_time(process, n, bt, wt);
    find_turn_around_time(process, n, bt, wt, tat);

    int total_wt =0, total_tat =0;

    for (int i =0; i< n; i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "process\tburst time\twaiting time\tturnaround time\n";

    for (int i =0; i< n; i++){
        cout << process[i] << "\t" << bt[i] << "\t\t" << wt[i]  << "\t\t" << tat[i] <<endl;
    }

    cout << "avg_waiting_time = " << double(total_wt) / n << endl;
    cout << "avg_tat_time = "<< double(total_tat) / n << endl;


}
int main(){

    int process[] = {1, 2, 3};
    int bt[] = {6, 8, 7};
    int n = sizeof(process) / sizeof(process[0]);

    find_avg_time(process, n, bt);



}
