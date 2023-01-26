#include <bits/stdc++.h>
using namespace std;
const long long int hell = 1e9 + 7;
const long long int inf = 1e18;
const long long int MIN = -1e18;
long long int gcdfun(long long int x, long long int y) {
  if (y == 0)
    return x;
  else
    return gcdfun(y, x % y);
}
long long int mul(long long int a, long long int b) { return (a * b) % hell; }
long long int sum(long long int a, long long int b) { return (a + b) % hell; }
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int p = power(a, n / 2);
  p = mul(p, p);
  if (n & 1) p = mul(p, a);
  return p;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i += 1) cin >> v[i];
  sort(v.begin(), v.end());
  long long int score = 0, remaining = n - 2 * k;
  for (long long int i = 0; i < remaining; i += 1) score += v[i];
  for (long long int i = remaining; i < n; i += 2) {
    if (v[n - 1] > v[i]) {
      long long int idx = upper_bound(v.begin() + i, v.end(), v[i]) - v.begin();
      v[idx] = v[i];
      sort(v.begin() + remaining, v.end());
    } else {
      score += (n - i) / 2;
      break;
    }
  }
  cout << score;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tits = 1;
  cin >> tits;
  for (long long int i = 0; i < tits; i += 1) {
    solve();
    cout << '\n';
  }
}
