#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void pr() { cout << endl; }
template <typename T1, typename... T2>
void pr(const T1& arg, const T2&... args) {
  cout << arg << " ";
  pr(args...);
}
vector<vector<int> > v;
int m, n;
bool pd(int x) {
  int book[m + 5];
  memset(book, 0, sizeof(book));
  for (int j = 1; j <= n; ++j) {
    bool flg = 0;
    for (int i = 1; i <= m; ++i) {
      if (v[i][j] >= x) {
        book[i]++;
        flg = 1;
      }
    }
    if (!flg) return 0;
  }
  for (int i = 1; i <= m; ++i) {
    if (book[i] >= 2) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    cin >> m >> n;
    v.clear();
    v.resize(m + 2, vector<int>(n + 2));
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> v[i][j];
        r = max(r, v[i][j]);
      }
    }
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (pd(m))
        l = m;
      else
        r = m - 1;
    }
    if (pd(r))
      cout << r << '\n';
    else
      cout << l << '\n';
  }
  return 0;
}
