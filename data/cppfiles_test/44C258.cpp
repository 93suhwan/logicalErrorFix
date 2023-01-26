#include <bits/stdc++.h>
using namespace std;
void ifdef() {}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
auto cmp = [](long long a, long long b) { return a > b; };
void solve() {
  long long c, d;
  cin >> c >> d;
  if ((abs(c - d)) % 2 != 0) {
    cout << "-1\n";
    return;
  }
  if (c == 0 && d == 0) {
    cout << "0\n";
    return;
  }
  if (c == d) {
    cout << "1\n";
    return;
  }
  cout << "2\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ifdef();
  long long ttt = 1;
  cin >> ttt;
  while (ttt--) {
    solve();
  }
  return 0;
}
