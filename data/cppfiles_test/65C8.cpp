#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  sort((a).begin(), (a).end());
  vi b = {a.back()};
  a.pop_back();
  str s;
  cin >> s;
  for (int i = 1; i < (n); ++i) {
    if (s[i] != s[i - 1]) {
      b.push_back(a.back());
      a.pop_back();
    }
  }
  reverse((b).begin(), (b).end());
  reverse((a).begin(), (a).end());
  for (int i = 1; i < (int)b.size(); i += 2) b[i] *= -1;
  for (int i = 0; i < (int)a.size(); i += 2) a[i] *= -1;
  int was = 1;
  vi result;
  result.push_back(b[0]);
  for (int i = 1; i < (n); ++i) {
    if (s[i] != s[i - 1]) {
      result.push_back(b[was++]);
    } else {
      result.push_back(a[i - was]);
    }
  }
  array<char, 2> to = {'L', 'R'};
  if (s[0] == 'L') swap(to[0], to[1]);
  for (auto &x : result) cout << abs(x) << ' ' << to[x > 0] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  for (int _ = 0; _ < (tests); ++_) {
    solve();
  }
  return 0;
}
