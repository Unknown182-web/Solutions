
#include <iostream.h>
#include <conio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
return 0;

    if (wt[n - 1] > W)
return knapsack(W, wt, val, n - 1);
    else
return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
  knapsack(W, wt, val, n - 1));
}

void main()
{
    clrscr();

    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int wt[100], val[100];

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
cin >> wt[i];
    }

    cout << "Enter the values of the items:\n";
    for ( i = 0; i < n; i++) {
cin >> val[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    getch();
}