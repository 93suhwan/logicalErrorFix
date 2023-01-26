#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int inf = 1 << 15;
int a[N][N];
int c[N][N];
int ans[N][N];
int q[N];
void update(int &x, int y) {
  if (x == -1 || x > y) x = y;
}
long long sqr(long long x) { return x * x; }
long long get_a(int y) { return -2 * y; }
long long get_b(int r, int y) { return sqr(r - c[r][y]) + sqr(y); }
void solve(int r, int m) {
  int top = 0, tail = 0;
  for (int i = 0; i < m; i++) {
    while (top + 1 < tail &&
           (get_b(r, i) - get_b(r, q[tail - 1])) *
                   (get_a(q[tail - 2]) - get_a(q[tail - 1])) <=
               (get_b(r, q[tail - 1]) - get_b(r, q[tail - 2])) *
                   (get_a(q[tail - 1]) - get_a(i)))
      tail--;
    q[tail++] = i;
  }
  for (int i = 0; i < m; i++) {
    while (top + 1 < tail && get_a(q[top]) * i + get_b(r, q[top]) >=
                                 get_a(q[top + 1]) * i + get_b(r, q[top + 1]))
      top++;
    update(ans[r][i], get_a(q[top]) * i + get_b(r, q[top]) + i * i);
  }
}
int main() {
  char s[N];
  memset(ans, -1, sizeof(ans));
  int n, m;
  scanf("%d%d", &n, &m);
  n++, m++;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) c[i][j] = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j])
        c[i][j] = i;
      else if (i)
        c[i][j] = c[i - 1][j];
    }
    solve(i, m);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) c[i][j] = inf;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (a[i][j])
        c[i][j] = i;
      else if (i + 1 < n)
        c[i][j] = c[i + 1][j];
    }
    solve(i, m);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) sum += ans[i][j];
  cout << sum << endl;
  return 0;
}
