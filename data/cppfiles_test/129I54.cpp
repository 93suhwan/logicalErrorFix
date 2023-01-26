#include <bits/stdc++.h>
using namespace std;
vector<int> v1[200005];
bool visit[200005];
bool color[200005];
int parent[200005];
int zz, zz1;
vector<int> vv;
void solve() {
  long long int n, m, a, b, c, time, z, x, y, d, w, u, v, r, l;
  cin >> n;
  vector<long long int> v1(n);
  for (long long int x = 0; x < n; ++x) cin >> v1[x];
  sort(v1.begin(), v1.end());
  long long int ans = 0;
  for (long long int x = 1; x < n + 1; ++x) {
    a = (v1[x - 1] - 1) / 2;
    if (a < x and v1[x - 1] != x) {
      cout << -1 << endl;
      return;
    }
    if (v1[x - 1] != x) ans++;
  }
  cout << ans << endl;
}
void test_case() {
  long long int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
int main() { test_case(); }
