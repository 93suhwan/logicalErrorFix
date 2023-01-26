#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long double PI = acos(-1);
const int M = 998244353;
int n, m, k, t, T;
long long ans;
int a, b;
map<int, int> mpx, mpy, mx, my;
map<pair<int, int>, int> X, Y;
vector<int> first, second;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a, first.push_back(a), mpx[a] = 1;
    for (int i = 1; i <= m; i++) cin >> a, second.push_back(a), mpy[a] = 1;
    for (int i = 1; i <= k; i++) {
      cin >> a >> b;
      if (mpx.find(a) != mpx.end()) {
        auto it = lower_bound(second.begin(), second.end(), b) - second.begin();
        if (b != second[it]) mx[it]++;
        ans -= X[{a, it}];
        X[{a, it}]++;
      } else {
        auto it = lower_bound(first.begin(), first.end(), a) - first.begin();
        if (a != first[it]) my[it]++;
        ans -= Y[{b, it}];
        Y[{b, it}]++;
      }
    }
    for (auto i : mx) {
      if (i.second >= 2) ans += i.second * (i.second - 1) / 2;
    }
    for (auto i : my) {
      if (i.second >= 2) ans += i.second * (i.second - 1) / 2;
    }
    cout << ans << '\n';
    mpx.clear();
    mpy.clear();
    mx.clear();
    my.clear();
    first.clear();
    second.clear();
    X.clear();
    Y.clear();
  }
  return 0;
}
