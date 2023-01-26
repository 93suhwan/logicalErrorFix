#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar(), f = 0;
  for (; c < 48 || c > 57; c = getchar())
    if (!(c ^ 45)) f = 1;
  for (; c >= 48 && c <= 57; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  f ? x = -x : x;
}
template <typename T, typename... L>
inline void read(T &x, L &...l) {
  read(x), read(l...);
}
const int N = 200005;
int rs[N][2];
int n, a[N];
char ch[N];
set<int> st;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) st.insert(a[i]);
  long long sm = 0;
  for (int i = 1; i <= n; i++) {
    if (ch[i] != ch[i - 1]) {
      auto x = st.lower_bound(sm);
      if (sm >= 1000000005) return puts("-1"), 0;
      if (x == st.end()) return puts("-1"), 0;
      rs[i][0] = *x, rs[i][1] = ch[i], st.erase(x);
      continue;
    }
    rs[i][0] = *st.begin(), rs[i][1] = ch[i], st.erase(st.begin());
  }
  for (int i = 1; i <= n; i++) printf("%d %c\n", rs[i][0], rs[i][1]);
  return 0;
}
