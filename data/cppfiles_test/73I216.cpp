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
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  while (1) {
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        c++;
      }
    }
    ans += c;
    if (c == 0) break;
  }
  if (ans >= n)
    cout << ans / 2 << endl;
  else
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
