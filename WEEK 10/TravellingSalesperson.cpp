#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int tsp(int mask, int u, int n, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
    if (mask == (1 << n) - 1) {
        return dist[u][0];
    }

    if (memo[mask][u] != -1) {
        return memo[mask][u];
    }

    int min_cost = INF;

    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) {
            int new_cost = dist[u][v] + tsp(mask | (1 << v), v, n, dist, memo);
            min_cost = min(min_cost, new_cost);
        }
    }

    return memo[mask][u] = min_cost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n > 20) {
        cout << "Dynamic programming with bitmasking is recommended for n <= 20 due to memory limits." << endl;
        return 1;
    }

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> memo(1 << n, vector<int>(n, -1));

    int min_total_cost = tsp(1, 0, n, dist, memo);

    cout << "The minimum cost of the TSP tour is: " << min_total_cost << endl;

    return 0;
}

