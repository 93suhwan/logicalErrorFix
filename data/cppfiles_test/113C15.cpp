#include <bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (name.length()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
long long digits(long long n) {
  int count = 0;
  while (n > 0) {
    count++;
    n /= 10;
  }
  return count;
}
long long fdigit(long long n) {
  long long k;
  while (n > 0) {
    k = n % 10;
    n /= 10;
  }
  return k;
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long a = digits(x1) + p1;
  long long b = digits(x2) + p2;
  if (a > b)
    cout << ">"
         << "\n";
  else if (a < b)
    cout << "<"
         << "\n";
  else if (a == b) {
    while (to_string(x1).size() < to_string(x2).size()) {
      x1 *= 10;
    }
    while (to_string(x2).size() < to_string(x1).size()) {
      x2 *= 10;
    }
    if (x1 > x2)
      cout << ">" << '\n';
    else if (x1 < x2)
      cout << "<"
           << "\n";
    else
      cout << "="
           << "\n";
  }
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
