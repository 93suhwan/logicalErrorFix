#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype(a.print(), o) {
  o << '{';
  a.print();
  return o << '}';
}
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype(a.second, o) {
  o << '(' << a.first << ", " << a.second;
  return o << ')';
}
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype((a).begin(), (a).end(), o) {
  o << '[';
  auto d = "";
  for (auto i : a) (o << d << i, d = ", ");
  return o << ']';
}
void DD(...) {}
template <class t, class u, class... w>
void DD(t s, u a, w... k) {
  for (int b = 1; *s && *s - b * 44; cerr << *s++) b += 2 / (*s * 2 - 81);
  cerr << ": " << a << *s++;
  DD(s, k...);
}
void run() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  s1 = "#" + s1;
  s2 = "#" + s2;
  vector<int> dp(n + 1);
  int last[2];
  last[0] = -1;
  last[1] = -1;
  for (int i = 1; i <= n; i++) {
    last[s1[i] - '0'] = i;
    last[s2[i] - '0'] = i;
    if (last[0] == -1) {
      dp[i] = dp[i - 1];
    } else if (last[1] == -1) {
      dp[i] = dp[i - 1] + 1;
    } else if (last[0] < last[1]) {
      dp[i] = max(dp[last[0] - 1] + 2, dp[i - 1]);
    } else if (last[1] < last[0]) {
      dp[i] = max(dp[last[1] - 1] + 2, dp[i - 1] + 1);
    } else {
      dp[i] = dp[i - 1] + 2;
    }
  }
  cout << dp[n] << '\n';
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    run();
  }
  return 0;
}
