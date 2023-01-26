#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, P1 = 1e9 + 7, P2 = 1e9 + 9;
int n, m;
char s[N], num[N];
pair<int, int> h1[N], h2[N], p10[N], ip10[N];
map<pair<int, int>, int> pos;
int power(int a, int b, int P, int c = 1) {
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) c = 1ll * c * a % P;
  return c;
}
const pair<int, int> B = {10, 10};
const pair<int, int> iB = {power(10, P1 - 2, P1), power(10, P2 - 2, P2)};
pair<int, int> operator+(const pair<int, int> a, const pair<int, int> b) {
  return {(a.first + b.first) % P1, (a.second + b.second) % P2};
}
pair<int, int> operator-(const pair<int, int> a, const pair<int, int> b) {
  return {(a.first - b.first + P1) % P1, (a.second - b.second + P2) % P2};
}
pair<int, int> operator*(const pair<int, int> a, const pair<int, int> b) {
  return {1ll * a.first * b.first % P1, 1ll * a.second * b.second % P2};
}
pair<int, int> query(int l, int r) {
  return h1[r] - h1[l - 1] * p10[r - l + 1];
}
int LCP(int first, int second) {
  int l = 1, r = min(n - first + 1, m - second + 1), best = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (query(first, first + mid - 1) ==
        h2[second + mid] - h2[second - 1] * p10[mid + 1])
      best = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return best;
}
void check(int len) {
  if (len == 0) return;
  for (int i = 1; i + len - 1 <= n; i++) {
    int lcp = len - min(len, LCP(i, 1));
    for (int j = max(1, lcp - 1); j <= lcp && i + len + j - 1 <= n; j++) {
      if (query(i, i + len - 1) + query(i + len, i + len + j - 1) == h2[m]) {
        printf("%d %d\n%d %d\n", i, i + len - 1, i + len, i + len + j - 1);
        exit(0);
      }
    }
    for (int j = max(1, lcp - 1); j <= lcp && i - j >= 1; j++) {
      if (query(i, i + len - 1) + query(i - j, i - 1) == h2[m]) {
        printf("%d %d\n%d %d\n", i - j, i - 1, i, i + len - 1);
        exit(0);
      }
    }
  }
  return;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p10[0] = {1, 1};
  ip10[0] = {1, 1};
  for (int i = 1; i <= n; i++)
    p10[i] = p10[i - 1] * B, ip10[i] = ip10[i - 1] * iB;
  for (int i = 1; i <= n; i++) {
    int c = s[i] - '0';
    h1[i] = h1[i - 1] * B + pair<int, int>{c, c};
  }
  scanf("%s", num + 1);
  m = strlen(num + 1);
  for (int i = 1; i <= m; i++) {
    int c = num[i] - '0';
    h2[i] = h2[i - 1] * B + pair<int, int>{c, c};
  }
  check(m);
  check(m - 1);
  return 0;
}
