#include <bits/stdc++.h>
using namespace std;
const int M = 4;
const int maxn = 5e5 + 5;
char s[maxn], x[maxn];
array<int, M> mod = {1000000007, 10001347, 998244353, 99999721};
array<int, M> pw[maxn], sm[maxn];
int z[maxn];
array<int, M> operator%(const array<int, M> a, const array<int, M> b) {
  array<int, M> res;
  for (int i = 0; i < M; ++i) res[i] = a[i] % b[i];
  return res;
}
array<int, M> operator+(const array<int, M> x, const array<int, M> y) {
  array<int, M> res;
  for (int i = 0; i < M; ++i) {
    res[i] = x[i] + y[i];
    if (res[i] >= mod[i]) res[i] -= mod[i];
  }
  return res;
}
array<int, M> operator*(const array<int, M> a, const array<int, M> b) {
  array<int, M> res;
  for (int i = 0; i < M; ++i) res[i] = 1ll * a[i] * b[i] % mod[i];
  return res;
}
array<int, M> operator-(const array<int, M> x, const array<int, M> y) {
  array<int, M> res;
  for (int i = 0; i < M; ++i) {
    res[i] = x[i] - y[i];
    if (res[i] < 0) res[i] += mod[i];
  }
  return res;
}
array<int, M> tra(int x) { return {x, x, x}; }
array<int, M> get(int l, int r) { return sm[r] - sm[l - 1] * pw[r - l + 1]; }
void print(array<int, M> x) { printf("(%d,%d,%d)", x[0], x[1], x[2]); }
int main() {
  scanf("%s%s", s + 1, x + 1);
  int lens = strlen(s + 1);
  int lenx = strlen(x + 1);
  array<int, M> c10 = {10, 10, 10};
  pw[0] = tra(1);
  for (int i = 1; i <= lens; ++i) {
    pw[i] = pw[i - 1] * c10;
  }
  sm[0] = tra(0);
  for (int i = 1; i <= lens; ++i) {
    sm[i] = sm[i - 1] * c10 + tra(s[i] - '0');
  }
  array<int, M> ans = tra(0);
  for (int i = 1; i <= lenx; ++i) {
    ans = ans * c10 + tra(x[i] - '0');
  }
  for (int i = 1; i <= lens; ++i) {
    if (i + (lenx << 1) - 3 > lens) break;
    if (get(i, i + lenx - 2) + get(i + lenx - 1, i + (lenx << 1) - 3) == ans) {
      printf("%d %d\n%d %d\n", i, i + lenx - 2, i + lenx - 1,
             i + (lenx << 1) - 3);
      return 0;
    }
  }
  int l = 0, r = 0;
  z[1] = lenx;
  for (int i = 2; i <= lenx; ++i) {
    int j = 0;
    if (r < i) {
      r = i - 1;
      while (r + 1 <= lenx && x[r + 1] == x[j + 1]) j++, r++;
      l = i;
    } else {
      if (z[i - l + 1] < r - i + 1)
        z[i] = z[i - l + 1];
      else {
        r = r - i + 1;
        while (r + 1 <= lenx && x[r + 1] == x[j + 1]) j++, r++;
        l = i;
      }
    }
    z[i] = j;
  }
  l = 0, r = 0;
  for (int i = 1; i <= lens; ++i) {
    int len = 0;
    if (r < i) {
      r = i - 1;
      while (r + 1 <= lens && len + 1 <= lenx && s[r + 1] == x[len + 1])
        len++, r++;
      l = i;
    } else {
      if (z[i - l + 1] < r - i + 1)
        len = z[i - l + 1];
      else {
        len = r - i + 1;
        while (r + 1 <= lens && len + 1 <= lenx && s[r + 1] == x[len + 1])
          len++, r++;
        l = i;
      }
    }
    for (int j = lenx - len - 1; j <= lenx - len; ++j) {
      if (i + lenx + j - 1 > lens) break;
      if (get(i, i + lenx - 1) + get(i + lenx, i + lenx + j - 1) == ans) {
        printf("%d %d\n%d %d\n", i, i + lenx - 1, i + lenx, i + lenx + j - 1);
        return 0;
      }
      if (i - j <= 0) continue;
      if (get(i, i + lenx - 1) + get(i - j, i - 1) == ans) {
        printf("%d %d\n%d %d\n", i - j, i - 1, i, i + lenx - 1);
        return 0;
      }
    }
  }
}
