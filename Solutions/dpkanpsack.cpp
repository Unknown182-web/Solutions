#include <iostream.h>
#include <conio.h>  
#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int knapsack(int W, int weights[], int values[], int n) {
    int dp[MAX_ITEMS][MAX_WEIGHT] ; 
    for (int i = 1; i <= n; ++i) {
	for (int w = 0; w <= W; ++w) {
	    if (weights[i - 1] <= w) {
		dp[i][w] = (dp[i - 1][w] > dp[i - 1][w - weights[i - 1]] + values[i - 1])
			   ? dp[i - 1][w]
			   : dp[i - 1][w - weights[i - 1]] + values[i - 1];
	    } else {
		dp[i][w] = dp[i - 1][w];
	    }
	}
    }
    return dp[n][W];
}

void main() {
    clrscr();  

    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int weights[MAX_ITEMS],values[MAX_ITEMS];

 
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
	cin >> weights[i];
    }
    cout << "Enter the values of the items:\n";
    for (i=0; i < n; ++i) {
	cin >> values[i];
    }

    int result = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained is: " << result << endl;

    getch(); 
}