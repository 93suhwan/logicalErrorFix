#include <bits/stdc++.h>
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
  ll n, m;
  cin >> n >> m;
  pair<ll, string> arr[n];
  for (int i = 0, nnnn = (n); i < nnnn; ++i) cin >> arr[i].first;
  for (int i = 0, nnnn = (n); i < nnnn; ++i) cin >> arr[i].second;
  ll ans = 0;
  ll p[m];
  for (int i = 0, nnnn = (m); i < nnnn; ++i) p[i] = i + 1;
  for (int i = 0, nnnn = ((1 << n)); i < nnnn; ++i) {
    pair<ll, ll> cnt[m];
    memset(cnt, 0, sizeof cnt);
    for (int j = 0, nnnn = (m); j < nnnn; ++j) cnt[j].second = j;
    ll score = 0;
    for (int j = 0, nnnn = (n); j < nnnn; ++j) {
      if (i & (1 << j))
        score -= arr[j].first;
      else
        score += arr[j].first;
      for (int k = 0, nnnn = (m); k < nnnn; ++k) {
        if (arr[j].second[k] == '1') {
          if (i & (1 << j))
            cnt[k].first++;
          else
            cnt[k].first--;
        }
      }
    }
    sort(cnt, cnt + m);
    for (int j = 0, nnnn = (m); j < nnnn; ++j) {
      score += (j + 1) * cnt[j].first;
    }
    if (ans < score) {
      ans = score;
      for (int j = 0, nnnn = (m); j < nnnn; ++j) {
        p[cnt[j].second] = j + 1;
      }
    }
  }
  for (int i = 0, nnnn = (m); i < nnnn; ++i) {
    cout << p[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
