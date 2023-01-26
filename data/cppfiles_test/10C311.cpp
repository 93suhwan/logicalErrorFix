#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t, n, i, x, mx, mn, f, j, s, r, y, c, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long int> v, v1[n + 2], v2(n + 2, 0);
    map<long long int, long long int> M, M1;
    map<long long int, long long int>::iterator it;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
      v1[x].push_back(i);
      M[x]++;
    }
    it = M.begin();
    s = 0;
    while (it != M.end()) {
      s += min((long long int)k, it->second);
      it++;
    }
    s = s / k;
    x = 1;
    c = 0;
    for (i = 0; i <= n; i++) {
      for (j = 0; j < v1[i].size() && j < k; j++) {
        c++;
        v2[v1[i][j]] = x;
        x++;
        if (x > k) x = 1;
        if ((s * k) <= c) break;
      }
      if ((s * k) <= c) break;
    }
    for (i = 0; i < n; i++) {
      cout << v2[i] << " ";
    }
    cout << endl;
  }
}
