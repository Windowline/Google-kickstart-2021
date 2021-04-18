#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;

// 최적화 문제로 푼다.
// 알아내고자 하는 답(difficulty)를 대입해보며, 최적의 답에 접근
// f(d): difficulty를 d로 정했을 때, 필요한 최소 세션수(<= K)
// difficulty란 각 diff들 사이에 세션 추가시 발생하는 가장 큰 수
// 목표로 하는 d가 낮을수록 --> f(d)는 커진다
// 목표로 하는 d가 높을수록 --> f(d)는 작아진다.
// 최적의 d를 찾기 위해서, 어떤 d를 정하여 f(d)의 값을 얻었을 때, 두가지 경우를 고려해볼 수 있다.
// 1. f(d)가 해의 영역일 때 (f(d) <= K):    더 좋은 답을 찾아본다. 즉, d를 낮춰도 좋을지 본다. (f(d)를 조금 키워도 괜찮을지 살핀다.)
// 2. f(d)가 해의 영역일 밖일 때 (f(d) > K): 해의 영역안에 들어갈 수 있도록 d를 높힌다. (f(d)를 작게 한다.)
// 결국 최적의 답이 나올 때까지 d를 내릴 것이냐 올릴 것이냐의 문제다. --> 이분탐색. 시간복잡도는 O(log1e9 * N) => O(N)

bool ok(vector<int>& diffs, int d) { //f(d)가 해의 영역인지?
    int cnt = 0;
    for (auto diff : diffs) {
        int m = diff % d ? 1 : 0;
        int v = diff / d + m - 1;
        cnt += v;
    }
    //여기서 cnt는 f(d)이다.
    return cnt <= K;
}

int solve(vector<int>& mini) {
    vector<int> diffs;
    for (int i = 1; i < mini.size(); ++i) {
        diffs.push_back(mini[i] - mini[i-1]);
    }
    
    int left = 1;
    int right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2;
        if (ok(diffs, mid)) { 
            right = mid; // mid 영역이므로 mid를 낮춰보며, mid 또한 다음 탐색영역에 포함되어야 하므로 1을 빼지 않는다.
        } else {
            left = mid + 1;
        }
    }
    return right;
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
