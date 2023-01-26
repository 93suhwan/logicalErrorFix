#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 30;
const long long mod = 1e9 + 7;
const long long base = 3e18;
long long cnt[maxn];
long long a[maxn];
long long pos[maxn];
long long id[maxn];
long long get(vector<long long> vt) {
  long long n = vt.size();
  for (int i = 1; i <= n; i++) {
    pos[vt[i - 1]] = i;
    id[i] = vt[i - 1];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (id[i] == a[i]) continue;
    long long h = id[i];
    swap(id[i], id[pos[a[i]]]);
    pos[h] = pos[a[i]];
    ans++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("tests.in", "r")) {
    freopen("tests.in", "r", stdin);
  }
  long long t1;
  cin >> t1;
  while (t1--) {
    long long n, m;
    cin >> n >> m;
    long long sle = n - m * 2;
    for (int i = 1; i <= n; i++) {
      long long p;
      cin >> p;
      a[i] = p;
      if (i >= p) {
        cnt[i - p]++;
      } else {
        cnt[i + n - p]++;
      }
    }
    vector<long long> ans;
    for (int i = 0; i <= n - 1; i++) {
      if (cnt[i] >= sle) {
        vector<long long> vt;
        for (int j = n - i + 1; j <= n; j++) {
          vt.push_back(j);
        }
        for (int t = 1; t <= n - i; t++) vt.push_back(t);
        if (get(vt) <= m) ans.push_back(i);
      }
    }
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    cout << ans.size() << " ";
    for (auto to : ans) cout << to << " ";
    cout << "\n";
  }
}
