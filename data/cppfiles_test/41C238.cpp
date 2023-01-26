#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const long long lg = 21;
const double EPS = 1e-6;
long long n, m;
vector<string> v;
vector<long long> p[6];
void gen(string s = "", set<char> q = {}) {
  if (s.length() == 3) {
    v.push_back(s);
    return;
  }
  for (long long i = 0; i < 3; i++) {
    if (!q.count('a' + i)) {
      q.insert('a' + i);
      gen(s + char('a' + i), q);
      q.erase('a' + i);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  string s;
  cin >> n >> m >> s;
  gen();
  for (long long i = 0; i < 6; i++) {
    p[i].push_back(0);
    for (long long j = 0; j < s.length(); j++) {
      if (s[j] == v[i][j % 3])
        p[i].push_back(p[i].back());
      else
        p[i].push_back(p[i].back() + 1);
    }
  }
  while (m--) {
    long long l, r, ans = INF;
    cin >> l >> r;
    for (long long i = 0; i < 6; i++) ans = min(ans, p[i][r] - p[i][l - 1]);
    cout << ans << '\n';
  }
}
