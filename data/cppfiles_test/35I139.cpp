#include <bits/stdc++.h>
using namespace std;
void dbg() { std::cout << "  #\n"; }
template <typename T, typename... Args>
void dbg(T a, Args... args) {
  std::cout << a << ' ';
  dbg(args...);
}
const int maxn = 2e5 + 10;
const int MAX = (1 << 30);
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m;
int a[maxn];
int b[maxn];
int getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
vector<pair<int, int> > allseg;
void divide(int l, int r, int L, int R, int val) {
  if (L > r || R < l) return;
  if (L <= l && r <= R) {
    l ^= val, r ^= val;
    allseg.push_back({l & r, l | r});
    return;
  }
  int mid = (l + r) >> 1;
  divide(l, mid, L, R, val);
  divide(mid + 1, r, L, R, val);
}
void solve() {
  n = getint();
  m = getint();
  allseg.clear();
  divide(0, MAX - 1, 0, m, n);
  sort((allseg).begin(), (allseg).end());
  int ans = 0;
  for (int i = 0; i < allseg.size(); i++) {
    pair<int, int> cur = allseg[i];
    if (cur.first <= ans)
      ans = max(ans, cur.second + 1);
    else {
      cout << (ans) << endl;
      return;
    }
  }
}
signed main() {
  int TestCase = 1;
  cin >> TestCase;
  while (TestCase--) {
    solve();
  }
  char EndFile = getchar();
  EndFile = getchar();
  return 0;
}
