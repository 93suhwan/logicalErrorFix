#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
int a[N], p[N];
vector<int> v0, v1, v2, v3;
int h(vector<int> &v, int k) {
  return lower_bound(v.begin(), v.end(), k) - v.begin() + 1;
}
void solve() {
  v0.clear();
  v2.clear();
  v1.clear();
  v3.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    a[i] = c - '0';
    if (a[i] == 0)
      v0.push_back(p[i]);
    else
      v1.push_back(p[i]);
  }
  sort(v0.begin(), v0.end());
  sort(v1.begin(), v1.end());
  for (int i = 1; i <= n; ++i) {
    if (i <= v0.size())
      v2.push_back(p[i]);
    else
      v3.push_back(p[i]);
  }
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());
  long long ans = 0;
  for (int i = 1; i <= v0.size(); ++i) {
    int k = h(v2, p[i]);
    cout << v0[k - 1] << " ";
    ans += abs(v0[k - 1] - p[i]);
  }
  for (int i = v0.size() + 1; i <= n; ++i) {
    int k = h(v3, p[i]);
    cout << v1[k - 1] << " ";
    ans += abs(v1[k - 1] - p[i]);
  }
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
