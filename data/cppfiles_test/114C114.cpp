#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  int cur = 0, ans = 0;
  vector<int> h(n);
  for (int i = 0, c; i < n; ++i) {
    cin >> c;
    a[i].resize(c);
    for (int j = 0; j < c; ++j) {
      cin >> a[i][j];
    }
    --c;
    cur += a[i][c];
    h[i] = c;
  }
  int m;
  cin >> m;
  set<vector<int>> st;
  for (int j = 0; j < m; ++j) {
    vector<int> H(n);
    for (auto& it : H) {
      cin >> it;
      --it;
    }
    st.insert(H);
  }
  if (st.count(h)) {
    int tmp;
    for (auto H : st) {
      cur = 0;
      for (int i = 0; i < n; ++i) {
        cur += a[i][H[i]];
      }
      if (cur <= ans) continue;
      for (int i = 0; i < n; ++i) {
        if (H[i] != 0) {
          --H[i];
          if (!st.count(H)) {
            tmp = cur + a[i][H[i]] - a[i][H[i] + 1];
            if (ans < tmp) {
              ans = tmp;
              h = H;
            }
          }
          ++H[i];
        }
      }
    }
  }
  for (auto& it : h) {
    cout << it + 1 << ' ';
  }
}
