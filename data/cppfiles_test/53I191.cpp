#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int idx = -2, cnt = 0;
    for (int i = 0; i < n; i++) {
      auto k = lower_bound(b.begin(), b.end(), a[i]);
      if ((k - b.end()) != idx + 1) cnt++;
      idx = k - b.end();
    }
    if (k >= cnt)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
