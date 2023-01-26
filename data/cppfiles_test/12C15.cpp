#include <bits/stdc++.h>
using namespace std;
namespace {
using T = long long;
constexpr char endl = '\n';
const int maxN = 2e3 + 5;
const T inf = 1e18;
T n, m;
string line;
vector<T> pos[maxN];
struct L {
  T k, b;
};
L q[maxN];
int beg, end;
T cur[maxN];
bool judge1(const L& l1, const L& l2, T x) {
  return l1.k * x + l1.b >= l2.k * x + l2.b;
}
bool judge2(const L& l1, const L& l2, const L& l3) {
  if (l2.k > l1.k)
    return (l1.k - l3.k) * (l1.b - l2.b) >= (l2.k - l1.k) * (l3.b - l1.b);
  else
    return (l1.k - l3.k) * (l1.b - l2.b) <= (l2.k - l1.k) * (l3.b - l1.b);
}
void solve() {
  cin >> n >> m, n++, m++;
  for (T i = 0; i < n; i++) {
    cin >> line;
    for (int j = 0; j < m; j++)
      if (line[j] == '1') pos[i].push_back(j);
  }
  T ans = 0;
  for (T j = 0; j < m; j++) {
    beg = end = 0;
    for (T i = 0; i < n; i++)
      if (pos[i].size()) {
        while (cur[i] + 1 < pos[i].size() &&
               abs(pos[i][cur[i] + 1] - j) <= abs(pos[i][cur[i]] - j))
          cur[i]++;
        T y = i, x = pos[i][cur[i]];
        L l = {-2 * y, (x - j) * (x - j) + y * y};
        while (end - beg > 1 && judge2(q[end - 1], q[end - 2], l)) end--;
        q[end++] = l;
      }
    for (T i = 0; i < n; i++) {
      while (end - beg > 1 && judge1(q[beg], q[beg + 1], i)) beg++;
      ans += q[beg].k * i + q[beg].b + i * i;
    }
  }
  cout << ans << endl;
}
}  // namespace
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t(1);
  for (int i = 1; i <= t; i++) solve();
}
