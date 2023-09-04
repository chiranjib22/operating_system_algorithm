#include <iostream>

using namespace std;
void print(int at[], int bt[], int wt[], int n)
{
    cout << "PN\t\tAT\t\tBN\t\tWT\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }
}

void avg(int wt[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    cout << "Average waiting time = " << sum / (double)n << endl;
}

void calculateWaitingTime(int at[], int bt[], int n)
{
    int wt[n];

    // waiting time for the first process is 0
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = (at[i - 1] + bt[i - 1] + wt[i - 1]) - at[i];
    }
    // print the waiting time for each process
    print(at, bt, wt, n);

    // avg. waiting time
    avg(wt, n);
}
int main()
{
    // number of process
    int n = 5;

    // array for arrival time
    int at[] = {0, 1, 2, 3, 4};

    // array for burst time
    int bt[] = {4, 3, 1, 2, 5};

    // to find the waiting time
    calculateWaitingTime(at, bt, n);
    return 0;
}