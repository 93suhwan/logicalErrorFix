#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k;
const int N = 1e6 + 5;
int colBanned[N][2];
int rowBanned[N][2];
long long int pp[N];
long long int iw = 499122176;
int Cols[3];
int Rows[3];
set<pair<pair<int, int>, int> > history;
void resolve(int x, int y, int t) {
  history.insert(make_pair(make_pair(x, y), t));
}
int colsBad[2];
void add(int x, int y, int t) {
  if (t == 1) {
    int pos = (1 - (y & 1));
    rowBanned[x][pos]++;
    if (rowBanned[x][pos] == 1) {
      int was = 0;
      if (rowBanned[x][1 - pos]) was++;
      Rows[was]--;
      Rows[was + 1]++;
    }
    int pos2 = (1 - (x & 1));
    colBanned[y][pos2]++;
    if (colBanned[y][pos2] == 1) {
      colsBad[(pos2 + (y & 1)) & 1]++;
      int was = 0;
      if (colBanned[y][1 - pos2]) was++;
      Cols[was]--;
      Cols[was + 1]++;
    }
    resolve(x, y, t);
  } else if (t == 0) {
    int pos = (y & 1);
    rowBanned[x][pos]++;
    if (rowBanned[x][pos] == 1) {
      int was = 0;
      if (rowBanned[x][1 - pos]) was++;
      Rows[was]--;
      Rows[was + 1]++;
    }
    int pos2 = (x & 1);
    colBanned[y][pos2]++;
    if (colBanned[y][pos2] == 1) {
      colsBad[(pos2 + (y & 1)) & 1]++;
      int was = 0;
      if (colBanned[y][1 - pos2]) was++;
      Cols[was]--;
      Cols[was + 1]++;
    }
    resolve(x, y, t);
  }
}
void rem(int x, int y, int t, bool dbg) {
  auto it = history.lower_bound(make_pair(make_pair(x, y), 0));
  if (it == history.end()) return;
  int value = -1;
  if ((*it).first == make_pair(x, y)) {
    value = (*it).second;
    history.erase(it);
  }
  if (value == -1) return;
  if (dbg) {
    cout << "AC" << endl;
    for (int i = 1; i <= 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << i << " " << j << " " << colBanned[i][j] << endl;
      }
    }
    cout << "AC" << endl;
  }
  if (value == 0) {
    int pos = (y & 1);
    rowBanned[x][pos]--;
    if (rowBanned[x][pos] == 0) {
      int was = 1;
      if (rowBanned[x][1 - pos]) was++;
      Rows[was]--;
      Rows[was - 1]++;
    }
    int pos2 = (x & 1);
    colBanned[y][pos2]--;
    if (colBanned[y][pos2] == 0) {
      colsBad[(pos2 + (y & 1)) & 1]--;
      int was = 1;
      if (colBanned[y][1 - pos2]) was++;
      Cols[was]--;
      Cols[was - 1]++;
    }
  } else {
    int pos = 1 - (y & 1);
    rowBanned[x][pos]--;
    if (rowBanned[x][pos] == 0) {
      int was = 1;
      if (rowBanned[x][1 - pos]) was++;
      Rows[was]--;
      Rows[was - 1]++;
    }
    int pos2 = (1 - (x & 1));
    colBanned[y][pos2]--;
    if (colBanned[y][pos2] == 0) {
      colsBad[(pos2 + (y & 1)) & 1]--;
      int was = 1;
      if (colBanned[y][1 - pos2]) was++;
      Cols[was]--;
      Cols[was - 1]++;
    }
  }
}
void solve() {
  pp[0] = 1;
  for (int i = 1; i < N; i++) {
    pp[i] = pp[i - 1] * 2;
    pp[i] %= mod;
  }
  cin >> n >> m >> k;
  Rows[0] = n;
  Cols[0] = m;
  while (k--) {
    int x, y, t;
    cin >> x >> y >> t;
    if (t >= 0) {
      rem(x, y, t, false);
      add(x, y, t);
    } else
      rem(x, y, t, false);
    long long int ans = 0;
    long long int waysNormal = pp[m - Cols[1]];
    if (Cols[2] == 0) {
      ans += waysNormal;
      if (ans >= mod) ans -= mod;
      if (ans < 0) ans += mod;
    }
    if (Rows[2] == 0) {
      long long int cur = pp[n - Rows[1]];
      cur %= mod;
      ans += cur;
      if (ans >= mod) ans -= mod;
    }
    if (colsBad[0] == 0 && colsBad[1] == 0) {
      ans -= 2;
    } else if (colsBad[0] > 0 && colsBad[1] > 0) {
      ans -= 0;
    } else
      ans -= 1;
    if (ans < 0) ans += mod;
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
