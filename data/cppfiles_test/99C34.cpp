#include <bits/stdc++.h>
using namespace std;
void invector(vector<long long> p) {
  cout << " in p : ";
  for (auto x : p) {
    cout << x << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long x, n;
  cin >> x >> n;
  long long ans = 0;
  if (n % 4 == 0) {
    ans = 0;
  } else if (n % 4 == 1) {
    ans = -n;
  } else if (n % 4 == 2) {
    ans = 1;
  } else {
    ans = 1 + n;
  }
  if (x % 2 == 0)
    x += ans;
  else {
    x -= ans;
  }
  cout << x << "\n";
}
signed main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
