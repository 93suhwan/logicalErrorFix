#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1);
vector<int> a[500005];
vector<int> lmx[500005], lmn[500005], rmx[500005], rmn[500005];
char ans[500005];
struct rowl {
  int mx, mn, id;
  bool operator<(const rowl x) const {
    return mn == x.mn ? id < x.id : mn < x.mn;
  }
};
struct rowr {
  int mx, mn, id;
  bool operator<(const rowr x) const {
    return mx == x.mx ? id < x.id : mx > x.mx;
  }
};
set<rowl> sl;
set<rowr> sr;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      int tmp;
      a[i].push_back(0);
      for (int j = 1; j <= m; j++) {
        cin >> tmp;
        a[i].push_back(tmp);
      }
    }
    for (int i = 1; i <= n; i++) {
      lmx[i].push_back(0);
      lmn[i].push_back(inf);
      for (int j = 1; j <= m; j++) {
        lmx[i].push_back(max(lmx[i].back(), a[i][j]));
        lmn[i].push_back(min(lmn[i].back(), a[i][j]));
      }
      rmx[i].push_back(a[i][m]);
      rmn[i].push_back(a[i][m]);
      for (int j = m - 1; j > 0; j--) {
        rmx[i].push_back(max(rmx[i].back(), a[i][j]));
        rmn[i].push_back(min(rmn[i].back(), a[i][j]));
      }
      rmx[i].push_back(0);
      rmn[i].push_back(inf);
      reverse(rmx[i].begin(), rmx[i].end());
      reverse(rmn[i].begin(), rmn[i].end());
    }
    int c = 0;
    for (int col = 1; col < m; col++) {
      if (c > 0) break;
      sl.clear(), sr.clear();
      for (int i = 1; i <= n; i++) {
        ans[i] = 'R';
        sl.insert((rowl){lmx[i][col], lmn[i][col], i});
        sr.insert((rowr){rmx[i][col + 1], rmn[i][col + 1], i});
      }
      int lblue_mx = 0, rblue_mn = 1000001;
      while (!sl.empty()) {
        int lred_mn = sl.begin()->mn;
        while (!sl.empty() && sl.begin()->mn == lred_mn) {
          int tmx = sl.begin()->mx, tmn = sl.begin()->mn, tid = sl.begin()->id;
          lblue_mx = max(lblue_mx, tmx);
          rblue_mn = min(rblue_mn, rmn[tid][col + 1]);
          ans[tid] = 'B';
          sl.erase(sl.begin());
          sr.erase((rowr){rmx[tid][col + 1], rmn[tid][col + 1], tid});
        }
        if (!sl.empty() && lblue_mx < sl.begin()->mn &&
            rblue_mn > sr.begin()->mx) {
          c = col;
          break;
        }
      }
    }
    if (c) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) cout << ans[i];
      cout << ' ' << c;
      cout << '\n';
    } else {
      cout << "NO\n";
    }
    for (int i = 1; i <= n; i++) {
      a[i].clear();
      lmx[i].clear();
      lmn[i].clear();
      rmx[i].clear();
      rmn[i].clear();
    }
  }
}
