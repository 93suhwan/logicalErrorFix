#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template <typename U>
void print(U arr) {
  for (auto element : arr) {
    cout << element << " ";
  }
  cout << '\n';
}
void setup(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int M = 1e9 + 7;
void solve() {
  long long int i, n, x, y, a, b, c, sam = 0;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> vp;
  for (ll i = 0; i < n; i++) {
    cin >> a;
    pair<pair<ll, ll>, ll> p;
    p.first.first = a;
    vp.push_back(p);
  }
  for (ll i = 0; i < n; i++) {
    cin >> b;
    vp[i].first.second = b;
  }
  for (i = 0; i < n; ++i) {
    vp[i].second = i;
  }
  sort(begin(vp), end(vp));
  vector<bool> ans(n, 0);
  ans[vp[vp.size() - 1].second] = 1;
  ll minwin = vp[vp.size() - 1].first.second;
  ll j = n - 1;
  for (i = n - 2; i >= 0; i--) {
    if (vp[i].first.second > minwin) {
      for (int t = i; t < j; t++) {
        ans[vp[t].second] = 1;
        minwin = min(minwin, vp[t].first.second);
      }
      j = i;
    }
  }
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << '\n';
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
