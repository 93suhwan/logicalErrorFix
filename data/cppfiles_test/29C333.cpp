#include <bits/stdc++.h>
using namespace std;
vector<long long> p(61, 1);
void pre() {
  for (int i = 1; i <= 60; i++) {
    p[i] = p[i - 1] * 2;
  }
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] == 1) one++;
    if (a[i] == 0) zero++;
  }
  cout << (1ll << zero) * (long long)one << "\n";
}
int main() {
  pre();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
