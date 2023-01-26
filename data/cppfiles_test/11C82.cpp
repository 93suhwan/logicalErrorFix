#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
long long mod = 1e9 + 7;
long double eps = 1e-12;
long double pi = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uc = unsigned char;
using us = unsigned short;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= i + 1) b.push_back({i + 1 - a[i], a[i]});
    a[i] = i + 1 - a[i];
  }
  sort(b.begin(), b.end());
  if (b.size() == 0) {
    cout << 0;
    return;
  }
  vector<int> ans(1, b[0].second);
  for (int i = 1; i < b.size(); i++) {
    int id = lower_bound(ans.begin(), ans.end(), b[i].second) - ans.begin();
    if (id == ans.size()) {
      ans.push_back(b[i].second);
    } else {
      ans[id] = b[i].second;
    }
  }
  cout << ans.size();
}
int main() {
  cout << setprecision(20) << fixed;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t t1 = clock();
  int t = 1;
  int cs = 1;
  while (t--) {
    solve();
  }
  return 0;
}
