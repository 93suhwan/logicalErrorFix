#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gas;
ll get_and(ll i, ll j) {
  gas--;
  assert(gas >= 0);
  cout << "and " << i + 1 << " " << j + 1 << "\n";
  cout.flush();
  ll x;
  cin >> x;
  if (x == -1) exit(0);
  return x;
}
ll get_or(ll i, ll j) {
  gas--;
  assert(gas >= 0);
  cout << "or " << i + 1 << " " << j + 1 << "\n";
  cout.flush();
  ll x;
  cin >> x;
  if (x == -1) exit(0);
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  gas = 2 * n;
  vector<ll> A(n), B(n);
  for (ll i = 1; i < n; i++) {
    A[i] = get_and(0, i);
  }
  for (ll i = 1; i < n; i++) {
    B[i] = get_or(0, i);
  }
  vector<ll> C(n);
  for (ll i = 1; i < n; i++) {
    C[i] = B[i] - A[i];
  }
  ll X = B[1] | B[2];
  ll Y = get_and(1, 2);
  for (ll b = 0; b < 33; b++) {
    bool b1 = A[1] & (1LL << b);
    bool b2 = A[2] & (1LL << b);
    bool b3 = Y & (1LL << b);
    if (b1 || b2 || b3) {
      X ^= (1LL << b);
    }
  }
  ll W = get_or(1, 2);
  ll Z = W - Y;
  ll a = X ^ Z;
  vector<ll> v;
  v.push_back(a);
  for (ll i = 1; i < n; i++) {
    v.push_back(a ^ C[i]);
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << "\n";
  cout.flush();
  return 0;
}
