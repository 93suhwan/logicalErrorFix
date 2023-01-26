#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll pw(ll b, ll p) {
  p %= mod - 1;
  if (p == 0) return 1;
  if (p < 0) return pw(b, p + mod - 1);
  return (pw((b * b) % mod, p >> 1) * (p & 1 ? b : 1)) % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    set<ll> st;
    if (rb <= rd) {
      for (int i = 0; i < 2 * (m - 1); i++) {
        st.insert(2 * i * (n - 1) + (rd - rb));
        st.insert(2 * i * (n - 1) + (2 * n - rd - rb));
      }
    } else {
      for (int i = 0; i < 2 * (m - 1); i++) {
        st.insert(2 * i * (n - 1) + (2 * n - rb - rd));
        st.insert(2 * i * (n - 1) + (2 * n - rb + rd - 2));
      }
    }
    if (cb <= cd) {
      for (int i = 0; i < 2 * (n - 1); i++) {
        st.insert(2 * i * (m - 1) + (cd - cb));
        st.insert(2 * i * (m - 1) + (2 * m - cd - cb));
      }
    } else {
      for (int i = 0; i < 2 * (n - 1); i++) {
        st.insert(2 * i * (m - 1) + (2 * m - cb - cd));
        st.insert(2 * i * (m - 1) + (2 * m - cb + cd - 2));
      }
    }
    ll res = 0, sum = 0, id = 0;
    if (st.count(4 * (n - 1) * (m - 1))) st.erase(4 * (n - 1) * (m - 1));
    for (int u : st) {
      ll curr = pw(100 - p, id) * pw(100, -id) % mod;
      ll base = p * pw(100, -1) % mod;
      curr = curr * base % mod;
      sum = (sum + curr) % mod;
      res = (res + u * curr) % mod;
      id++;
    }
    res += (mod + 1 - sum) * (4 * (n - 1) * (m - 1) % mod) % mod;
    cout << res * pw(sum, -1) % mod << '\n';
  }
}
