#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, m;
int *a[N], *mx1[N], *mx2[N], *mn1[N], *mn2[N];
unsigned int hhh[N];
int col[N];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= 1e6; i++) hhh[i] = hhh[i - 1] * 1919810 + 114514;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      a[i] = new int[m + 5];
      mx1[i] = new int[m + 5];
      mx2[i] = new int[m + 5];
      mn1[i] = new int[m + 5];
      mn2[i] = new int[m + 5];
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
      mx1[i][0] = 0;
      for (int j = 1; j <= m; j++) mx1[i][j] = max(a[i][j], mx1[i][j - 1]);
      mx2[i][m + 1] = 0;
      for (int j = m; j >= 1; j--) mx2[i][j] = max(a[i][j], mx2[i][j + 1]);
      mn1[i][0] = 0x3f3f3f3f;
      for (int j = 1; j <= m; j++) mn1[i][j] = min(a[i][j], mn1[i][j - 1]);
      mn2[i][m + 1] = 0x3f3f3f3f;
      for (int j = m; j >= 1; j--) mn2[i][j] = min(a[i][j], mn2[i][j + 1]);
    }
    bool fflg = 0;
    for (int k = 1; k < m; k++) {
      for (int i = 1; i <= n; i++) col[i] = 0;
      vector<pair<int, int> > vec1, vec2, vec3, vec4;
      for (int i = 1; i <= n; i++) {
        vec1.push_back(make_pair(mx1[i][k], i));
        vec2.push_back(make_pair(mn1[i][k], i));
        vec4.push_back(make_pair(mx2[i][k + 1], i));
        vec3.push_back(make_pair(mn2[i][k + 1], i));
      }
      sort(vec1.begin(), vec1.end());
      sort(vec2.begin(), vec2.end());
      sort(vec3.begin(), vec3.end(), greater<pair<int, int> >());
      sort(vec4.begin(), vec4.end(), greater<pair<int, int> >());
      unsigned int res = 0;
      bool flg = 0;
      for (int i = 1; i < n; i++) {
        res ^= hhh[vec1[i - 1].second];
        res ^= hhh[vec3[i - 1].second];
        col[vec1[i - 1].second] = 1;
        if (i + 1 < n && vec1[i - 1].first >= vec2[i].first) continue;
        if (i + 1 < n && vec3[i - 1].first <= vec4[i].first) continue;
        if (res == 0) {
          cout << "YES" << endl;
          for (int j = 1; j <= n; j++) cout << (col[j] ? 'B' : 'R');
          cout << ' ' << k << endl;
          flg = 1;
          break;
        }
      }
      if (flg) {
        fflg = 1;
        break;
      }
    }
    if (!fflg) cout << "NO" << endl;
  }
  return 0;
}
