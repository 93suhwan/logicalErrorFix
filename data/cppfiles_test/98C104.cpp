#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double PI = acos(-1.0);
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  if (s.size()) setIn(s + ".in"), setOut(s + ".out");
}
using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpll = vector<pll>;
using vpii = vector<pii>;
bool check(string s) {
  int a = 0, b = 0;
  for (char c : s)
    if (c == 'a')
      a++;
    else
      b++;
  return a == b;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string cur = "";
      for (int k = i; k <= j; k++) cur += s[k];
      if (check(cur)) {
        cout << i + 1 << ' ' << j + 1 << endl;
        return;
      }
    }
  }
  cout << -1 << ' ' << -1 << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
