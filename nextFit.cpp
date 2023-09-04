#include <bits/stdc++.h>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], j = 0, t = m - 1;
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < m; i++)
    {
        while (j < m)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j = (j + 1) % m;
        }
    }

    // output

    cout << "\nProccess No.\tProccess Size\tBlock No. \n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "not allocated!";
        cout << endl;
    }
}

int main()
{
    // input
    int n, m;
    cout << "Enter the number of proccess: ";
    cin >> n;
    int proccessSize[n];
    for (int i = 0; i < n; i++)
    {
        cout << "The size of proccess " << i + 1 << " is: ";
        cin >> proccessSize[i];
    }

    cout << "Enter the number of blocks: ";
    cin >> m;
    int blockSize[m];
    for (int i = 0; i < m; i++)
    {
        cout << "The size of block " << i + 1 << " is: ";
        cin >> blockSize[i];
    }
    nextFit(blockSize, m, proccessSize, n);
    return 0;
}