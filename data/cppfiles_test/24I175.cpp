#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long long mod = 1e9 + 7;
long long n, m, k;
double r, a, b, h;
void solve() {
  cin >> n;
  if (n < 10)
    cout << n / 9 << endl;
  else {
    cout << n / 10 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
