#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << "  " << H;
  dbg_out(T...);
}
void solve() {
  int N;
  cin >> N;
  string S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int ans = 0;
  for (char c = 'a'; c <= 'e'; c++) {
    vector<pair<int, int>> cnt;
    for (int i = 0; i < N; i++) {
      int other = 0;
      for (char s : S[i]) {
        if (s != c) {
          other++;
        }
      }
      cnt.emplace_back(other, i);
    }
    sort(cnt.begin(), cnt.end());
    int cur = 0, ccnt = 0, other = 0;
    for (int i = 0; i < N; i++) {
      int idx = cnt[i].second;
      if (c == 'c') {
        ;
      }
      other += cnt[i].first;
      ccnt += S[idx].size() - cnt[i].first;
      if (ccnt <= other) {
        other -= cnt[i].first;
        ccnt -= S[idx].size() - cnt[i].first;
        continue;
      }
      cur++;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
}
