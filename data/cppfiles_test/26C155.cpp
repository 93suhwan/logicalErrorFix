#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, fl = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fl = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * fl;
}
const int N = 110, M = 100010, mod = 1e9 + 7;
int n, m, k, top, t;
int a[N], b[N];
char s[N];
bool check(int i, int cnt1, int cnt2) {
  if (i & 1) {
    if (cnt1 - cnt2 > (10 - i + 1) / 2 || cnt2 - cnt1 > (10 - i - 1) / 2) {
      return 1;
    }
  } else {
    if (cnt1 - cnt2 > (10 - i) / 2 || cnt2 - cnt1 > (10 - i) / 2) {
      return 1;
    }
  }
  return 0;
}
int main() {
  t = read();
  while (t--) {
    scanf("%s", s + 1);
    for (int i = 1; i <= 10; i++) {
      if (s[i] == '1')
        a[i] = 1;
      else if (s[i] == '0')
        a[i] = 0;
      else
        a[i] = -1;
    }
    int ans = 10;
    for (int i = 1; i <= 10; i++) {
      if (a[i] != -1)
        b[i] = a[i];
      else {
        if (i & 1)
          b[i] = 1;
        else
          b[i] = 0;
      }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 10; i++) {
      if (i & 1)
        cnt1 += b[i];
      else
        cnt2 += b[i];
      if (check(i, cnt1, cnt2)) {
        ans = min(ans, i);
        break;
      }
    }
    for (int i = 1; i <= 10; i++) {
      if (a[i] != -1)
        b[i] = a[i];
      else {
        if (i & 1)
          b[i] = 0;
        else
          b[i] = 1;
      }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 10; i++) {
      if (i & 1)
        cnt1 += b[i];
      else
        cnt2 += b[i];
      if (check(i, cnt1, cnt2)) {
        ans = min(ans, i);
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
