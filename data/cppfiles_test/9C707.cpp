#include <bits/stdc++.h>
using namespace std;
void show_trace() { cout << endl; }
template <typename Start, typename... Rem>
void show_trace(Start S, Rem... R) {
  cout << ' ' << S;
  show_trace(R...);
}
const int INFi = 2139062143;
const long long INF = 1e18;
void solve() {
  string s;
  cin >> s;
  map<char, int> f;
  set<char> se;
  for (auto c : s) {
    se.insert(c);
    f[c]++;
  }
  int ans = 0;
  int rem = 0;
  for (auto c : se) {
    if (f[c] >= 2)
      ans++;
    else
      rem++;
  }
  cout << ans + (rem / 2) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
