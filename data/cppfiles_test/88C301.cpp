#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T vmin(T v) {
  return v;
}
template <typename T>
inline T vmax(T v) {
  return v;
}
template <typename T, typename... Args>
inline T vmin(T first, Args... args) {
  return min(first, (T)vmin(args...));
}
template <typename T, typename... Args>
inline T vmax(T first, Args... args) {
  return max(first, (T)vmax(args...));
}
template <typename T, typename... Args>
inline void smin(T &x, Args... args) {
  x = (T)vmin(x, args...);
}
template <typename T, typename... Args>
inline void smax(T &x, Args... args) {
  x = (T)vmax(x, args...);
}
const long double eps = 1e-15;
const int maxN = 1 * 300 + 10, mod = (int)1e9 + 7, inf = (int)1e9 + 1;
int t, n, m;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first)
    return 1;
  else if (a.first == b.first)
    return (a.second > b.second);
  else
    return 0;
}
int mat[maxN][maxN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<pair<int, int> > a(n * m);
    vector<int> b(n * m);
    for (int i = (int)(0); i < (int)(n * m); ++i) {
      cin >> a[i].first;
      a[i].second = i;
      mat[i / m][i % m] = 0;
    }
    sort(a.begin(), a.end());
    for (int i = (int)(0); i < (int)(n); ++i) {
      int start = -1;
      int end = -1;
      for (int j = (int)(0); j < (int)(m); ++j) {
        if (start == -1 && j != m - 1 &&
            a[i * m + j].first == a[i * m + j + 1].first)
          start = i * m + j;
        if (start != -1 && j != m - 1 &&
            a[i * m + j].first != a[i * m + j + 1].first) {
          end = i * m + j;
          sort(a.begin() + start, a.begin() + end + 1, cmp);
          start = -1;
        }
      }
      if (start != -1) sort(a.begin() + start, a.begin() + i * m + m, cmp);
    }
    for (int i = (int)(0); i < (int)(n * m); ++i) b[a[i].second] = i;
    long long res = 0;
    for (int i = (int)(0); i < (int)(n * m); ++i) {
      int c = b[i] / m;
      for (int j = (int)(0); j < (int)(b[i] % m); ++j)
        if (mat[c][j] == 1) res++;
      mat[c][b[i] % m] = 1;
    }
    cout << res << '\n';
  }
  return 0;
}
