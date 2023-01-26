#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    vector<long long> a, b;
    long long maxa = -0x3f3f3f3f, maxb = -0x3f3f3f3f;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      long long c;
      cin >> c;
      if (c >= 0)
        a.push_back(c), maxa = max(maxa, c);
      else
        b.push_back(abs(c)), maxb = max(maxb, abs(c));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans1 = 0, i;
    if (a.size() > 0) {
      for (i = a.size() - 1; i >= 0; i -= k) {
        ans1 += a[i];
      }
    }
    if (b.size() > 0) {
      for (i = b.size() - 1; i >= 0; i -= k) {
        ans1 += b[i];
      }
    }
    ans1 <<= 1;
    ans1 -= max(maxa, maxb);
    cout << ans1 << endl;
  }
}
