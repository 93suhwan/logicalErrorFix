#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
void solve() {
  int n;
  cin >> n;
  map<int, vector<tuple<int, int, int>>> mp;
  vector<int> A(n), B(n);
  for (int i = (int)(0); i < (int)(n); i++) {
    int a, b, m;
    cin >> a >> b >> m;
    int sum = a + b - m;
    int mn = (a - min(a, m)) - (b - m + min(a, m));
    int mx = (a - m + min(b, m)) - (b - min(b, m));
    mp[sum].push_back({mn, mx, i});
    A[i] = a, B[i] = b;
  }
  vector<pair<int, int>> ans(n);
  int cnt = 0;
  for (auto [sum, v] : mp) {
    vector<tuple<int, int, int>> C;
    for (auto [mn, mx, i] : v) {
      C.push_back({mn, -1, i});
      C.push_back({mx + 1, 1, i});
    }
    set<int> st;
    sort(C.begin(), C.end());
    for (auto [p, t, i] : C) {
      if (t == -1) {
        st.insert(i);
      } else {
        if (st.count(i)) {
          cnt++;
          for (int j : st) {
            ans[j] = {A[j] - (sum + p - 1) / 2, B[j] - (sum - (p - 1)) / 2};
          }
          st.clear();
        }
      }
    }
  }
  cout << cnt << '\n';
  for (int i = (int)(0); i < (int)(n); i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
