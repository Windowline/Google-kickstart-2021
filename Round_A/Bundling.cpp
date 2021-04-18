#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int N, K, ans;

typedef struct data {
    data* child[26];
    int cnt;
}trie;

trie* root;

void insert(string& s) {
    trie* cur = root;
    for(char ch : s) {
        int idx = ch - 'A';
        if (!cur->child[idx])
            cur->child[idx] = new trie();
        cur = cur->child[idx];
    }
    cur->cnt++;
}

void dfs(trie* cur, int depth) {
    //하위 노드들중에서 아직 그루핑되지 않은 단어들의 총수를 집계한다.
    //(root~자신까지의 prefix를 갖고 아직 그루핑되지 않은 단어들의 총수)
    for (int i = 0; i <= 25; ++i) {
        if (cur->child[i]) {
            dfs(cur->child[i], depth + 1);
            cur->cnt += cur->child[i]->cnt;
        }
    }
    while (cur->cnt >= K) {
        cur->cnt -= K;
        ans += depth;
    }
}




void solve(vector<string>& str) {
    root = new trie();
    for (auto& s : str)
        insert(s);
    ans = 0;
    dfs(root, 0);
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