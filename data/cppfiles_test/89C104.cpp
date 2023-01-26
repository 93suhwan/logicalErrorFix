#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 998244353;
const ll INF = 1e18;
ll dfs(ll s, ll t, mat &G, vec &A, vec &B, ll &ans) {
  ll a = 1, b = 0;
  for (long long i = 0; i < (G.at(s).size()); ++i) {
    if (G.at(s).at(i) == t) continue;
    a *= dfs(G.at(s).at(i), s, G, A, B, ans);
    b++;
  }
  if (b == 0) {
    ans++;
    B.at(s) = 1;
  } else if (s != 0 && a == 1) {
    ans--;
    A.at(s) = 1;
    B.at(s) = 1;
    a = 0;
  } else {
    ll c = 1, d = 1;
    for (long long i = 0; i < (G.at(s).size()); ++i) {
      if (G.at(s).at(i) == t) continue;
      c *= A.at(G.at(s).at(i));
      d *= B.at(G.at(s).at(i));
    }
    ans += c;
    if (s != 0) ans -= d - c;
    a = c;
    A.at(s) = d - c;
    B.at(s) = d;
  }
  return a;
}
int main() {
  ll T;
  cin >> T;
  for (long long l = 0; l < (T); ++l) {
    ll N;
    cin >> N;
    mat G(N);
    for (long long i = 0; i < (N - 1); ++i) {
      ll a, b;
      cin >> a >> b;
      G.at(a - 1).push_back(b - 1);
      G.at(b - 1).push_back(a - 1);
    }
    ll ans = 0;
    vec A(N, 0), B(N, 0);
    dfs(0, 0, G, A, B, ans);
    cout << ans << endl;
  }
}
