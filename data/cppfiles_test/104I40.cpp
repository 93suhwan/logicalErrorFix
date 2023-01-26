#include <bits/stdc++.h>
using namespace std;
struct bl {
  int a;
  int b;
  int pos;
  int am;
  int bm;
};
bool comp1(bl x, bl y) { return x.a < y.a; }
bool comp2(bl x, bl y) { return x.b < y.b; }
bool comp3(bl x, bl y) { return x.pos < y.pos; }
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<bl> v(n);
  int64_t suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &v[i].a, &v[i].b);
    suma += v[i].a;
    sumb += v[i].b;
    v[i].pos = i;
  }
  int64_t d = abs(sumb - suma);
  if (suma > sumb) {
    sort(v.begin(), v.end(), comp1);
    for (int i = 0; i < n; ++i) {
      int fish = min(v[i].a, m);
      int meet = m - fish;
      if (fish - meet > d) {
        fish = min(fish, (int)d);
        fish += min(v[i].a - fish, (m - fish) / 2);
      }
      meet = min(m - fish, v[i].b);
      fish = m - meet;
      d -= (fish - meet);
      v[i].am = fish;
      v[i].bm = meet;
    }
    int i = 0;
    while (i < n && d < 0) {
      int meet = min(v[i].am, v[i].b - v[i].bm);
      if (abs(d / 2) + abs(d % 2) < meet) {
        meet = abs(d / 2) + abs(d % 2);
      }
      v[i].bm += meet;
      v[i].am -= meet;
      i++;
      d += meet * 2;
    }
  } else {
    sort(v.begin(), v.end(), comp2);
    for (int i = 0; i < n; ++i) {
      int meet = min(v[i].b, m);
      int fish = m - meet;
      if ((meet - fish) > d) {
        meet = min(meet, (int)d);
        meet += min(v[i].b - meet, (m - meet) / 2);
      }
      fish = min(m - meet, v[i].a);
      meet = m - fish;
      d -= (meet - fish);
      v[i].am = fish;
      v[i].bm = meet;
    }
    int i = 0;
    while (i < n && d < 0) {
      int fish = min(v[i].bm, v[i].a - v[i].am);
      if (abs(d / 2) + abs(d % 2) < fish) {
        fish = abs(d / 2) + abs(d % 2);
      }
      v[i].am += fish;
      v[i].bm -= fish;
      i++;
      d += fish * 2;
    }
  }
  printf("%lld\n", abs(d));
  sort(v.begin(), v.end(), comp3);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", v[i].am, v[i].bm);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
