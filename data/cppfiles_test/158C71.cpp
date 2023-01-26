#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
vpii cost(10000);
vi inv(10000);
vi perm(10000);
inline void __run_test() {
  int n, m;
  cin >> n >> m;
  vi x(n);
  vector<string> d(n);
  for (int i = 0; i < (n); i++) cin >> x[i];
  for (int i = 0; i < (n); i++) cin >> d[i];
  long long val = -1;
  for (int i = 0; i < (m); i++) cost[i].second = i;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < (m); i++) cost[i].first = 0;
    sort(cost.begin(), cost.begin() + m,
         [&](pii a, pii b) -> bool { return a.second < b.second; });
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (m); j++)
        if (d[i][j] == '1') cost[j].first += (mask & (1 << i)) ? 1 : -1;
    sort(cost.begin(), cost.begin() + m);
    for (int i = 0; i < (m); i++) inv[cost[i].second] = i + 1;
    long long now = 0;
    for (int i = 0; i < (n); i++) {
      long long r = 0;
      for (int j = 0; j < (m); j++)
        if (d[i][j] == '1') r += inv[j];
      now += abs(x[i] - r);
    }
    if (now > val) {
      val = now;
      for (int i = 0; i < (m); i++) perm[i] = inv[i];
    }
  }
  for (int i = 0; i < (m); i++) cout << perm[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __tests;
  cin >> __tests;
  while (__tests--) __run_test();
}
