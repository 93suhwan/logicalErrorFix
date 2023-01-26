#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll inf = 1LL << 60;
void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  string t = "";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      if (cnt == 0) {
        t += s[i];
        continue;
      } else {
        ll p = x % (cnt * k + 1);
        while (p--) t += 'b';
        x /= (cnt * k + 1);
        cnt = 0;
        t += s[i];
      }
    } else {
      cnt++;
    }
  }
  if (cnt != 0) {
    ll p = x % (cnt * k + 1);
    while (p--) t += 'b';
    x /= (cnt * k + 1);
    cnt = 0;
  }
  reverse(t.begin(), t.end());
  cout << t << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
