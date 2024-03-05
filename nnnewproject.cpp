#include <iostream>
#include <algorithm>

using namespace std;


int getMinIndex(int arr[], int n) {
    int minInd = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minInd]) {
            minInd = i;
        }
    }
    return minInd;
}


int getMaxIndex(int arr[], int n) {
    int maxInd = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxInd]) {
            maxInd = i;
        }
    }
    return maxInd;
}


void cashFlowTask(int amount[], int n) {
    int max_credit = getMaxIndex(amount, n);
    int max_debit = getMinIndex(amount, n);

    
    if (amount[max_credit] == 0 && amount[max_debit] == 0) {
        return;
    }

    
    int min_val = min(-amount[max_debit], amount[max_credit]);

    
    amount[max_credit] -= min_val;
    amount[max_debit] += min_val;

    
    cout << "Person " << max_debit + 1 << " pays " << min_val << " to Person " << max_credit + 1 << endl;

    
    cashFlowTask(amount, n);
}


void minCashFlow(int* graph[], int n) {
    int* amount = new int[n]();

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            amount[i] += (graph[j][i] - graph[i][j]);
        }
    }

    
    cashFlowTask(amount, n);

    delete[] amount;
}

int main() {
    int n;

    
    cout << "Enter the number of individuals: ";
    cin >> n;

    int** graph = new int*[n];

    
    cout << "Enter the debt/credit amounts between the individuals: " << endl;
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    
    minCashFlow(graph, n);

    
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
