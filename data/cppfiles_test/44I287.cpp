#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
ll lwb(vector<T>& a, const T& b) {
  return lower_bound(a.begin(), a.end(), b) - a.begin();
}
template <class T>
ll upb(vector<T>& a, const T& b) {
  return upper_bound(a.begin(), a.end(), b) - a.begin();
}
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void setIO(str second) {
  setIn(second + ".inp");
  setOut(second + ".out");
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
ll pow_mod(ll a, ll b, ll m) {
  ll res = 1;
  while (b) {
    res = res * (b & 1 ? a : 1) % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll inv(ll a, ll m) { return pow_mod(a, m - 2, m); }
ll nxt(void) {
  ll x;
  cin >> x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll TC = nxt();
  while (TC--) {
    ll c, d;
    cin >> c >> d;
    if (abs(c - d) % 2) {
      cout << "-1\n";
      continue;
    }
    cout << (c != 0) + (c != d) << '\n';
  }
  return 0;
}
