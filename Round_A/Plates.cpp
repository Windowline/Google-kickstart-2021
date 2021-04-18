#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K, P; //stack, paltes in each stack, plates to get

//dp(stack, count): 현재 위치한 0~stack까지 고려한 상태이고 취해온 갯수가 count일 때 최대 beautyValue 
int dp(int stack, int count, vector<vector<int>>& plates, vector<vector<int>>& cache) {
    if (count == P)
        return 0;
    if (stack == N)
        return -1e9;
    if (cache[stack][count] != -1)
        return cache[stack][count];
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < K && (count + i + 1) <= P; ++i) {
        sum += plates[stack][i];
        int subAns = dp(stack + 1, count + i + 1, plates, cache);
        if (subAns > -1e9)
            ans = max(ans, subAns + sum);
    }
    // no select
    int subAns = dp(stack + 1, count, plates, cache);
    if (subAns > -1e9)
        ans = max(ans, subAns);
    return cache[stack][count] = ans;
}

int solve(vector<vector<int>>& plates) {
    int ans = 0;
    vector<vector<int>> cache = vector<vector<int>>(N, vector<int>(N * K, -1));
    ans = dp(0, 0, plates, cache);
    return ans;
}


int main() {
    
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d %d", &N, &K, &P);
        vector<vector<int>> plates = vector<vector<int>>(N, vector<int>());
        for (int n = 0; n < N; ++n) {
            for (int k = 0; k < K; ++k) {
                int bv;
                scanf("%d", &bv);
                plates[n].push_back(bv);
            }
        }
        
        int ans = solve(plates);
        printf("Case #%d: %d\n", tc + 1, ans);
    }
    
    
}
