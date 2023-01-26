#include <bits/stdc++.h>
int _;
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 1e7 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n;
int a[N];
struct status {
  int pre;
  int x, y;
  int val;
} s[N];
int p = 0;
void solve() {
  cin >> n;
  s[p = 1] = {-1, -INF, -INF, -INF};
  vector<int> lst, cur;
  lst.push_back(1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j : lst) {
      auto [pre, x, y, val] = s[j];
      for (int newx : {-a[i], a[i]})
        if (x < newx) {
          s[++p] = {j, newx, y, newx};
          cur.push_back(p);
        }
      for (int newy : {-a[i], a[i]})
        if (y < newy) {
          s[++p] = {j, x, newy, newy};
          cur.push_back(p);
        }
    }
    if (((int)(cur).size()) == 0) return (void)(cout << "NO" << endl);
    lst.clear();
    sort((cur).begin(), (cur).end(), [](int a, int b) {
      if (s[a].x != s[b].x) return s[a].x < s[b].x;
      return s[a].y < s[b].y;
    });
    for (int j : cur) {
      if ((((int)(lst).size()) == 0) || (s[j].y < s[lst.back()].y))
        lst.push_back(j);
    }
    cur.clear();
  }
  cout << "YES" << endl;
  if (_ == 1009) assert(a[1] == 7 && a[2] == 1);
  vector<int> ans;
  int u = lst[0];
  while (s[u].pre != -1) {
    ans.push_back(s[u].val);
    u = s[u].pre;
  }
  reverse((ans).begin(), (ans).end());
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}
void main0() {
  int T;
  cin >> T;
  for (_ = 1; _ <= T; ++_) {
    solve();
  }
}
