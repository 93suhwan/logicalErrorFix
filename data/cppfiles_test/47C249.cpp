#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, SZ = 4e5 + 4;
long long n;
bool prime(long long n) {
  for (int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long a, long long b, long long m) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return power((a * a) % m, b / 2, m);
  return a * (power((a * a) % m, (b - 1) / 2, m)) % m;
}
inline void print(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}
void solve() {
  long long k;
  cin >> n >> k;
  vector<long long> a, b, c;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a.emplace_back(x);
    ;
    b.emplace_back(a[i]);
    c.emplace_back(-a[i]);
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  long long mi = upper_bound(b.begin(), b.end(), 0) - b.begin(),
            di = upper_bound(c.begin(), c.end(), 0) - c.begin();
  long long c1 = c[n - 1], c2 = b[n - 1];
  for (int i = n - 1; i >= mi; i -= k) {
    c1 += 2 * b[i];
  }
  for (int i = n - 1 - k; i >= di; i -= k) {
    c1 += 2 * c[i];
  }
  for (int i = n - 1; i >= di; i -= k) {
    c2 += 2 * c[i];
  }
  for (int i = n - 1 - k; i >= mi; i -= k) {
    c2 += 2 * b[i];
  }
  cout << min(c2, c1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int cases = 1;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
