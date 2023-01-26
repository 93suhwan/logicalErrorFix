#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 42
#endif
void _debug() {
    std::cerr << std::endl;
}
template <typename T, typename... U> void _debug(T t, U... args) {
    std::cerr << " " << t;
    _debug(args...);
}

const int maxn = 2e5 + 10;

int n, a[maxn];

map<int, int> id;
int cnt;
map<int, pair<int, int>> mp[maxn * 40];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        int pre = 2e9, step = 0, now = a[i];
        for (; now != 0; step++) {
            if (!id.count(now)) id[now] = cnt++;
            int _id = id[now];
            mp[_id][pre] = max(make_pair(step, i), mp[_id][pre]);
            pre = now;
            int _2k = (1 << (31 - __builtin_clz(now)));
            if (_2k < now) _2k <<= 1;
            now = _2k - now;
        }
        mp[0][pre] = {step, i};
    }
    int ans = 0;
    pii pr;
    for (int i = 0; i < cnt; i++) {
        if (mp[i].size() < 2) continue;
        vector<pii> vec;
        vec.reserve(mp[i].size());
        for (const auto& [k, v] : mp[i]) {
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end(), [&](auto l, auto r) {
            return l.first > r.first;
        });
        if (vec[0].first + vec[1].first > ans) {
            ans = vec[0].first + vec[1].first;
            pr = {vec[0].second, vec[1].second};
        }
    }
    printf("%d %d %d\n", pr.first, pr.second, ans);
}