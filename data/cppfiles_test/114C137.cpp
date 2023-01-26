#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
ll bpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool cmp(vector<ll> v1, vector<ll> v2) { return v1[1] < v2[1]; }
ll power(ll x, ll y) {
  ll result = 1;
  while (y > 0) {
    if (y % 2 == 0) {
      x = x * x;
      y = y / 2;
    } else {
      result = result * x;
      y = y - 1;
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    ll count = 0;
    ll tar = n / 2;
    for (int i = 1; i < n; i++) {
      cout << a[i] << " " << a[0] << endl;
      count++;
      if (count == tar) break;
    }
  }
}
