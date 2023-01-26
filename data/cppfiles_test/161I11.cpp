#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define len(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &i : a)
        in >> i;
    return in;
}

template<class T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &i : a)
        out << i << ' ';
    return out;
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
    int cnt1 = a.second - a.first + 1;
    int cnt2 = b.second - b.first + 1;
    if (cnt1 != cnt2) {
        return cnt1 > cnt2;
    } else {
        return a.first < b.first;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a)cin >> i.first >> i.second;
    sort(all(a), comp);
    vector<int> add(n+2);
    for (auto &i : a){
        add[i.first]++;
        add[i.second+1]--;
    }
    for (int i =1;i <= n;++i){
        add[i] += add[i-1];
    }
    vector<pair<int,int>> cnt;
    for (int i = 1;i<=n;++i){
        cnt.emplace_back(make_pair(add[i],i));
    }
    sort(all(cnt));
    for (int i = 0;i < n;++i){
        cout << a[i].first << " " << a[i].second  << " " << cnt[i].second << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}