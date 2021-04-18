#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, B;

//가능한 작은것 부터 카운팅
int solve(vector<int>& p) {
    
    sort(p.begin(), p.end());
    int ans = 0;
    int rem = B;
    for (int i = 0; i < N; ++i) {
        if (p[i] <= rem) {
            ans++;
            rem -= p[i];
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d", &N, &B);
        vector<int> price = vector<int>(N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &price[i]);
        
        int ans = solve(price);
        printf("Case #%d: %d\n", tc + 1, ans);
    }
    
    
}