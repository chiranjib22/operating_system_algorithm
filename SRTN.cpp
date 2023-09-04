#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid; // process id
    int bt;  // burst time
    int art; // arrival time
};

void findWaitingTime(Process proc[], int n, int wt[])
{
    int rt[n];

    // copy the burst time into rt[]
    for (int i = 0; i < n; i++)
    {
        rt[i] = proc[i].bt;
    }
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, completion_time;
    bool check = false;

    // process until all processes gets completed
    while (complete != n)
    {
        // find process with minimum time remaining time along
        // processes that arrives till the current time
        for (int j = 0; j < n; j++)
        {
            if (proc[j].art <= t && rt[j] < minm && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        // reduce remaining time
        rt[shortest]--;

        // update minm
        minm = rt[shortest];
        if (minm == 0)
        {
            minm = INT_MAX;
        }
        // if a process gets completely executed
        if (rt[shortest] == 0)
        {
            complete++; // increment complete process
            check = false;
            completion_time = t + 1; // store finish time of the current process

            // waiting time = completion time - arrival time - burst time
            wt[shortest] = completion_time - proc[shortest].art - proc[shortest].bt;
            if (wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
        }
        // increment the time (i process gets cpu)
        t++;
    }
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // TurnAroundTime = waiting time + burst time
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + proc[i].bt;
    }
}
void findAvgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    // output
    cout << "Process \t"
         << "Burst Time\t"
         << "Arrival Time\t"
         << "Waiting Time\t"
         << "Turn Around Time" << endl;

    // calculate total turn around time and total waiting time
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t\t"
             << proc[i].art << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << "\t\t" << endl;
    }
    cout << "Average Waiting Time = " << (float)total_wt / (float)n << endl;
    cout << "Average Turn Around Time = " << (float)total_tat / (float)n << endl;
}

int main()
{
    Process proc[] = {{1, 6, 2},
                      {2, 2, 5},
                      {3, 8, 1},
                      {4, 3, 0},
                      {5, 4, 4}};
    int n = sizeof(proc) / sizeof(proc[0]);
    findAvgTime(proc, n);
    return 0;
}