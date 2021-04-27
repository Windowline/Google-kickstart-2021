#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

typedef long long LL;

using namespace std;

int N;
LL D;

bool q(LL v, vector<LL>& in) { // v 출발날짜
    LL a = v;
    for (auto x : in)
        a = (a + x - 1) / x * x; //a이상인 가장작은 x배수(a+x-1이하의 가장큰 x의 배수) --> floor(a+x-1) * x 추측: a + x 미만의 가장 큰 x 배수.
    return a <= D;
}

LL solve(vector<LL>& p) {
    LL l = 1, h = D;
    while (l < h) {
        LL m = (l + h + 1) / 2;
        if (q(m, p))
            l = m;
        else
            h = m - 1;
    }
    return l;
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
