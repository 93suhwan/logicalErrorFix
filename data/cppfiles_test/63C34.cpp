#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using cd = complex<db>;
using vi = vector<int>;
using vd = vector<db>;
using vl = vector<ll>;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> second(n);
  vector<int> sv(n);
  vector<vector<vi> > pos(n);
  for (int i = 0; i < n; i++) {
    cin >> second[i];
    int v = 0;
    int N = int((second[i]).size());
    pos[i].emplace_back();
    for (int j = 0; j < N; j++) {
      if (second[i][j] == '(')
        v++;
      else
        v--;
      if (v <= 0) {
        if (int((pos[i]).size()) <= -v) pos[i].emplace_back();
        pos[i][-v].push_back(j);
      }
    }
    sv[i] = v;
  }
  int N = 1 << n;
  vl dp(N, -1);
  vl sum(N, 0);
  dp[0] = 0;
  ll ans = 0;
  for (int msk = 1; msk < N; msk++) {
    for (int i = 0; i < n; i++) {
      if ((msk >> i) & 1) {
        int nmsk = msk ^ (1 << i);
        sum[msk] = sum[nmsk] + sv[i];
        if (dp[nmsk] == -1) continue;
        int L = int((pos[i]).size()) - 1;
        if (sum[nmsk] == L) {
          dp[msk] = max(dp[msk], dp[nmsk] + int((pos[i][L]).size()));
          if (dp[msk] > ans) ans = dp[msk];
        } else if (sum[nmsk] > L)
          dp[msk] = max(dp[msk], dp[nmsk]);
        else {
          int p = pos[i][sum[nmsk] + 1][0] - 1;
          if (p < 0) continue;
          int ct =
              lower_bound(begin(pos[i][sum[nmsk]]), end(pos[i][sum[nmsk]]), p) -
              pos[i][sum[nmsk]].begin();
          ans = max(ans, dp[nmsk] + ct + 1);
        }
      }
    }
  }
  cout << ans << endl;
}
