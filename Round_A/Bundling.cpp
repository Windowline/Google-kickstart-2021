#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int N, K, ans;

class Trie {
    public:
    int cnt;
    Trie next[26] = {nullptr, };
};

Trie* root = nullptr;

void insert(string& s) {
    Trie* cur = root;
    for (int i = 0; i < s.size(); ++i) {
        int idx = s[i] - 'A';
        if (!cur->next[idx])
            cur->next[idx] = new Trie();
        cur = cur->next[idx];
    }
    cur->cnt++;
}

void dfs(Trie* cur, int depth) {
    for (int i = 0; i <= 25; ++i) {
        if (cur->next[i]) {
            dfs(cur->next[i], depth + 1);
            cur->cnt += cur->next[i]->cnt;
        }
    }
    while (cur->cnt <= K) {
        ans += (depth * K);
        cur->cnt -= K;
    }
}

void solve(vector<string>& str) {
    root = new Trie();
    ans = 0;
    for (auto& s : str)
        insert(s);
    dfs(root, 0);
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int TC;
    scanf("%d", &TC);
    
    for (int tc = 0; tc < TC; ++tc) {
        scanf("%d %d", &N, &K);
        vector<string> in(N);
        for (int i = 0; i < N; ++i) {
            cin >> in[i];
        }
        solve(in);
        printf("Case #%d: %d\n",tc + 1, ans);
    }
    return 0;
}