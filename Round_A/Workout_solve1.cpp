#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;


int N, K;
int solve(vector<int>& mini) {
    priority_queue<pair<int, pair<int, int>>> q;
    for (int i = 1; i < N; ++i)
        q.push({mini[i] - mini[i-1], {mini[i] - mini[i-1], 1}});
    
    for (int k = 0; k < K; ++k) {
        auto cur = q.top(); q.pop();
        int orgVal = cur.second.first;
        int divCnt = cur.second.second + 1;
        int m = orgVal % divCnt ? 1 : 0;
        q.push({orgVal / divCnt + m, {orgVal, divCnt}});
    }
    
    return q.top().first;
}


int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d", &N, &K);
        vector<int> mini = vector<int>(N);
        for (int n = 0; n < N; ++n)
            scanf("%d", &mini[n]);
        printf("Case #%d: %d\n", tc + 1, solve(mini));
    }
}