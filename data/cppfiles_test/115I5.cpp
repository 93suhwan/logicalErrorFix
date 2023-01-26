#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long cnt1, cnt2, f = 2, f1 = 0, f2 = 0;
int a[1000005][2][2], b[1000005][2][2];
int bad[2][2];
map<pair<int, int>, int> mapp;
long long ks[1000005];
long long sq(long long x) { return x * x % 998244353; }
long long ksm(long long x) {
  if (ks[x])
    return ks[x];
  else {
    if (x % 2)
      ks[x] = sq(ksm(x / 2)) * 2;
    else
      ks[x] = sq(ksm(x / 2));
    ks[x] %= 998244353;
    return ks[x];
  }
}
void add(int x, int y, int z) {
  if (!(bad[0][1] || bad[0][0] || bad[1][0] || bad[1][1])) {
    f = 1;
  }
  bad[(x + y) % 2][z]++;
  if (bad[(x + y) % 2][z ^ 1] || bad[((x + y) % 2) ^ 1][z]) {
    f = 0;
  }
  if (!(a[x][0][0] || a[x][0][1] || a[x][1][0] || a[x][1][1])) {
    cnt1--;
  }
  a[x][y % 2][z]++;
  if ((a[x][y % 2][z ^ 1]) || (a[x][(y % 2) ^ 1][z])) {
    f1++;
  }
  if (!(b[y][0][0] || b[y][0][1] || b[y][1][0] || b[y][1][1])) {
    cnt2--;
  }
  b[y][x % 2][z]++;
  if ((b[y][x % 2][z ^ 1]) || (b[y][(x % 2) ^ 1][z])) {
    f2++;
  }
}
void del(int x, int y, int z) {
  if (!mapp[make_pair(x, y)]) {
    return;
  }
  bad[(x + y) % 2][z]--;
  if (!(bad[0][1] || bad[0][0] || bad[1][0] || bad[1][1])) {
    f = 2;
  }
  if ((bad[(x + y) % 2][z ^ 1] || bad[((x + y) % 2) ^ 1][z]) &&
      (!bad[(x + y) % 2][z])) {
    if (!bad[((x + y) % 2) ^ 1][z ^ 1]) f = 1;
  }
  a[x][y % 2][z]--;
  if (!(a[x][0][0] || a[x][0][1] || a[x][1][0] || a[x][1][1])) {
    cnt1++;
  }
  if ((a[x][y % 2][z ^ 1]) || (a[x][(y % 2) ^ 1][z])) {
    if ((a[x][y % 2][z]) == 0) {
      if ((a[x][(y % 2) ^ 1][z ^ 1]) == 0) f1--;
    }
  }
  b[y][x % 2][z]--;
  if (!(b[y][0][0] || b[y][0][1] || b[y][1][0] || b[y][1][1])) {
    cnt2++;
  }
  if (b[y][x % 2][z ^ 1] || b[y][(x % 2) ^ 1][z]) {
    if (!(b[y][x % 2][z]))
      if (!b[y][(x % 2) ^ 1][z ^ 1]) f2--;
  }
  return;
}
int main() {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(bad, 0, sizeof(bad));
  memset(ks, 0, sizeof(ks));
  cin >> n >> m >> k;
  ks[0] = 1;
  ks[1] = 2;
  cnt1 = n;
  cnt2 = m;
  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (z != -1) {
      del(x, y, mapp[make_pair(x, y)] - 1);
      mapp[make_pair(x, y)] = z + 1;
      add(x, y, z);
      cout << (ksm(cnt1) * (int)(!((bool)(f1))) +
               ksm(cnt2) * (int)(!((bool)(f2))) - f + 998244353ll) %
                  998244353
           << endl;
    } else {
      int ff = f1, zz = mapp[make_pair(x, y)] - 1;
      del(x, y, mapp[make_pair(x, y)] - 1);
      cout << (ksm(cnt1) * (int)(!((bool)(f1))) +
               ksm(cnt2) * (int)(!((bool)(f2))) - f + 998244353ll) %
                  998244353
           << endl;
      mapp[make_pair(x, y)] = 0;
    }
  }
}
