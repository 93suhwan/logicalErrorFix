#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T1, typename T2>
inline void remin(T1& a, T2 b) {
  a = min(a, (T1)b);
}
template <typename T1, typename T2>
inline void remax(T1& a, T2 b) {
  a = max(a, (T1)b);
}
const int maxN = 1 << 19;
char A[maxN], S[maxN];
void solve() {
  long long a, s;
  scanf("%lld%lld", &a, &s);
  string B;
  for (; a != 0; a /= 10) {
    if (s == 0) {
      printf("-1\n");
      return;
    }
    int c = a % 10, d = s % 10;
    s /= 10;
    if (d < c) {
      if (s % 10 != 1) {
        printf("-1\n");
        return;
      }
      d += 10;
      s /= 10;
    }
    B.push_back('0' + (d - c));
  }
  if (s == 0)
    while (((int)(B).size()) > 1 and B.back() == '0') B.pop_back();
  reverse((B).begin(), (B).end());
  if (s != 0) printf("%lld", s);
  printf("%s\n", B.c_str());
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (auto tid = (1); tid < (t + 1); tid++) {
    solve();
  }
  return 0;
}
