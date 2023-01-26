#include <bits/stdc++.h>
using namespace std;
const int MX = 100005, inf = 2e9;
int n;
vector<vector<int> > a, b;
bool f(vector<vector<int> > &v, vector<int> &ord, int m, int d, int lvl = 0,
       int x1 = -inf, int y1 = -inf, int x2 = inf, int y2 = inf) {
  if (lvl == 3) return 1;
  int cn = 0;
  for (int i = (d == 1 ? 0 : n - 1); 0 <= i && i < n; i += d)
    if (v[i][2] == ord[lvl]) {
      if (v[i][0] < x1 || x2 < v[i][0]) continue;
      if (v[i][1] < y1 || y2 < v[i][1]) continue;
      cn++;
      if (cn >= m) {
        int nx1 = &v == &a && d == 1 ? v[i][0] + 1 : x1;
        int ny1 = &v == &b && d == 1 ? v[i][1] + 1 : y1;
        int nx2 = &v == &a && d == -1 ? v[i][0] - 1 : x2;
        int ny2 = &v == &b && d == -1 ? v[i][1] - 1 : y2;
        if (f(&v == &b ? a : b, ord, m, 1, lvl + 1, nx1, ny1, nx2, ny2))
          return 1;
        if (lvl) break;
        if (f(v, ord, m, 1, lvl + 1, nx1, ny1, nx2, ny2)) return 1;
        break;
      }
    }
  return 0;
}
void main_() {
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    int x, y, c;
    cin >> x >> y >> c;
    a.push_back({x, y, c});
    b.push_back({x, y, c});
  }
  sort(a.begin(), a.end(),
       [&](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });
  sort(b.begin(), b.end(),
       [&](const vector<int> &x, const vector<int> &y) { return x[1] < y[1]; });
  int i = 0, j = n / 3, rep = 18;
  while (rep--) {
    int m = (i + j + 1) / 2, esPos = 0;
    vector<int> ord = {1, 2, 3};
    do {
      esPos |= f(a, ord, m, 1);
      esPos |= f(a, ord, m, -1);
      esPos |= f(b, ord, m, 1);
      esPos |= f(b, ord, m, -1);
    } while (next_permutation(ord.begin(), ord.end()));
    if (esPos)
      i = m;
    else
      j = m;
  }
  cout << 3 * i << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}
