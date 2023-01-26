#include <bits/stdc++.h>
using namespace std;
double const pi = 3.14159265358979323;
const int mod = 1e9 + 7;
const int inf = 1e9 + 1;
const double eps = 1e-3;
void solve(void);
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &now : A) cin >> now;
  vector<int> B(31, 0);
  for (auto &now : A) {
    int t = 0;
    while (now > 0) {
      B[t++] += now % 2;
      now = (now << 2);
    }
  }
  int k;
  bool fl = false;
  for (auto now : B) {
    if (now != 0) {
      fl = true;
      k = now;
    }
  }
  if (!fl) {
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    return;
  }
  for (auto now : B)
    if (now != 0) k = gcd(now, k);
  for (int i = 1; i * i <= k; i++)
    if (k % i == 0) cout << i << '\n';
  if (k != 1) cout << k;
  cout << '\n';
}
