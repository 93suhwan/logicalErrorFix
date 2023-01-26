#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 7;
const int INF = (int)1e9 + 7;
int t;
int n;
int a[N][2];
bool ok1[N][2];
bool ok2[N][2];
int p1[N][2];
int p2[N][2];
void solve() {
  for (int i = 1; i <= n; i++) {
    ok1[i][0] = ok1[i][1] = 0;
    ok2[i][0] = ok2[i][1] = 0;
  }
  ok1[1][0] = ok1[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int cur = 0; cur < 2; cur++) {
      for (int ant = 0; ant < 2; ant++) {
        if (a[i - 1][ant] < a[i][cur] && ok1[i - 1][ant]) {
          ok1[i][cur] = 1;
          p1[i][cur] = ant;
        }
      }
    }
  }
  ok2[n][0] = ok2[n][1] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int cur = 0; cur < 2; cur++) {
      for (int ant = 0; ant < 2; ant++) {
        if (a[i][cur] < a[i + 1][ant] && ok2[i + 1][ant]) {
          ok2[i][cur] = 1;
          p2[i][cur] = ant;
        }
      }
    }
  }
  bool yes = 0;
  for (int i = 1; i < n; i++) {
    for (int ff = 0; ff < 2; ff++) {
      for (int ss = 0; ss < 2; ss++) {
        yes |= (ok1[i][ff] && ok2[i][ss]);
      }
    }
  }
  if (!yes) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int pos = -1, t1 = -1, t2 = -1;
  for (int i = 1; i < n; i++) {
    for (int ff = 0; ff < 2; ff++) {
      for (int ss = 0; ss < 2; ss++) {
        if (ok1[i][ff] && ok2[i][ss]) {
          pos = i;
          t1 = ff;
          t2 = ss;
        }
      }
    }
  }
  assert(pos != -1);
  assert(t1 != -1);
  assert(t2 != -1);
  vector<int> x, y;
  int i = pos;
  while (i >= 1) {
    assert(ok1[i][t1]);
    x.push_back(a[i][t1]);
    t1 = p1[i][t1];
    i--;
  }
  i = pos + 1;
  while (i <= n) {
    assert(ok2[i][t2]);
    y.push_back(a[i][t2]);
    t2 = p2[i][t2];
    i++;
  }
  reverse(x.begin(), x.end());
  for (auto &it : x) {
    cout << it << " ";
  }
  for (auto &it : y) {
    cout << it << " ";
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0];
      a[i][1] = -a[i][0];
    }
    solve();
  }
  return 0;
}
