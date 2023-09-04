#include <iostream>
using namespace std;

void sort(int a[][4], int n)
{
    // sort according to their burst time

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][1] > a[j][1])
            {
                // swapping the burst time
                int temp = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] = temp;

                // swapping the process id
                temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;
            }
        }
    }
}

int calculateWaitingTime(int a[][4], int n)
{
    // waitingTime[i] = burstTime[i-1] + waitingTime[i-1]
    // arrival time of all processes are 0

    a[0][2] = 0;        // let the waiting time of 1st process is 0
    int t_wt = a[0][2]; // total waiting time
    for (int i = 1; i < n; i++)
    {
        a[i][2] = a[i - 1][1] + a[i - 1][2];
        t_wt += a[i][2];
    }
    return t_wt;
}

int calculateTurnAroundTime(int a[][4], int n)
{

    int t_tt = 0; // total turnaround time
    for (int i = 0; i < n; i++)
    {
        a[i][3] = a[i][1] + a[i][2];
        t_tt += a[i][3];
    }
    return t_tt;
}

int main()
{
    int n;

    // input the number of process
    cout << "Enter the number of process: ";
    cin >> n;
    int A[n][4];

    // input the burst time of all process.
    //  assuming that all processes are arrive at 0ms
    // arrival_time = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> A[i][1];
        A[i][0] = i + 1;
    }

    sort(A, n);
    double avg_wt = calculateWaitingTime(A, n) / (double)n;
    double avg_tt = calculateTurnAroundTime(A, n) / (double)n;

    cout << "PN\t"
         << "BT\t"
         << "WT\t"
         << "TT\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << A[i][0] << ":\t" << A[i][1] << "\t" << A[i][2] << "\t" << A[i][3] << endl;
    }
    cout << "Average Waiting Time = " << avg_wt << endl;
    cout << "Average Turn Around Time = " << avg_tt << endl;
    return 0;
}