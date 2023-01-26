#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, k, t, T, r, p = 0;
  cin >> T;
  for (long long t = 0; t < T; t++) {
    cin >> n >> m;
    vector<long long> a, b, c, d;
    cin >> k;
    for (long long i = 0; i < k; i++) {
      cin >> r;
      a.push_back(r);
    }
    sort(a.begin(), a.end());
    cin >> k;
    for (long long i = 0; i < k; i++) {
      cin >> r;
      b.push_back(r);
    }
    sort(b.begin(), b.end());
    cin >> k;
    for (long long i = 0; i < k; i++) {
      cin >> r;
      c.push_back(r);
    }
    sort(c.begin(), c.end());
    cin >> k;
    for (long long i = 0; i < k; i++) {
      cin >> r;
      d.push_back(r);
    }
    sort(d.begin(), d.end());
    long long w1, w2, w3, w4, w;
    w1 = a[a.size() - 1] - a[0];
    w2 = b[b.size() - 1] - b[0];
    w3 = c[c.size() - 1] - c[0];
    w4 = d[d.size() - 1] - d[0];
    long long ans1 = 0, ans2 = 0, ans = 0;
    ans1 = w1 * m;
    ans2 = w2 * m;
    ans = max(ans1, ans2);
    ans1 = w3 * n;
    ans2 = w4 * n;
    ans = max(ans, ans1);
    ans = max(ans, ans2);
    cout << ans << endl;
  }
  return 0;
}
