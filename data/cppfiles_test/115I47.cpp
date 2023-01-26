#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int cnt1, cnt2, f = 2, f1 = 1, f2 = 1;
int a[1000005][2][2], b[1000005][2][2];
int bad[2][2];
map<pair<int, int>, int> mapp;
void add(int x, int y, int z) {
  if (!(bad[0][1] || bad[0][0] || bad[1][0] || bad[1][1])) {
    f--;
  }
  bad[(x + y) % 2][z]++;
  if (bad[(x + y) % 2][z ^ 1] || bad[((x + y) % 2) ^ 1][z]) {
    f = 0;
  }
  if (!(a[x][0][0] || a[x][0][1] || a[x][1][0] || a[x][1][1])) {
    cnt1 /= 2;
  }
  a[x][y % 2][z]++;
  if (a[x][y % 2][z ^ 1] || a[x][(y % 2) ^ 1][z]) {
    f1 = 0;
  }
  if (!(b[y][0][0] || b[y][0][1] || b[y][1][0] || b[y][1][1])) {
    cnt2 /= 2;
  }
  b[y][x % 2][z]++;
  if (b[y][x % 2][z ^ 1] || b[y][(x % 2) ^ 1][z]) {
    f2 = 0;
  }
}
void del(int x, int y, int z) {
  bad[(x + y) % 2][z]--;
  if (!(bad[0][1] || bad[0][0] || bad[1][0] || bad[1][1])) {
    f = 2;
  }
  if (bad[(x + y) % 2][z ^ 1] || bad[((x + y) % 2) ^ 1][z]) {
    f++;
  }
  a[x][y % 2][z]--;
  if (!(a[x][0][0] || a[x][0][1] || a[x][1][0] || a[x][1][1])) {
    cnt1 *= 2;
  }
  if (a[x][y % 2][z ^ 1] || a[x][(y % 2) ^ 1][z]) {
    f1 = 1;
  }
  b[y][x % 2][z]--;
  if (!(b[y][0][0] || b[y][0][1] || b[y][1][0] || b[y][1][1])) {
    cnt2 *= 2;
  }
  if (b[y][x % 2][z ^ 1] || b[y][(x % 2) ^ 1][z]) {
    f2 = 1;
  }
}
int main() {
  cin >> n >> m >> k;
  cnt1 = (1 << n);
  cnt2 = (1 << m);
  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (z != -1) {
      if (mapp[make_pair(x, y)]) {
        del(x, y, mapp[make_pair(x, y)]);
      }
      mapp[make_pair(x, y)] = z;
      add(x, y, z);
      cout << cnt1 * f1 + cnt2 * f2 - f << endl;
    } else {
      del(x, y, mapp[make_pair(x, y)]);
      mapp[make_pair(x, y)] = 0;
      cout << cnt1 * f1 + cnt2 * f2 - f << endl;
    }
  }
}
