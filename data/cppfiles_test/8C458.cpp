#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long mod(long long x) { return (x % M + M) % M; }
long long mul(long long a, long long b) { return mod((mod(a) * mod(b))); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
void solve() {
  int n;
  cin >> n;
  int part = n / 3;
  int diff = 100;
  int a, b;
  for (int i = part; i <= part + 3; i++) {
    int B = n - i;
    if (B % 2 == 0) {
      int part2 = B / 2;
      if (i >= 0 && part2 >= 0 && abs(i - part2) < diff) {
        diff = abs(i - part2);
        a = i;
        b = part2;
      }
    }
  }
  for (int i = part - 3; i >= 0, i <= part; i++) {
    int B = n - i;
    if (B % 2 == 0) {
      int part2 = B / 2;
      if (i >= 0 && part2 >= 0 && abs(i - part2) < diff) {
        diff = abs(i - part2);
        a = i;
        b = part2;
      }
    }
  }
  cout << a << " " << b << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
