#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int dd[2][2][2][2];
int emul(int p1, int p2, int d1, int d2, int n) {
  std::vector<int> p(2), d(2);
  p[0] = p1;
  p[1] = p2;
  d[0] = d1;
  d[1] = d2;
  std::vector<int> del(n, 0);
  int left = n;
  int mv = 0;
  if (n > 1)
    while (1) {
      if (p[0] == p[1] && del[p[0]] == 0) {
        del[p[0]] = 1;
        left--;
        if (left == 1) break;
      }
      if (p[mv] + d[mv] < 0 || p[mv] + d[mv] >= n) {
        d[mv] = -d[mv];
      } else {
        p[mv] += d[mv];
        if (del[p[mv]] == 0) mv = 1 - mv;
      }
    }
  int pt = 0;
  while (del[pt]) pt++;
  return pt;
}
int sclean(int p, int d, int n) {
  if (p == 0) return n - 1;
  if (p == n - 1) return 0;
  int np2 = n % 2;
  int flux = 0;
  if (p * 2 >= n) {
    p = n - 1 - p;
    d = -d;
    flux = 1;
  }
  int e2 = p % 2;
  int m2 = (n / 2 - 1 - p) % 2;
  return (n - 1) * (flux ^ dd[np2][e2][m2][(d + abs(d)) / 2]);
}
int solve(int p1, int p2, int d1, int d2, int n) {
  if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
  if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
  if (p1 == p2) {
    if (d1 == d2) {
      if (p1 == 0)
        return n - 1;
      else if (p1 == n - 1)
        return 0;
      else if (d1 == 1)
        return 0;
      else
        return n - 1;
    } else
      return sclean(p1, d1, n);
  } else if (p1 + d1 == p2) {
    p1 += d1;
    swap(p1, p2);
    swap(d1, d2);
    if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
    if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
    if (d1 == d2) {
      if (p1 == 0)
        return n - 1;
      else if (p1 == n - 1)
        return 0;
      else if (d1 == 1)
        return 0;
      else
        return n - 1;
    } else
      return sclean(p1, d1, n);
  } else {
    if (d1 < d2 && p1 < p2) {
      int ms = min(p1, n - 1 - p2);
      p1 -= ms;
      p2 += ms;
      if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
      if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
    }
    if (d2 < d1 && p2 < p1) {
      int ms = min(p2, n - 1 - p1);
      p1 += ms;
      p2 -= ms;
      if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
      if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
    }
    if (d1 == d2) {
      if (d1 == -1) {
        int ms = min(p1, p2);
        p1 -= ms;
        p2 -= ms;
        if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
        if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
      } else {
        int ms = min(n - 1 - p1, n - 1 - p2);
        p1 += ms;
        p2 += ms;
        if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
        if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
      }
    }
    int stf = abs(p2 - p1) / 2;
    p1 += stf * d1;
    p2 += stf * d2;
    if (p1 != p2) {
      p1 += d1;
      swap(d1, d2);
    }
    if (d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
    if (d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
    return sclean(p1, d1, n);
  }
}
int main() {
  for (int np2 = 0; np2 < 2; np2++) {
    for (int e2 = 0; e2 < 2; e2++) {
      for (int m2 = 0; m2 < 2; m2++) {
        for (int dir = 0; dir < 2; dir++) {
          int pos = 2 + e2;
          int n = 2 * (pos + m2) + np2;
          int rd = -1;
          if (dir) rd = 1;
          dd[np2][e2][m2][dir] = emul(pos, pos, rd, -rd, n);
          if (dd[np2][e2][m2][dir] > 0) dd[np2][e2][m2][dir] = 1;
        }
      }
    }
  }
  int ta;
  cin >> ta;
  string s;
  while (ta--) {
    int a, b, n;
    cin >> a >> b >> n;
    cin >> s;
    int d1 = -1;
    if (s[0] == 'r') d1 = 1;
    cin >> s;
    int d2 = -1;
    if (s[0] == 'r') d2 = 1;
    printf("%d\n", solve(a, b, d1, d2, n));
  }
}
