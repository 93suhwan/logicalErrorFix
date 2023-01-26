#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target( \
    "bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 200000;
void solve() {
  ll n, t = 0;
  cin >> n;
  int arr[n];
  for (int i = 0, nnnn = (n); i < nnnn; ++i) cin >> arr[i];
  vector<pair<int, ll>> cur;
  for (int i = n - 1; i >= 0; i--) {
    vector<pair<int, ll>> nxt, nxt1;
    for (auto it : cur) {
      t += (it.first - 1) * it.second * (i + 1);
      if (i > 0) {
        int t1 = arr[i] / it.first;
        int add = (arr[i - 1] + t1 - 1) / t1;
        nxt.push_back(make_pair(add, it.second));
      }
    }
    t %= mod;
    if (i > 0) {
      ll d = arr[i - 1] / arr[i] + (int)(arr[i - 1] % arr[i] > 0);
      nxt.push_back(make_pair(d, 1));
    }
    sort((nxt).begin(), (nxt).end());
    for (auto it : nxt) {
      if (nxt1.empty())
        nxt1.push_back(it);
      else if (it.first == nxt1[((int)(nxt1).size()) - 1].first) {
        nxt1[((int)(nxt1).size()) - 1].second += it.second;
      } else
        nxt1.push_back(it);
    }
    cur = nxt1;
  }
  cout << t << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
