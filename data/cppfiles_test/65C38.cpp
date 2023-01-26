#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long su = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) su = su * 10 + c - '0';
  return su * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
pair<int, int> a[200005];
string st;
int t;
int l, r;
int n;
int x;
int y;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int q;
    cin >> q;
    a[i] = {q, i};
  }
  sort(a + 1, a + n + 1);
  cin >> st;
  for (int i = 1; i < st.length(); i++)
    if (st[i] != st[i - 1]) x++;
  int l = n - x, r = n - x + 1;
  if (st[0] == 'L') t = 1;
  cout << a[l].first << " " << st[0] << endl;
  l--;
  for (int i = 1; i < st.length(); i++) {
    if (st[i] != st[i - 1]) {
      cout << a[r].first << " " << st[i] << endl;
      r++;
    } else {
      if (t)
        cout << a[l].first << " " << 'R' << endl;
      else
        cout << a[l].first << " " << 'L' << endl;
      t ^= 1;
      l--;
    }
  }
}
