#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long int;
using ld = long double;
ll binpow(ll a, ll b) {
  ll res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
ll modmul(ll a, ll b) {
  ll res = 0;
  a %= 1000000007;
  while (b) {
    if (b & 1) {
      res = (res + a) % 1000000007;
    }
    a = (2 * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
struct union_find {
  vector<ll> data;
  ll components = 0;
  union_find(ll n = -1) {
    if (n >= 0) {
      init(n);
    }
  }
  void init(ll n) {
    data.assign(n + 1, -1);
    components = n;
  }
  ll find(ll x) {
    if (data[x] < 0) {
      return x;
    }
    return data[x] = find(data[x]);
  }
  ll get_size(ll x) { return -data[find(x)]; }
  bool unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    if (-data[x] < -data[y]) {
      swap(x, y);
    }
    data[x] += data[y];
    data[y] = x;
    components--;
    return true;
  }
};
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  int ind = -1;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '0') {
      ind = i;
    }
  }
  if (ind == -1) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
  } else if (ind < n / 2) {
    cout << ind + 1 << " " << n << " " << ind + 2 << " " << n << "\n";
  } else {
    cout << 1 << " " << ind + 1 << " " << 1 << " " << ind << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ll t = 1;
  cin >> t;
  for (ll i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
