#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7;
const int MOD = 1e9 + 7;
int t;
int n, m;
int a[MAX], b[MAX];
int l[MAX], r[MAX];
long long L[MAX], R[MAX];
vector<pair<int, int> > ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
      if (a[i] >= m)
        l[i] = a[i] - b[i] - m;
      else
        l[i] = m - a[i] - b[i];
      if (b[i] >= m)
        r[i] = a[i] - b[i] + m;
      else
        r[i] = a[i] - m + b[i];
      L[i] = L[i - 1] + l[i], R[i] = R[i - 1] + r[i];
      assert(abs(l[i]) % 2 == abs(r[i]) % 2);
    }
    long long nw = 0;
    for (int i = 1; i <= n; i++) {
      int d;
      long long nwl = nw + l[i], nwr = nw + r[i];
      long long rsum = -(L[n] - L[i]), lsum = -(R[n] - R[i]);
      if (nwl >= rsum || (nwl >= lsum && nwl <= rsum))
        d = l[i];
      else if (nwr <= lsum || (nwr >= lsum && nwr <= rsum))
        d = r[i];
      else {
        d = lsum - nw;
        if (abs(l[i] - d) % 2) d++;
      }
      nw += d;
      int cnt1 = min(m, a[i]), cnt2 = m - cnt1;
      d = (d - l[i]) / 2;
      ans.push_back({cnt1 - d, cnt2 + d});
    }
    cout << abs(nw) << '\n';
    for (pair<int, int> v : ans) cout << v.first << " " << v.second << '\n';
  }
  return 0;
}
