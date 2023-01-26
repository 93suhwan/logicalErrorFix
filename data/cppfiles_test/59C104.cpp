#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void ioi(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
int n, c[10], d[10][10];
void solve() {
  cin >> n;
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++) c[i] = d[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> v;
    for (int j = 1; j <= 5; j++) {
      int x;
      cin >> x;
      if (x) v.push_back(j);
    }
    for (int j = 0; j < (int)v.size(); j++) {
      c[v[j]]++;
      for (int k = j + 1; k < (int)v.size(); k++) {
        d[v[j]][v[k]]++;
        d[v[k]][v[j]]++;
      }
    }
  }
  for (int i = 1; i <= 5; i++) {
    if (n / 2 <= c[i]) {
      for (int j = i + 1; j <= 5; j++) {
        if (n / 2 <= c[j] && c[i] + c[j] - d[i][j] >= n) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(10);
  ;
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
