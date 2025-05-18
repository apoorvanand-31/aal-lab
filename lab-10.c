//traveling salesman problem
#include <stdio.h>
#include <limits.h>

#define V 4  // Number of cities

// Function to find the minimum cost path using Dynamic Programming
int tspDP(int dist[][V], int dp[][1 << V], int pos, int mask) {
    if (mask == (1 << V) - 1) {
        return dist[pos][0];  // Return to starting city
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tspDP(dist, dp, city, mask | (1 << city));
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    dp[pos][mask] = ans;
    return ans;
}

// Function to initialize and call the TSP solution
void travellingSalesman(int dist[][V]) {
    int dp[V][1 << V];

    for (int i = 0; i < V; i++) {
        for (int mask = 0; mask < (1 << V); mask++) {
            dp[i][mask] = -1;
        }
    }

    int minCost = tspDP(dist, dp, 0, 1);  // Start at city 0, visited only city 0
    printf("The minimum cost is: %d\n", minCost);
}

// Main function to test the TSP
int main() {
    int dist[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    travellingSalesman(dist);
    return 0;
}
