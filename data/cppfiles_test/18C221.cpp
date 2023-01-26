#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const double pi = acos(-1.0);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long poww(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = (s * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return s % mod;
}
const int N = 1e6 + 11;
long long n, m;
bool vis[555];
void solve() {
  memset(vis, 0, sizeof(vis));
  vector<pair<int, int> > ve;
  vector<int> v;
  cin >> n >> m;
  n *= 2;
  int l, r;
  for (auto i = (1); i <= (m); ++i) {
    cin >> l >> r;
    ve.push_back({l, r});
    vis[l] = 1;
    vis[r] = 1;
  }
  for (auto i = (1); i <= (n); ++i) {
    if (vis[i] == 0) v.push_back(i);
  }
  int len = v.size();
  len /= 2;
  for (int i = 0; i < len; i++) ve.push_back({v[i], v[i + len]});
  int ans = 0;
  for (int i = 0; i < ve.size(); i++) {
    if (ve[i].first > ve[i].second) swap(ve[i].first, ve[i].second);
  }
  n /= 2;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> q;
      q.push_back(ve[i].second);
      q.push_back(ve[i].first);
      q.push_back(ve[j].second);
      q.push_back(ve[j].first);
      sort(q.begin(), q.end());
      if (q[0] == ve[i].first && q[1] == ve[i].second)
        ;
      else if (q[1] == ve[i].first && q[2] == ve[i].second)
        ;
      else if (q[2] == ve[i].first && q[3] == ve[i].second)
        ;
      else if (q[0] == ve[j].first && q[1] == ve[j].second)
        ;
      else if (q[1] == ve[j].first && q[2] == ve[j].second)
        ;
      else if (q[2] == ve[j].first && q[3] == ve[j].second)
        ;
      else
        ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
