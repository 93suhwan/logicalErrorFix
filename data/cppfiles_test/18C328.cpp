#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<array<int, 2>> v(k);
    unordered_set<int> st;
    for (int i = 0; i < k; i++) {
      cin >> v[i][0] >> v[i][1];
      if (v[i][0] > v[i][1]) swap(v[i][0], v[i][1]);
      st.insert(v[i][0]);
      st.insert(v[i][1]);
    }
    int nk = n - k;
    int ret = nk * (nk - 1) / 2;
    for (int i = 0; i < k; i++) {
      int cnt0 = 0;
      for (int j = v[i][0] + 1; j != v[i][1]; j++) {
        if (!st.count(j)) cnt0++;
      }
      int cnt1 = nk * 2 - cnt0;
      int cnt = min(cnt0, cnt1);
      ret += cnt;
    }
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        int x0 = v[i][0], y0 = v[i][1];
        int x1 = v[j][0], y1 = v[j][1];
        if (x0 > x1) {
          swap(x0, x1);
          swap(y0, y1);
        }
        if (x1 < y0 && y1 > y0) ret++;
      }
    }
    cout << ret << endl;
  }
  return 0;
}
