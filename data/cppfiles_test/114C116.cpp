#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long double t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> sz, v[n], ans;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x;
      sz.push_back(x);
      while (x--) {
        cin >> y;
        v[i].push_back(y);
      }
    }
    int m;
    cin >> m;
    set<vector<int>> s;
    while (m--) {
      vector<int> tmp;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tmp.push_back(x - 1);
      }
      s.insert(tmp);
    }
    long long sum = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++) tmp.push_back(sz[i] - 1);
    if (s.find(tmp) == s.end()) {
      for (int i = 0; i < n; i++) cout << tmp[i] + 1 << " ";
      return 0;
    }
    for (auto it = s.begin(); it != s.end(); it++) {
      vector<int> v1 = *it;
      long long tmpSum = 0;
      for (int i = 0; i < n; i++) tmpSum += v[i][v1[i]];
      for (int i = 0; i < n; i++) {
        v1[i] -= 1;
        if (v1[i] < 0) {
          v1[i]++;
          continue;
        }
        if (s.find(v1) == s.end()) {
          long long val = tmpSum + v[i][v1[i]] - v[i][v1[i] + 1];
          if (val > sum) {
            sum = val;
            ans = v1;
          }
        }
        v1[i]++;
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
  }
}
