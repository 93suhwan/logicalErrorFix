#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  if (n < 0) {
    cout << n << " " << abs(n) - 1 << '\n';
    return;
  }
  long long x = n - 1;
  cout << (-x) << " " << n << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
