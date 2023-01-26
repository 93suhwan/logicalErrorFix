#include <bits/stdc++.h>
using namespace std;
long long a, b;
long double an = 10000000000000000, eps = 1e-10;
struct p {
  long double q, w;
  bool fl;
} l[200001];
long double slope(long long qq, long long ww) {
  return (long double)(l[qq].w - l[ww].w) / (l[qq].q - l[ww].q) * 1.0000000000;
}
long double dis(long long qq, long long ww) {
  return sqrt((l[qq].q - l[ww].q) * (l[qq].q - l[ww].q) +
              (l[qq].w - l[ww].w) * (l[qq].w - l[ww].w));
}
bool cmp(p qq, p ww) { return qq.q < ww.q; }
int main() {
  scanf("%lld%lld", &a, &b);
  for (int i = 1; i <= a; i++) {
    scanf("%Lf%Lf", &l[i].q, &l[i].w);
  }
  swap(l[b], l[1]);
  l[1].fl = 1;
  if (a == 3) {
    printf("%.6Lf", min(dis(1, 2) + dis(2, 3), dis(1, 3) + dis(3, 2)));
    return 0;
  }
  long long tt = 0;
  long double xl = 0;
  for (int i = 2; i < a; i++) {
    if (fabs(slope(i, i - 1) - slope(i, i + 1)) <= eps) {
      tt = i;
      xl = slope(i, i - 1);
      break;
    }
    if (i >= 3 && (fabs(slope(i, i - 1) - slope(i, i - 2)) <= eps ||
                   fabs(slope(i, i + 1) == slope(i, i - 2)) <= eps)) {
      tt = i;
      xl = slope(i, i - 2);
      break;
    }
    if (i < a - 1 && (fabs(slope(i, i - 1) - slope(i, i + 2)) <= eps ||
                      fabs(slope(i, i + 1) == slope(i, i + 2)) <= eps)) {
      tt = i;
      xl = slope(i, i + 2);
      break;
    }
  }
  long long bb = 0;
  for (int i = 1; i <= a; i++) {
    if (i == tt) continue;
    if (abs(slope(i, tt) - xl) > eps) {
      bb = i;
      break;
    }
  }
  swap(l[a], l[bb]);
  sort(l + 1, l + a, cmp);
  if (!bb)
    while (1)
      ;
  if (l[a].fl == 1) {
    while (1)
      ;
    an = min(an, min(dis(a, 1) + dis(1, a - 1), dis(a, a - 1) + dis(a - 1, 1)));
    printf("%.6Lf", an);
    return 0;
  }
  for (int i = 1; i < a; i++) {
    if (l[i].fl == 1) b = i;
  }
  if (b == 1) {
    an = min(an, dis(1, a) + dis(a, a - 1) + dis(a - 1, b + 1));
    an = min(an, dis(1, a - 1) + dis(a - 1, a));
    printf("%.6Lf", an);
    return 0;
  }
  if (b == a - 1) {
    an = min(an, dis(a - 1, a) + dis(a, 1) + dis(1, b - 1));
    an = min(an, dis(a - 1, 1) + dis(1, a));
    printf("%.6Lf", an);
    return 0;
  }
  for (int i = 1; i <= b; i++) {
    long double gg = dis(b, i) + dis(i, a) + dis(i - 1, a) + dis(i - 1, 1) +
                     dis(1, b) + dis(b, a - 1);
    if (i > 1) an = min(an, gg);
    gg = dis(b, i) + dis(i, a) + dis(a, 1) + dis(1, a - 1);
    an = min(an, gg);
  }
  for (int i = b; i < a; i++) {
    long double gg = dis(b, 1) + dis(1, b) + dis(b, i - 1) + dis(i - 1, a) +
                     dis(a, i) + dis(i, a - 1);
    if (i > b) an = min(an, gg);
    gg = dis(b, 1) + dis(1, a) + dis(a, i) + dis(i, b + 1) + dis(b + 1, i) +
         dis(i, a - 1);
    if (i > b) an = min(an, gg);
    gg = dis(b, i - 1) + dis(i - 1, b) + dis(b, 1) + dis(1, a) + dis(a, a - 1) +
         dis(a - 1, i);
    if (i > b) an = min(an, gg);
    gg = dis(b, 1) + dis(1, b) + dis(b, i - 1) + dis(i - 1, a) + dis(a, a - 1) +
         dis(a - 1, i);
    if (i > b) an = min(an, gg);
  }
  an = min(an, dis(1, b) + dis(1, a - 1) + dis(a - 1, a));
  for (int i = b; i < a; i++) {
    long double gg = dis(b, i - 1) + dis(i - 1, a) + dis(a, i) + dis(i, a - 1) +
                     dis(1, a - 1);
    if (i > b) an = min(an, gg);
    gg = dis(b, i) + dis(i, a) + dis(a, a - 1) + dis(1, a - 1);
    an = min(an, gg);
  }
  for (int i = 1; i <= b; i++) {
    long double gg = dis(a - 1, b) * 2 + dis(b, i) + dis(i, a) + dis(a, i - 1) +
                     dis(1, i - 1);
    if (i > 1) an = min(an, gg);
    gg = dis(b, a - 1) + dis(a - 1, a) + dis(a, i) + dis(i, b - 1) * 2 +
         dis(1, i);
    if (i < b) an = min(an, gg);
    gg = dis(b, a - 1) + dis(a - 1, a) + dis(a, 1) + dis(i + 1, b) * 2 +
         dis(1, i);
    if (i < b) an = min(an, gg);
    gg = dis(a - 1, b) * 2 + dis(b, i) + dis(i, a) + dis(a, 1) + dis(1, i - 1);
    if (i > 1) an = min(an, gg);
  }
  an = min(an, dis(a - 1, b) + dis(1, a - 1) + dis(1, a));
  an = min(an, dis(b, a) + dis(a, 1) + dis(1, a - 1));
  an = min(an, dis(b, a) + dis(a, a - 1) + dis(1, a - 1));
  printf("%.6Lf", an);
  return 0;
}
