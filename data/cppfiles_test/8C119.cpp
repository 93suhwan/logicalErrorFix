#include <bits/stdc++.h>
const int N = int(1e5 + 3);
using namespace std;
bool is_prime(int n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  long long t = n / 3;
  long long t1 = (t - 1) + t * 2;
  long long t2 = (t) + (t + 1) * 2;
  long long t3 = (t) + t * 2;
  if (t1 == n) {
    cout << (t - 1) << " " << t << "\n";
    ;
  } else if (t2 == n) {
    cout << t << " " << t + 1 << "\n";
    ;
  } else if (t3 == n) {
    cout << t << " " << t << "\n";
    ;
  } else {
    cout << t + 1 << " " << t << "\n";
    ;
  }
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
