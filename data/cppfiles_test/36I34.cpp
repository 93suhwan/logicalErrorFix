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
mt19937 __MT(chrono::system_clock::now().time_since_epoch().count());
const int maxn = 200000 + 10;
const int maxm = 10;
const int maxb = 130000;
const int apsz = 26;
const long long inf = 1e18;
const int mod = 1e9 + 7;
int n;
inline int check(int n) {
  int c = 1;
  int ok = 0;
  for (int i = 1; i <= 26;) {
    if (1LL * c * i >= n) ok++;
    if (ok) {
      int cnt = n / i;
      int Left = n % i;
      if (cnt % 2 == 0) {
        Left += i;
      }
      assert(Left + i <= 26);
      return 1;
    }
    ++i;
    c = c * i;
  }
  return 0;
}
inline void solve() {
  int c = 1;
  int ok = 0;
  vector<pair<int, int> > totlen;
  for (int i = 1; i <= 26;) {
    if (1LL * c * i >= n) ok++;
    if (ok) {
      int cnt = n / i;
      int Left = n % i;
      if (cnt % 2 == 0) {
        Left += i;
      }
      if (Left + i <= 26) {
        totlen.push_back({i, min(Left, n)});
      }
    }
    ++i;
    c = c * i;
  }
  sort((totlen).begin(), (totlen).end());
  int i = totlen.back().first;
  int Left = totlen.back().second;
  vector<int> p(i);
  iota((p).begin(), (p).end(), 0);
  for (int k = n / i; k; --k) {
    for (auto e : p) printf("%c", 'a' + e);
    next_permutation((p).begin(), (p).end());
  }
  for (auto o = (0); o < (Left); ++o) printf("%c", 'a' + o + i);
  puts("");
}
int main(void) {
  int T;
  scanf("%d", &(T));
  for (auto i = (1); i <= (200000); ++i) {
    if (check(i) == 0) {
      printf("%d\n", i);
    }
  }
  for (; T--;) {
    scanf("%d", &(n));
    solve();
  }
  return 0;
}
