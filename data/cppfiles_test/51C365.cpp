#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long base_converter(string s, int k) {
  long long ans = 0;
  for (auto x : s) {
    ans *= k;
    ans += x - '0';
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  cout << -1 * (n - 1) << " " << n << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
