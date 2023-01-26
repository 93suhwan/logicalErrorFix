#include <bits/stdc++.h>
namespace hyy {
const int MAXSIZE = 1 << 20;
inline char gc() {
  return getchar();
  static char buf[MAXSIZE];
  static char *p1 = buf + MAXSIZE;
  static char *p2 = buf + MAXSIZE;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
  }
  if (p1 == p2) {
    return -1;
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <class T>
inline void read(T &x) {
  register double tmp = 1;
  register bool sign = 0;
  x = 0;
  register char ch = gc();
  for (; !(ch >= '0' && ch <= '9'); ch = gc()) {
    if (ch == '-') {
      sign = 1;
    }
  }
  for (; (ch >= '0' && ch <= '9'); ch = gc()) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
  }
  if (ch == '.') {
    for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc()) {
      tmp /= 10.0;
      x += tmp * (ch - 48);
    }
  }
  if (sign) {
    x = -x;
  }
}
inline void read(char *s) {
  register char ch = gc();
  for (; blank(ch); ch = gc())
    ;
  for (; !blank(ch); ch = gc()) {
    *s++ = ch;
  }
  *s = 0;
}
inline void read(char &c) {
  for (c = gc(); blank(c); c = gc())
    ;
}
inline void push(const char &c) {
  char pbuf[MAXSIZE];
  char *pp = pbuf;
  if (pp - pbuf == MAXSIZE) {
    fwrite(pbuf, 1, MAXSIZE, stdout);
    pp = pbuf;
  }
  *pp++ = c;
}
template <class T>
inline void write(T x) {
  static T sta[35];
  T top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) {
    putchar(sta[--top] + '0');
  }
  return;
  while (top) {
    push(sta[--top] + '0');
  }
}
template <class T>
inline void write(T x, char lastChar) {
  write(x);
  putchar(lastChar);
}
}  // namespace hyy
using namespace hyy;
using namespace std;
using namespace std;
struct MapBool {
  vector<long long> A[10000007];
  inline bool Find(long long x) {
    long long p = x % 10000007;
    for (register int i = 0; i < A[p].size(); ++i) {
      if (A[p][i] == x) {
        return true;
      }
    }
    return false;
  }
  inline void Insert(long long x) {
    long long p = x % 10000007;
    A[p].push_back(x);
  }
};
struct MapInt {
  struct NODE {
    long long key;
    int num;
  };
  vector<NODE> A[10000007];
  inline int Find(long long x) {
    long long p = x % 10000007;
    for (register int i = 0; i < A[p].size(); ++i) {
      if (A[p][i].key == x) {
        return A[p][i].num;
      }
    }
    return -1;
  }
  inline void Insert(long long x, int w) {
    long long p = x % 10000007;
    A[p].push_back(NODE{x, w});
  }
};
MapInt f;
int n, m;
int a[1005][1005];
bool vis[1005][1005];
int cnt;
void Dfs(int x, int y) {
  if (vis[x][y]) {
    return;
  }
  if (x > n || y > m || x == 0 || y == 0) {
    return;
  }
  vis[x][y] = true;
  cnt++;
  if ((a[x][y] >> 3 & 1) == 0) {
    Dfs(x - 1, y);
  }
  if ((a[x][y] >> 2 & 1) == 0) {
    Dfs(x, y + 1);
  }
  if ((a[x][y] >> 1 & 1) == 0) {
    Dfs(x + 1, y);
  }
  if ((a[x][y] >> 0 & 1) == 0) {
    Dfs(x, y - 1);
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      read(a[i][j]);
    }
  }
  vector<int> Q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j] == false) {
        cnt = 0;
        Dfs(i, j);
        Q.push_back(-cnt);
      }
    }
  }
  sort(Q.begin(), Q.end());
  for (int i = 0; i < Q.size(); i++) {
    cout << -Q[i] << " ";
  }
  return 0;
}
