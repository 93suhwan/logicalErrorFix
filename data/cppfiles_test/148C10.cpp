#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 605;
const int LG = 20;
void solve() {
  int w, h;
  cin >> w >> h;
  ll ans = 0;
  auto read = [&]() {
    int k;
    cin >> k;
    int x1;
    cin >> x1;
    int x2;
    for (int _ = 0; _ < (k - 1); ++_) cin >> x2;
    return x2 - x1;
  };
  ans = max(ans, 1ll * read() * h);
  ans = max(ans, 1ll * read() * h);
  ans = max(ans, 1ll * read() * w);
  ans = max(ans, 1ll * read() * w);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
