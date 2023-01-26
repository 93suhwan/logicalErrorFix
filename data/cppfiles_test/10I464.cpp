#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m, m1;
    for (int i = 0; i < n; i++) {
      m[a[i]]++;
    }
    for (auto i = m.begin(); i != m.end(); i++) {
      if (i->second >= k) m1[i->first] = 1;
    }
    vector<int> v(n, -1);
    int x = k, j = 1, y = k, c = 0;
    for (int i = 0; i < n; i++) {
      if (m[a[i]] >= x) {
        if (m1[a[i]] <= k) {
          v[i] = m1[a[i]];
          m1[a[i]]++;
        }
      } else
        c++;
    }
    c -= (c % k);
    for (int i = 0; i < n; i++) {
      if (m[a[i]] < x && c > 0) {
        v[i] = j;
        j++;
        if (j > k) j = 1;
        c--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (v[i] == -1)
        cout << 0 << " ";
      else
        cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
