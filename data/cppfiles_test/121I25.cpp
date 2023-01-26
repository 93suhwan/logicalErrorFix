#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 1e6 + 10;
int n;
char s[N], t[N];
int tot[2], fl[2];
void solve() {
  n = read<int>();
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  bool tfl = 1;
  for (int i = (1); i <= (n); i++) tfl &= (s[i] == t[i]);
  if (tfl) return puts("0"), void();
  tot[0] = tot[1] = fl[0] = fl[1] = 0;
  for (int i = (1); i <= (n); i++) {
    if (s[i] == t[i]) {
      tot[0]++;
      fl[0] |= s[i] == '1';
    } else {
      tot[1]++;
      fl[1] |= s[i] == '1';
    }
  }
  int ans = 1e9;
  if (fl[0]) chkmin(ans, tot[0]);
  if (fl[1]) chkmin(ans, tot[1]);
  if (ans == 1e9) ans = -1;
  printf("%d\n", ans);
}
int main() {
  int T = read<int>();
  while (T--) solve();
  return 0;
}
