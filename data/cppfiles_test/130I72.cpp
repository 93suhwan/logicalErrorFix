#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, M = 1e9 + 7;
int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res % M;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
int n, x, y;
bool st[N];
int ask(int a, int b, int c) {
  printf("? %d %d %d\n", a, b, c);
  fflush(stdout);
  int t;
  scanf("%d", &t);
  return t;
}
void cale(int a, int b, int c, int d, int e, int f) {
  int t1 = ask(a, b, d);
  int t2 = ask(a, b, e);
  int t3 = ask(a, b, f);
  if (!t1 && !t2 && !t3) {
    x = a;
    int t4 = ask(d, e, a);
    if (t4 == 0)
      y = f;
    else
      y = d;
  } else {
    if (t1)
      y = d;
    else if (t2)
      y = e;
    else
      y = f;
    int t4 = ask(a, b, y);
    if (t4 == 0)
      x = a;
    else
      x = c;
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) st[i] = 0;
  vector<int> p;
  int lt = ask(1, 2, 3);
  p.push_back(lt);
  int t;
  for (int i = 4; i <= n; i += 3) {
    t = ask(i, i + 1, i + 2);
    p.push_back(t);
    if (lt != t) {
      if (lt == 0)
        cale(i - 3, i - 2, i - 1, i, i + 1, i + 2);
      else
        cale(i, i + 1, i + 2, i - 3, i - 2, i - 1);
      break;
    }
    lt = t;
  }
  st[x] = 1;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] == 0) {
      int a = 3 * i + 1, b = 3 * i + 2, c = 3 * i + 3;
      int t1 = ask(a, b, y);
      int t2 = ask(b, c, y);
      if (!t1 && !t2)
        st[a] = st[b] = st[c] = 1;
      else if (!t1 && t2)
        st[a] = st[b] = 1;
      else if (t1 && !t2)
        st[b] = st[c] = 1;
      else
        st[a] = st[c] = 1;
    } else {
      int a = 3 * i + 1, b = 3 * i + 2, c = 3 * i + 3;
      int t1 = ask(a, b, x);
      int t2 = ask(b, c, x);
      if (!t1 && !t2)
        st[b] = 1;
      else if (!t1 && t2)
        st[a] = 1;
      else if (t1 && !t2)
        st[c] = 1;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (st[i]) cnt++;
  printf("! %d ", cnt);
  for (int i = 1; i <= n; i++)
    if (st[i]) printf("%d ", i);
  puts("");
  fflush(stdout);
}
signed main() {
  int _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
