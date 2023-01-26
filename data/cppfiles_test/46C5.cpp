#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9;
long long int power(long long int a, long long int b) {
  long long int p = 1;
  while (b > 0) {
    if (b & 1) p = (p * a);
    a = (a * a);
    b >>= 1;
  }
  return p;
}
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (auto &i : a) cin >> i;
  long long int ans = 0;
  long long int max = a[n - 1];
  for (long long int i = n - 2; i >= 0; i--) {
    if (a[i] > max) {
      max = a[i];
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  fast_io();
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
