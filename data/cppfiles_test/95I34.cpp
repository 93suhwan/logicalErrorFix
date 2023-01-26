#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, mod = 998244353;
vector<vector<int> > a, Lmn, Lmx, Rmn, Rmx;
int n, m;
long long H[N];
void preprocess() {
  Lmn = Rmn = Lmx = Rmx = a;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      Lmn[i][j] = min(Lmn[i][j], Lmn[i][j - 1]);
      Lmx[i][j] = max(Lmx[i][j], Lmx[i][j - 1]);
    }
    for (int j = m - 1; j >= 1; j--) {
      Rmn[i][j] = min(Rmn[i][j], Rmn[i][j + 1]);
      Rmx[i][j] = max(Rmx[i][j], Rmx[i][j + 1]);
    }
  }
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bool solve(int k) {
  vector<pair<pair<int, int>, int> > V1, V2;
  for (int i = 1; i <= n; i++) {
    V1.push_back({{Lmn[i][k], Lmx[i][k]}, i});
    V2.push_back({{Rmn[i][k + 1], Rmx[i][k + 1]}, i});
  }
  sort(V1.begin(), V1.end());
  sort(V2.begin(), V2.end());
  map<long long, int> vis;
  long long curS = 0;
  for (int i = 0; i < n; i++) {
    if (i && V1[i].first.first > V1[i - 1].first.second) vis[curS] = i - 1;
    curS += H[V1[i].second];
  }
  vector<char> ans(n + 1, '*');
  for (int i = 0; i < n; i++) {
    if (i && V2[i].first.first > V2[i - 1].first.second) {
      if (vis.find(curS) != vis.end()) {
        cout << "YES\n";
        for (int j = 0; j < i; j++) ans[V2[j].second] = 'R';
        for (int j = 1; j <= n; j++) cout << (ans[j] == '*' ? 'B' : 'R');
        cout << " " << k << "\n";
        return true;
      }
    }
    curS -= H[V2[i].second];
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= n; i++) {
      H[i] = rng();
    }
    cin >> n >> m;
    a = vector<vector<int> >(n + 3, vector<int>(m + 3));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    preprocess();
    bool good = false;
    for (int k = 1; k < m; k++)
      if (solve(k)) {
        good = true;
        break;
      }
    if (!good) cout << "NO\n";
  }
}
