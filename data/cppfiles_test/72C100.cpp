#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
inline ll bit(ll x, ll y) { return (x & (1ll << y)); }
const ll mod = 998244353;
const ll N = 2e5 + 5;
const ll base = 31;
ll dd[20];
ll kq[20];
ll n, cnt = 0;
string st;
ll k, cur = 0;
void down(ll i) {
  if (dd[kq[i]] == 1) cnt--;
  dd[kq[i]]--;
  if (kq[i] == 9) {
    down(i - 1);
  } else {
    st[i] = char(ll((st[i] - '0') + 1) + '0');
    for (ll j = i + 1; j <= n; j++) st[j] = '0';
    cur = i - 1;
  }
  return;
}
void check(ll i) {
  ll x = st[i] - '0';
  if (dd[x]) {
    kq[i] = x;
    dd[x]++;
    return;
  }
  if (cnt < k) {
    kq[i] = st[i] - '0';
    if (dd[kq[i]] == 0) cnt++;
    dd[kq[i]]++;
    return;
  }
  bool kt = false;
  for (ll j = x; j <= 9; j++)
    if (dd[j]) {
      kt = true;
      kq[i] = j;
      dd[j]++;
      for (ll k = i + 1; k <= n; k++) st[k] = '0';
      return;
    }
  if (kt == false) {
    down(i - 1);
    return;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    cin >> st >> k;
    for (ll i = 0; i <= 9; i++) {
      dd[i] = 0;
      kq[i] = 0;
    }
    cnt = 0;
    cur = 1;
    n = st.size();
    st = ' ' + st;
    while (cur <= n) {
      check(cur);
      cur++;
    }
    for (ll i = 1; i <= n; i++) cout << kq[i];
    cout << endl;
  }
}
