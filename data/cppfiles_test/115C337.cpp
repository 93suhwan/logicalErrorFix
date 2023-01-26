#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pll = pair<ll, ll>;
using pi = pair<int, int>;
void setIO(string name = "") {
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
ll n, h;
vector<ll> arr;
bool good(ll k) {
  ll sum = 0;
  sum += k;
  ll st = arr[0];
  ll en = arr[0] + k;
  for (int i = 1; i < n; i++) {
    sum -= max(0LL, en - arr[i]);
    st = arr[i];
    en = arr[i] + k;
    sum += k;
  }
  return sum >= h;
}
void solve() {
  cin >> n >> h;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll l = 0, r = 2 * arr[0] + h;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (good(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
