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
vector<int> v[N], mp[N], l_u[N], l_d[N], r_u[N], r_d[N];
int dui[N], n, m;
void init() {
  for (int i = 1; i <= n; ++i)
    v[i].clear(), mp[i].clear(), l_u[i].clear(), l_d[i].clear(), r_u[i].clear(),
        r_d[i].clear();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<pair<int, int> > temp;
    for (int i = 1; i <= n; ++i) {
      v[i].push_back(233);
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        v[i].push_back(x);
      }
    }
    for (int i = 1; i <= n; ++i) {
      temp.push_back(pair<int, int>(v[i][1], i));
    }
    sort(temp.begin(), temp.end());
    int cnt = 0;
    for (int i = 0; i < temp.size(); ++i) {
      int fir = temp[i].second;
      mp[++cnt].push_back(233);
      dui[cnt] = temp[i].second;
      l_u[cnt].push_back(233);
      l_d[cnt].push_back(233);
      r_u[cnt].push_back(233);
      r_d[cnt].push_back(233);
      for (int j = 1; j <= m; ++j) {
        mp[cnt].push_back(v[fir][j]);
        l_u[cnt].push_back(v[fir][j]);
        l_d[cnt].push_back(v[fir][j]);
        r_u[cnt].push_back(v[fir][j]);
        r_d[cnt].push_back(v[fir][j]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        l_u[i][j] = max({i - 1 >= 1 ? l_u[i - 1][j] : 0,
                         j - 1 >= 1 ? l_u[i][j - 1] : 0, l_u[i][j]});
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= m; ++j) {
        l_d[i][j] = min({i + 1 <= n ? l_d[i + 1][j] : inf,
                         j - 1 >= 1 ? l_d[i][j - 1] : inf, l_d[i][j]});
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = m; j >= 1; --j) {
        r_u[i][j] = min({i - 1 >= 1 ? r_u[i - 1][j] : inf,
                         j + 1 <= m ? r_u[i][j + 1] : inf, r_u[i][j]});
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = m; j >= 1; --j) {
        r_d[i][j] = max({i + 1 <= n ? r_d[i + 1][j] : 0,
                         j + 1 <= m ? r_d[i][j + 1] : 0, r_d[i][j]});
      }
    }
    bool flag = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (l_u[i][j] < l_d[i + 1][j] && r_u[i][j + 1] > r_d[i + 1][j + 1]) {
          flag = 0;
          cout << "YES" << endl;
          bool op[N];
          memset(op, 0, sizeof(op));
          for (int k = 1; k <= i; ++k) {
            op[dui[k]] = 1;
          }
          for (int k = 1; k <= n; ++k) {
            if (op[k])
              cout << "B";
            else
              cout << "R";
          }
          cout << " " << j << endl;
        }
        if (!flag) break;
      }
      if (!flag) break;
    }
    if (flag) cout << "NO" << endl;
    init();
  }
  return 0;
}
