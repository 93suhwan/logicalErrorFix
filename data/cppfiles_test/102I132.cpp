#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
template <class T>
using VC = vector<T>;
template <class T, class V>
using PR = pair<T, V>;
template <class T>
bool mns(T &a, T b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
bool mxs(T &a, T b) {
  return (a < b ? a = b, 1 : 0);
}
pii DR[] = {{-1, 0}, {0, 1},  {1, 0},  {0, -1},
            {1, 1},  {1, -1}, {-1, 1}, {-1, -1}};
const int INF = 1e9 + 1e7 + 7;
const int MOD = 998244353;
const ll INFLL = 1e18 + 1e16 + 7ll;
const int N = 2e5 + 5;
const int SS = 2e6 + 5;
void Main();
bool START = 1;
int main() {
  ios_base::sync_with_stdio(0);
  if (START) {
    int t;
    cin >> t;
    while (t--) Main();
  } else
    Main();
}
int n, m;
string s;
void Main() {
  cin >> n >> m;
  cin >> s;
  int l = 0, r = ll(s.size()), mid, ans;
  int x = 1, y = 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    int ml, mr, mu, md;
    ml = md = 0;
    mr = mu = 0;
    int cx = 0, cy = 0;
    for (int i = 0; i < mid; ++i) {
      if (s[i] == 'L')
        --cx, mns(ml, cx);
      else if (s[i] == 'R')
        ++cx, mxs(mr, cx);
      else if (s[i] == 'U')
        ++cy, mxs(mu, cy);
      else
        --cy, mns(md, cy);
    }
    if (abs(ml) + 1 <= m - mr && abs(md) + 1 <= n - mu)
      ans = mid, x = m - mr, y = n - mu, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << x << ' ' << y << endl;
}
