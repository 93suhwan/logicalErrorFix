#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const long long int MOD = 1e9 + 7;
long long int div_floor(const long long int &a, const long long int &b) {
  return a / b - (((a ^ b) < 0) and a % b);
}
long long int div_ceil(const long long int &a, const long long int &b) {
  return a / b + (((a ^ b) >= 0) and a % b);
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long int binpow(long long int a, long long int b, long long int p) {
  long long int res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}
bool check(vector<long long int> &m, long long int mid, long long int n) {
  bool ok = 1;
  long long int ind = n - mid;
  for (long long int i = 0; i < mid; i++) {
    if (m[i] >= m[ind]) {
      ok = 0;
    }
    ind++;
  }
  return ok;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  multiset<long long int> m;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    m.insert(x);
  }
  long long int ans = 0;
  for (long long int i = 0; i < n - 2 * k; i++) {
    auto it = m.begin();
    ans += *it;
    m.erase(it);
  }
  vector<long long int> temp;
  for (auto it : m) temp.push_back(it);
  long long int l = 0, r = k, mid, add = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(temp, mid, (long long int)temp.size())) {
      l = mid + 1;
      add = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans + (k - add) << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
