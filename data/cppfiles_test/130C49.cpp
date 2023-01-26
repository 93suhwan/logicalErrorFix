#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;
bool query(int a, int b, int c) {
  cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
  int r;
  cin >> r;
  if (r == -1) exit(0);
  return (r == 1);
}
void answer(vector<int> a) {
  cout << "! " << a.size() << ' ';
  for (auto x : a) cout << x + 1 << ' ';
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  int x = -1, y = -1;
  vector<int> b(n, -1);
  for (int i = 0; i < n; i += 3) {
    if (b[i] = query(i, i + 1, i + 2))
      y = i;
    else
      x = i;
  }
  int fr = -1, inv = -1;
  for (int i = y; i < y + 3; i++) {
    if (query(x, x + 1, i)) fr = i;
  }
  if (fr == -1) {
    inv = x;
    for (int i = y; i < y + 3; i++) {
      if (query(inv, i == y ? y + 1 : y, i == y + 2 ? y + 1 : y + 2))
        fr = (i == y ? y + 1 : y);
    }
  } else {
    for (int i = x; i < x + 3; i++) {
      if (!query(fr, i == x ? x + 1 : x, i == x + 2 ? x + 1 : x + 2))
        inv = (i == x ? x + 1 : x);
    }
  }
  vector<int> a;
  for (int i = 0; i < n; i += 3) {
    if (x == i || y == i) {
      for (int j = i; j < i + 3; j++) {
        if (j == inv || j != fr && !query(inv, fr, j)) a.push_back(j);
      }
    } else if (b[i] == 0) {
      bool res = query(fr, i, i + 1);
      if (res) {
        if (query(inv, fr, i))
          a.push_back(i + 1);
        else
          a.push_back(i);
        a.push_back(i + 2);
      } else {
        a.push_back(i);
        a.push_back(i + 1);
        if (!query(inv, fr, i + 2)) a.push_back(i + 2);
      }
    } else {
      bool res = query(inv, i, i + 1);
      if (res) {
        if (!query(inv, fr, i + 2)) a.push_back(i + 2);
      } else {
        if (query(inv, fr, i))
          a.push_back(i + 1);
        else
          a.push_back(i);
      }
    }
  }
  answer(a);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
