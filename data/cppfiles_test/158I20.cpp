#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
const int maxm = 1e4 + 1;
int x[maxn];
int s[maxn][maxm];
pair<int, int> y[maxm];
int an[maxm];
int mx = 0;
void gen(int n, int m, int id, string &t) {
  if (id == n) {
    for (int j = 0; j < m; ++j) {
      y[j].first = 0;
      y[j].second = j;
    }
    long long cst = 0;
    for (int i = 0; i < n; ++i) {
      if (t[i] == '+')
        cst += (long long)x[i];
      else
        cst -= (long long)x[i];
      for (int j = 0; j < m; ++j) {
        if (s[i][j] != 1) continue;
        if (t[i] == '+')
          y[j].first--;
        else
          y[j].first++;
      }
    }
    sort(y, y + m);
    int a[maxm];
    for (int i = 0; i < m; ++i) {
      a[y[i].second] = i + 1;
      cst += (long long)(i + 1) * (long long)y[i].first;
    }
    if (cst > mx) {
      mx = cst;
      swap(a, an);
    }
    return;
  }
  t += '+';
  gen(n, m, id + 1, t);
  t.pop_back();
  t += '-';
  gen(n, m, id + 1, t);
  t.pop_back();
  return;
}
void solve() {
  int n, m;
  cin >> n >> m;
  mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    string ss;
    cin >> ss;
    for (int j = 0; j < m; ++j) {
      s[i][j] = (ss[j] == '1');
    }
  }
  string tmp = "";
  gen(n, m, 0, tmp);
  for (int i = 0; i < m; ++i) cout << an[i] << " ";
  cout << "\n";
  return;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
