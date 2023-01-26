#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
using db = double;
using u32 = unsigned int;
using u64 = unsigned long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
using pqi = priority_queue<int>;
using si = set<int>;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
template <class T>
inline bool chkmin(T& a, T b) {
  return b < a ? a = b, true : false;
}
template <class T>
inline bool chkmax(T& a, T b) {
  return a < b ? a = b, true : false;
}
int _w, _t;
FILE* _f;
int n, cnt[26], ans, tmp;
char s[55];
void solve() {
  ans = 0;
  tmp = 0;
  memset(cnt, 0, sizeof cnt);
  scanf("%s", s + 1);
  n = (int)strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    ++cnt[s[i] - 'a'];
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 1) {
      ++ans;
    } else if (cnt[i]) {
      ++tmp;
    }
  }
  ans += tmp >> 1;
  printf("%d\n", ans);
}
int main() {
  _w = scanf("%d", &_t);
  while (_t--) solve();
  return 0;
}
