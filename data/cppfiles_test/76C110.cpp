#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mxn = 2e5 + 5;
ll n, m;
ll t[mxn];
ll sum(int k) {
  ll second = 0;
  while (k >= 1) {
    second = (second + t[k]) % m;
    k -= k & -k;
  }
  return second;
}
void update(int k, ll x) {
  while (k <= n) {
    t[k] = (t[k] + x) % m;
    k += k & -k;
  }
}
ll qry(int l, int r) { return ((sum(r) - sum(l - 1)) % m + m) % m; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  update(n, 1);
  for (int i = n - 1; i >= 1; --i) {
    update(i, qry(i + 1, n));
    for (ll j = 2; i * j <= n; ++j) {
      update(i, qry(i * j, min(n, (i + 1) * j - 1)));
    }
  }
  cout << qry(1, 1) << '\n';
}
