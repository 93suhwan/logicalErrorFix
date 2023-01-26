#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void eras(map<int, int> &m, int x) {
  m[x]--;
  if (!m[x]) m.erase(x);
}
const int N = (int)2e5 + 100;
const int M = (int)2e7 + 10;
const long long inf = (long long)1e18 + 10000;
const double eps = 1e-9;
bool a[N];
int b[N];
bool q(int x, int y, int z) {
  cout << "? " << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
  bool d;
  cin >> d;
  return d;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, i;
    cin >> n;
    for ((i) = 0; (i) < (n); (i)++) b[i] = -1;
    int x, y;
    for (int i = 0; i < n; i += 3) {
      a[i] = q(i, i + 1, i + 2);
      if (!a[i]) x = i;
      if (a[i]) y = i;
    }
    int z = -1, o = -1;
    for ((i) = 0; (i) < (3); (i)++) {
      if (!q(y, y + 1, x + i)) {
        b[x + i] = 0;
        b[y + 2] = 1;
        z = x + i;
        o = y + 2;
        for ((i) = 0; (i) < (3); (i)++) {
          if (x + i != z) b[x + i] = q(z, o, x + i);
          if (y + i != o) b[y + i] = q(z, o, y + i);
        }
        break;
      }
    }
    if (z == -1) {
      o = y;
      b[y] = 1;
      b[y + 1] = 1;
      if (q(x, x + 1, o)) {
        b[x + 2] = 0;
        z = x + 2;
        for ((i) = 0; (i) < (2); (i)++) {
          b[x + i] = q(z, o, x + i);
        }
      } else {
        b[x] = 0;
        b[x + 1] = 0;
        z = x;
        b[x + 2] = q(z, o, x + 2);
      }
      b[y + 2] = q(z, o, y + 2);
    }
    for (int i = 0; i < n; i += 3) {
      if (i == x || i == y) continue;
      if (a[i]) {
        if (q(i, i + 1, z)) {
          b[i] = 1;
          b[i + 1] = 1;
          b[i + 2] = q(z, o, i + 2);
        } else {
          b[i] = q(z, o, i);
          b[i + 1] = !b[i];
          b[i + 2] = 1;
        }
      } else {
        if (q(i, i + 1, o)) {
          b[i] = q(z, o, i);
          b[i + 1] = !b[i];
          b[i + 2] = 0;
        } else {
          b[i] = 0;
          b[i + 1] = 0;
          b[i + 2] = q(z, o, i + 2);
        }
      }
    }
    int ans = 0;
    for ((i) = 0; (i) < (n); (i)++) {
      if (!b[i]) ans++;
    }
    cout << "! " << ans << ' ';
    for ((i) = 0; (i) < (n); (i)++) {
      if (!b[i]) cout << i + 1 << ' ';
    }
    cout << endl;
  }
}
