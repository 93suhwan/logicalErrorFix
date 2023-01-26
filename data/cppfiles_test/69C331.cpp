#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vvpl = vector<vpl>;
const ll MOD = 1000000007;
const ll MOD9 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const ll dy[9] = {0, 1, -1, 0, 1, 1, -1, -1, 0};
const ll dx[9] = {1, 0, 0, -1, 1, -1, 1, -1, 0};
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ll t;
  cin >> t;
  vector<string> vs(61);
  for (ll i = 0; i < 61; i++) {
    vs[i] = to_string(1LL << i);
  }
  while (t--) {
    string s;
    cin >> s;
    ll ans = INF;
    ll n = s.size();
    for (auto t : vs) {
      ll now = 0;
      for (ll i = 0; i < n; i++) {
        if (now < t.size() && t[now] == s[i]) now++;
      }
      ll ret = n + t.size() - now * 2;
      chmin(ans, ret);
    }
    cout << ans << endl;
  }
}
