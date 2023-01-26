#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chkmin(T& x, T y) {
  if (x > y) x = y;
}
inline int read() {
  bool f = 0;
  int x = 0;
  char c = getchar();
  while (c < 48) f |= c == '-', c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return f ? -x : x;
}
void write$(int x) {
  if (x > 9) write$(x / 10);
  putchar(x % 10 | 48);
}
void write(int x) {
  if (x < 0) x = -x, putchar('-');
  write$(x);
}
const int maxn = 1e5 + 10;
int n, m, A[99999], mp[305][305];
map<int, vector<int>> S;
void solve() {
  S.clear();
  cin >> n >> m;
  for (int i = (1), iend = (n * m); i <= iend; ++i)
    A[i] = read(), S[A[i]].push_back(i);
  int x = 1, y = 1;
  for (int T = (1), Tend = (n * m); T <= Tend; ++T) {
    auto it = S.begin();
    vector<int>& vec = it->second;
    int sz = vec.size();
    if (sz <= m - y + 1) {
      reverse(vec.begin(), vec.end());
      for (int t : vec) {
        T++;
        mp[x][y] = t;
        y++;
      }
      if (y > m) x++, y = 1;
      S.erase(S.begin());
      T--;
      continue;
    }
    vector<int> ano;
    for (int i = (0), iend = (m - y); i <= iend; ++i) {
      mp[x][y + i] = vec[m - y - i];
      T++;
    }
    for (int i = (m - y + 1), iend = (vec.size() - 1); i <= iend; ++i)
      ano.push_back(vec[i]);
    T--;
    x++, y = 1;
    vec = ano;
  }
  int ans = 0;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    for (int j = (1), jend = (m); j <= jend; ++j) {
      for (int k = (1), kend = (j - 1); k <= kend; ++k)
        ans += mp[i][k] < mp[i][j];
    }
  }
  cout << ans << endl;
}
signed main() {
  int T = read();
  while (T--) solve();
  return 0;
}
