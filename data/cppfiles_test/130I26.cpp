#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 3e5 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ntest, n;
int d[N], p[2], ret[N];
void Print(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> ntest;
  while (ntest--) {
    cin >> n;
    int pos = 1;
    for (int i = 1; i <= n; i += 3) {
      Print(i, i + 1, i + 2);
      cin >> d[i];
      if (i > 1 && d[i] != d[i - 3]) pos = i - 3;
    }
    for (int _ = pos + 1, __ = pos + 2, i = _; i <= __; i++) {
      Print(i, i + 1, i + 2);
      cin >> d[i];
    }
    for (int _ = pos, __ = pos + 2, i = _; i <= __; i++) {
      if (d[i] == d[i + 1]) continue;
      p[d[i]] = i, p[d[i + 1]] = i + 3;
      ret[i] = d[i];
      ret[i + 3] = d[i + 1];
    }
    for (int i = 1; i <= n; i += 3) {
      if (d[i] == 1) {
        Print(i, i + 1, p[0]);
        int x;
        cin >> x;
        if (x == 1) {
          ret[i] = ret[i + 1] = 1;
          Print(p[0], p[1], i + 2);
          int val;
          cin >> val;
          ret[i + 2] = val;
        } else {
          ret[i + 2] = 1;
          Print(p[0], p[1], i);
          int val;
          cin >> val;
          ret[i] = val;
          ret[i + 1] = 1 - val;
        }
      } else {
        Print(i, i + 1, p[1]);
        int x;
        cin >> x;
        if (x == 0) {
          ret[i] = ret[i + 1] = 0;
          Print(p[0], p[1], i + 2);
          int val;
          cin >> val;
          ret[i + 2] = val;
        } else {
          ret[i + 2] = 0;
          Print(p[0], p[1], i);
          int val;
          cin >> val;
          ret[i] = val;
          ret[i + 1] = 1 - val;
        }
      }
    }
    vector<int> v;
    for (int _ = 1, __ = n, i = _; i <= __; i++)
      if (ret[i] == 0) v.push_back(i);
    cout << "! " << v.size() << " ";
    for (auto x : v) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
