#include <bits/stdc++.h>
using namespace std;
int T;
struct Item {
  int lmx, lmn, rmx, rmn, row;
  bool operator<(const Item& rhs) const {
    if (lmn != rhs.lmn) {
      return lmn < rhs.lmn;
    } else {
      if (lmx != rhs.lmx) {
        return lmx < rhs.lmx;
      } else {
        if (rmn != rhs.rmn)
          return rmn > rhs.rmn;
        else
          return rmx > rhs.rmx;
      }
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > vec(n + 1);
    vector<vector<int> > mx_pre(n + 1), mn_pre(n + 1);
    vector<vector<int> > mx_suff(n + 1), mn_suff(n + 1);
    for (int i = 1; i <= n; i++) {
      vec[i].resize(m + 1);
      mn_pre[i].resize(m + 1);
      mx_pre[i].resize(m + 1);
      mx_suff[i].resize(m + 1);
      mn_suff[i].resize(m + 1);
      for (int j = 1; j <= m; j++) {
        cin >> vec[i][j];
        mn_pre[i][j] = vec[i][j];
        mx_pre[i][j] = vec[i][j];
        mx_suff[i][j] = vec[i][j];
        mn_suff[i][j] = vec[i][j];
      }
    }
    for (int i = 2; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        mx_pre[j][i] = max(mx_pre[j][i - 1], mx_pre[j][i]);
        mn_pre[j][i] = min(mn_pre[j][i - 1], mn_pre[j][i]);
      }
    }
    for (int i = m - 1; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        mx_suff[j][i] = max(mx_suff[j][i + 1], mx_suff[j][i]);
        mn_suff[j][i] = min(mn_suff[j][i + 1], mn_suff[j][i]);
      }
    }
    bool check = false;
    for (int i = 1; i < m; i++) {
      bool flag = false;
      vector<Item> item;
      for (int j = 1; j <= n; j++) {
        item.push_back((Item){mx_pre[j][i], mn_pre[j][i], mx_suff[j][i + 1],
                              mn_suff[j][i + 1], j});
      }
      sort(item.begin(), item.end());
      vector<pair<int, int> > pre(n), suff(n);
      for (int j = 0; j < n; j++) {
        pre[j] = {item[j].rmn, item[j].lmx};
        suff[j] = {item[j].lmn, item[j].rmx};
      }
      for (int j = 1; j < n; j++) {
        pre[j].first = min(pre[j].first, pre[j - 1].first);
        pre[j].second = max(pre[j].second, pre[j - 1].second);
      }
      for (int j = n - 2; j >= 0; j--) {
        suff[j].first = min(suff[j].first, suff[j + 1].first);
        suff[j].second = max(suff[j].second, suff[j + 1].second);
      }
      for (int j = n - 1; j >= 1; j--) {
        if (suff[j].first > pre[j - 1].second &&
            pre[j - 1].first > suff[j].second) {
          flag = true;
          vector<bool> color(n + 1, false);
          for (int k = n - 1; k >= j; k--) {
            color[item[k].row] = true;
          }
          cout << "YES\n";
          for (int k = 1; k <= n; k++) {
            if (color[k])
              cout << 'R';
            else
              cout << 'B';
          }
          cout << ' ' << i << '\n';
          break;
        }
      }
      if (flag) {
        check = true;
        break;
      }
    }
    if (!check) {
      cout << "NO\n";
    }
  }
  return 0;
}
