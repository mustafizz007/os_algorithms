#include<bits/stdc++.h>
using namespace std;

void find_wt(int process[], int n, int bt[], int wt[], int priority[])
{
    for (int i = 0; i < n -1; i++){
        for (int j = i + 1; j < n; j++){
            if (priority[i] > priority[j])
            {
                int tmp = priority[i];
                priority[i] = priority[j];
                priority[j] = tmp;

                int tmp2 = bt[i];
                bt[i] =  bt[j];
                bt[j] = tmp2;

                int tmp3 = process[i];
                process[i] = process[j];
                process[j] = tmp3;
            }
        }
    }

    wt[0] =0;
    for (int i =1; i< n; i++){
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


void find_avg_time(int process[], int n, int bt[], int priority[])
{

    int wt[n], tat[n];

    find_wt(process, n, bt, wt, priority);
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
    int priority [] = {2, 1, 3};


    int n = sizeof(process) / sizeof(process[0]);

    find_avg_time(process, n, bt, priority);



}
