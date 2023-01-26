#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline int read() {
  char ch;
  bool sign = 0;
  int res = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = 1;
  while (isdigit(ch)) res = res * 10 + (ch ^ 48), ch = getchar();
  if (sign)
    return -res;
  else
    return res;
}
const int maxn = 200000 + 10;
const int maxm = 10000;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int apsz = 26;
int a[maxn], n;
inline long long solve() {
  int cnt[2] = {0, 0};
  for (int i = (0); i < (n); ++i) {
    if (a[i] < 2) cnt[a[i]]++;
  }
  if (cnt[1] == 0) return 0;
  return cnt[1] * (1LL << cnt[0]);
}
int main(void) {
  int T;
  scanf("%d", &(T));
  for (; T--;) {
    scanf("%d", &(n));
    for (int i = (0); i < (n); ++i) {
      scanf("%d", &(a[i]));
    }
    printf("%lld\n", solve());
  }
  return 0;
}
