#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N], b[N], c[N];
struct node {
  int a, b, c, d;
} st[N];
int t, n;
bool f[N];
int cmp(const node &a, const node &b) { return a.c < b.c; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> st[i].a >> st[i].b;
      st[i].c = st[i].b - st[i].a;
    }
    sort(st, st + n, cmp);
    for (int i = 0; i < n; i++) {
      for (int j = st[i].a; j <= st[i].b; j++)
        if (!f[j]) {
          st[i].d = j;
          f[j] = true;
        }
    }
    for (int i = 0; i < n; i++)
      cout << st[i].a << ' ' << st[i].b << ' ' << st[i].d << endl;
    memset(f, 0, sizeof f);
  }
  return 0;
}
