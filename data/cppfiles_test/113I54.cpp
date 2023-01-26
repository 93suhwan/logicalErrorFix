#include <bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (name.length()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long a = x1 * pow(10, p1);
  long long b = x2 * pow(10, p2);
  if (a > b)
    cout << ">"
         << "\n";
  else if (a < b)
    cout << "<"
         << "\n";
  else
    cout << "="
         << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("");
  int T = clock();
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  cerr << "\nTIME: " << (long double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
  T = clock();
  return 0;
}
