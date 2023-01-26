#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 1e6 + 5;
const int MOD = 998244353;
int n, m, k, type[N], ty[N], av[4], ay[4], aa[4];
set<int> v[N][2], acv[N][2];
int mi[N];
void premi() {
  mi[0] = 1;
  for (int i = 1; i <= N - 1; i++) {
    mi[i] = 1ll * mi[i - 1] * 2 % MOD;
  }
}
int main() {
  premi();
  n = read();
  m = read();
  k = read();
  int result = 1;
  for (int i = 1; i <= n; i++) {
    type[i] = 2;
  }
  for (int i = 1; i <= m; i++) {
    ty[i] = 2;
  }
  av[2] = n;
  ay[2] = m;
  int x, y, t;
  while (k--) {
    x = read();
    y = read();
    t = read();
    if (t == -1) {
      v[x][0].erase(y);
      v[x][1].erase(y);
      acv[y][0].erase(x);
      acv[y][1].erase(x);
    } else if (t == 0) {
      if (y & 1) {
        v[x][0].insert(y);
        v[x][1].erase(y);
      } else {
        v[x][1].insert(y);
        v[x][0].erase(y);
      }
      if (x & 1) {
        acv[y][0].insert(x);
        acv[y][1].erase(x);
      } else {
        acv[y][1].insert(x);
        acv[y][0].erase(x);
      }
    } else {
      if (y & 1) {
        v[x][1].insert(y);
        v[x][0].erase(y);
      } else {
        v[x][0].insert(y);
        v[x][1].erase(y);
      }
      if (x & 1) {
        acv[y][1].insert(x);
        acv[y][0].erase(x);
      } else {
        acv[y][0].insert(x);
        acv[y][1].erase(x);
      }
    }
    av[type[x]]--;
    if (v[x][0].size() == 0 && v[x][1].size() == 0) {
      type[x] = 2;
    } else if (v[x][0].size() != 0 && v[x][1].size() != 0) {
      type[x] = 3;
    } else if (v[x][0].size() == 0 && v[x][1].size() != 0) {
      type[x] = 1;
    } else {
      type[x] = 0;
    }
    av[type[x]]++;
    if (ty[y] == 0) {
      if (y & 1) {
        aa[0]--;
      } else {
        aa[1]--;
      }
    } else if (ty[y] == 1) {
      if (y & 1) {
        aa[1]--;
      } else {
        aa[0]--;
      }
    }
    ay[ty[y]]--;
    if (acv[y][0].size() == 0 && acv[y][1].size() == 0) {
      ty[y] = 2;
    } else if (acv[y][0].size() != 0 && acv[y][1].size() != 0) {
      ty[y] = 3;
    } else if (acv[y][0].size() == 0 && acv[y][1].size() != 0) {
      ty[y] = 1;
    } else {
      ty[y] = 0;
    }
    ay[ty[y]]++;
    if (ty[y] == 0) {
      if (y & 1) {
        aa[0]++;
      } else {
        aa[1]++;
      }
    } else if (ty[y] == 1) {
      if (y & 1) {
        aa[1]++;
      } else {
        aa[0]++;
      }
    }
    result = 0;
    if (av[3] != 0) {
      if (ay[3] == 0) {
        cout << mi[ay[2]] << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      result = mi[av[2]];
      if (ay[3] == 0) {
        int now = mi[ay[2]];
        if (aa[0] == 0 && aa[1] == 0) {
          now = (now - 2 + MOD) % MOD;
        } else if (aa[0] != 0 && aa[1] != 0) {
        } else {
          now = (now - 1 + MOD) % MOD;
        }
        result = (result + now) % MOD;
      }
      cout << result << endl;
    }
  }
  return 0;
}
