#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a < b) return gcd(a, b % a);
  return gcd(b, a % b);
}
bool isperfect(double n) {
  if (n >= 0) {
    long long x = sqrt(n);
    return (x * x == n);
  } else
    return false;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0, c;
  while (!is_sorted(a + 1, a + n + 1)) {
    ans++;
    c = ans % 2;
    for (int j = 2 - c; j <= n - 1 - c; j += 2) {
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
  }
  cout << ans << endl;
}
int main() {
  std ::ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(10);
  long long t;
  cin >> t;
  while (t--) solve();
}
