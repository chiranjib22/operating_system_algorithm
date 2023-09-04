#include <bits/stdc++.h>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (blockSize[j] < blockSize[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
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