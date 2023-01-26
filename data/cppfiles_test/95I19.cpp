#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 0.00000001;
void pr() { cout << endl; }
template <typename T1, typename... T2>
void pr(const T1& arg, const T2&... args) {
  cout << arg << " ";
  pr(args...);
}
const int N = 5e5 + 10;
vector<int> v[N], v_m[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      v[i].push_back(2333);
      v_m[i].push_back(2333);
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        v[i].push_back(x);
        v_m[i].push_back(x);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = m - 1; j >= 1; --j) {
        v_m[i][j] = max(v_m[i][j], v_m[i][j + 1]);
      }
    }
    bool flag = 1;
    int mx = 0;
    for (int j = 1; j < m; ++j) {
      int cnt = 0;
      vector<int> l, r;
      l.push_back(2333);
      r.push_back(2333);
      for (int i = 1; i <= n; ++i) {
        mx = max(mx, v[i][j]);
        l.push_back(v_m[i][j]);
        r.push_back(v_m[i][j]);
      }
      for (int i = 2; i <= n; ++i) {
        l[i] = max(l[i - 1], l[i]);
      }
      for (int i = n - 1; i >= 1; --i) {
        r[i] = max(r[i + 1], r[i]);
      }
      for (int i = 1; i <= n; ++i) {
        if (v[i][j] == mx) {
          int l_m = i - 1 >= 1 ? l[i - 1] : 0;
          int r_m = i + 1 <= n ? r[i + 1] : 0;
          if (l_m > v[i][j + 1] || r_m > v[i][j + 1]) {
            cout << "YES" << endl;
            flag = 0;
            for (int k = 1; k <= n; ++k) {
              if (k == i) cout << "R";
              cout << "B";
            }
            cout << " " << j << endl;
            break;
          }
        }
      }
      if (!flag) break;
    }
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
      v_m[i].clear();
    }
    if (flag) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
