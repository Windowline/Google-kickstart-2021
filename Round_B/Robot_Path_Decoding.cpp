#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
typedef long long LL;
using namespace std;
const LL END = 1e9;

LL adjust(LL v) {
    if (v <= 0)
        v += END;
    if (v > END)
        v %= END;
    return v;
}

class Data {
public:
    void add(Data& a, int repeat) {
        dy = adjust(dy + a.dy * repeat);
        dx = adjust(dx + a.dx * repeat);
    }
    
    void add(char d) {
        if (d == 'N')
            dy--;
        else if (d == 'S')
            dy++;
        else if (d == 'E')
            dx++;
        else
            dx--;
        dy = adjust(dy);
        dx = adjust(dx);
    }

    LL dx = 0;
    LL dy = 0;
};

bool isd(char c) {
    return '0' <= c && c <= '9';
}

Data parse(int start, int& end, string& s) {
    Data ret;
    int i = start;
    while ((i < s.size() && s[i] != ')')) {
        if (isd(s[i])) {
            int repeat = s[i] - '0';
            int end;
            auto tmp = parse(i + 2, end, s);
            ret.add(tmp, repeat);
            i = end;
        } else {
            ret.add(s[i++]);
        }
    }
    end = i + 1;
    return ret;
}

pair<int, int> solve(string& s) {
    string in = "1(" + s + ")";
    int end;
    Data data = parse(0, end, in);
    return {adjust(data.dx + 1), adjust(data.dy + 1)};
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        string s;
        cin >> s;
        auto ans = solve(s);
        printf("Case #%d: %d %d\n", tc, ans.first, ans.second);
    }
}
