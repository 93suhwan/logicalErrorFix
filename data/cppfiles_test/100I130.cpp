#include <bits/stdc++.h>
const int N = 1e5;
const int inf = 1e9 + 10;
using namespace std;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
map<long long int, long long int> cnt;
void prime_factorization(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      ++cnt[i];
    }
  }
  if (n > 1) ++cnt[n];
}
void solve() {
  long long int x, y, a, b;
  cin >> x >> y;
  a = x, b = y;
  if (x > y) {
    cout << x + y;
    return;
  }
  if (x == y) {
    cout << x;
    return;
  }
  if (y % x == 0) {
    cout << x;
    return;
  }
  cout << (y / x) * x + (y % x) / 2;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
      cout << a[1] << endl;
    else {
      long long int cross = 0, mn = a[1], second = 0, ans = a[1];
      sort(a + 1, a + n + 1);
      for (int i = 2; i <= n; i++) {
        second += mn;
        mn = a[i] - second;
        a[i] = mn;
        ans = max(mn, ans);
      }
      sort(a + 1, a + n + 1);
      cout << ans;
      cout << endl;
    }
  }
}
