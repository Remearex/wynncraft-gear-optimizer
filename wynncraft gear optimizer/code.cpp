#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<pair<int, int>> items = {{25, 0}, {20, 10}, {15, 20}, {10, 30}}; // modify if needed
    int N = 3; // modify if needed
    int M = 55; // modify if needed
    
    int dp[N+1][M+1];
    dp[0][0] = 0;
    for (int j = 1; j <= M; j++) {
        dp[0][j] = -1;
    }
    
    for (int numEles = 1; numEles <= N; numEles++) {
        for (int mana = 0; mana <= M; mana++) {
            int optimalVal = -1;
            for (pair<int, int> item : items) {
                if (mana - item.first < 0) {
                    optimalVal = max(optimalVal, dp[numEles-1][0] + item.second);
                } else if (dp[numEles-1][mana - item.first] == -1) {
                    continue;
                } else {
                    optimalVal = max(optimalVal, dp[numEles-1][mana - item.first] + item.second);
                }
            }
            dp[numEles][mana] = optimalVal;
        }
    }
    
    cout << dp[N][M] << endl;
    
    // extract solution
    
    if (dp[N][M] == -1) {
        cout << "no solution" << endl;
        return 0;
    }
    
    vector<pair<int, int>> solution;
    
    int mana = M;
    
    for (int numEles = N; numEles > 0; numEles--) {
        for (pair<int, int> item : items) {
            int val = -1;
            if (mana - item.first < 0) {
                val = dp[numEles-1][0] + item.second;
            } else {
                val = dp[numEles-1][mana - item.first] + item.second;
            }
            if (val == dp[numEles][mana]) {
                solution.push_back({item.first, item.second});
                mana -= item.first;
                break;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << solution[i].first << " " << solution[i].second << endl;
    }
}