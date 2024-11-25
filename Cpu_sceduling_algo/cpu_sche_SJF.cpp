#include<bits/stdc++.h>
using namespace std;

void find_wt(int process[], int n, int bt[], int wt[]){
    /*int completion_time[n];
    completion_time[0] = bt[0];
    wt[0] = 0;
    for (int i =1; i<n; i++){
        completion_time[i] = completion_time[i-1] + bt[i-1];
        wt[i] = completion_time[i] - bt[i];
    }*/

    for (int i =0; i< n-1; i++){
        for (int j = i+1; j < n; j++){
            if (bt[i] > bt[j]){
                swap(bt[i], bt[j]);
                swap(process[i], process[j]);
            }
        }
    }
    wt[0] =0;
    for (int i =1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }


}

void find_tat(int process[], int n, int bt[], int wt[], int tat[])
{
    for (int i =0; i< n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}


void find_avg_time(int process[], int n, int bt[])
{

    int wt[n], tat[n];

    find_wt(process, n, bt, wt);
    find_tat(process, n, bt, wt, tat);

    int tot_wt =0, tot_tat=0;

    for (int i =0; i< n; i++)
    {
        tot_tat += tat[i];
        tot_wt += wt[i];
    }

    cout << "process\tburst time\twaiting time\tturnaround time\n";

    for (int i =0; i< n; i++)
    {
        cout << process[i] << "\t" << bt[i] << "\t\t" << wt[i]  << "\t\t" << tat[i] <<endl;
    }

    cout << "avg_waiting_time = " << double(tot_wt) / n << endl;
    cout << "avg_tat_time = "<< double(tot_tat) / n << endl;

}




int main()
{

    int process [] = {1, 2, 3};
    int bt[] = {6, 8, 7};

    int n = sizeof(process) / sizeof(process[0]);

    find_avg_time(process, n, bt);



}
