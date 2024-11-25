#include<bits/stdc++.h>
using namespace std;

void find_wt(int process[], int n, int bt[], int wt[], int quanta)
{

    int time = 0;

    int rem_bt[n];
    for (int i =0; i<n; i++)
    {
        rem_bt[i] = bt[i];
    }

    while (1)
    {
        int done = 1;
        for (int i =0; i<n; i++)
        {

            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > quanta)
                {

                    time += quanta;
                    rem_bt[i] -= quanta;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] =0;
                }

            }

        }
        if (done) break;
    }


}

void find_tat(int process[], int n, int bt[], int wt[], int tat[])
{
    for (int i =0; i< n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}


void find_avg_time(int process[], int n, int bt[], int quanta)
{

    int wt[n], tat[n];

    find_wt(process, n, bt, wt, quanta);
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
    int quanta = 4;

    int n = sizeof(process) / sizeof(process[0]);

    find_avg_time(process, n, bt, quanta);



}
