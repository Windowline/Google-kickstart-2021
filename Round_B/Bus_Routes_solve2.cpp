#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

typedef long long LL;

using namespace std;

int N;
LL D;


//greedy
//1. 마지막배열이 D를 상한으로 최대한 늦게 타는 a를 구한다.
//2. D대신 a를 상한으로 반복
LL solve(vector<LL>& p) {
    LL limit = D;
    for (int i = p.size() - 1; i >= 0; --i) {
        LL x = p[i];
        limit = limit / x * x; // limit이하의 가장 큰 x의 배수를 구한다. floor(limit/x) * x
    }
    return limit;
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%d %lld", &N, &D);
        vector<LL> in = vector<LL>(N);
        for (int i = 0; i < N; ++i)
            scanf("%lld", &in[i]);
        printf("Case #%d: %lld\n", tc, solve(in));
    }
}
