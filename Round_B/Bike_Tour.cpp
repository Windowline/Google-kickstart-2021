#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;

int solve(vector<int>& p) {
    int ans = 0;
    for (int i = 1; i < p.size() - 1; ++i) {
        if (p[i] > p[i-1] && p[i] > p[i+1])
            ++ans;
    }
    return ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d", &N);
        vector<int> in = vector<int>(N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &in[i]);
        printf("Case #%d: %d\n", tc + 1, solve(in));
    }
}
