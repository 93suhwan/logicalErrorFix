#include <bits/stdc++.h>
using namespace std;
long long mx = 1e9;
void query(long long i, long long j) { cout << "? " << i << " " << j << endl; }
void solve() {
  long long d1, d2;
  query(1, 1);
  cin >> d1;
  if (d1 == -1) return;
  query(mx, 1);
  cin >> d2;
  if (d2 == -1) return;
  long long x = (d1 + mx - d2 + 1) / 2;
  query(x, 1);
  long long dbot;
  cin >> dbot;
  if (dbot == -1) return;
  query(x, mx);
  long long dtop;
  cin >> dtop;
  if (dtop == -1) return;
  long long d3;
  query(mx, mx);
  cin >> d3;
  if (d3 == -1) return;
  long long x1, y1, x2, y2;
  x1 = d1 - dbot + 1;
  y1 = dbot + 1;
  x2 = mx + dtop - d3;
  y2 = mx - dtop;
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool _multipleTestCases = false;
  if (_multipleTestCases) {
    long long t;
    cin >> t;
    while (t--) solve();
  } else {
    solve();
  }
  return 0;
}
