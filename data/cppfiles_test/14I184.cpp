#include <bits/stdc++.h>
using namespace std;
vector<int> p[2021];
int main() {
  ios_base::sync_with_stdio(false);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int pre = 0;
    int ans = 0;
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] == i) {
        pre++;
        continue;
      }
      int c = 0;
      int oc = 0;
      for (int j = i; j < a.size(); ++j) {
        if (a[j] == j)
          c++;
        else if (j > a[j])
          oc++;
      }
      if (c + pre >= k) {
        pre += c;
        break;
      } else if (oc > c) {
        a.erase(a.begin() + i);
        i = max(0, i - 1);
        ans++;
      }
    }
    if (pre >= k)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}
