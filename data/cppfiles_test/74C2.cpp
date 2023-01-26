#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050, maxv = 2e6 + 50;
int n, x, y, z, N, cnt, tot, a[maxn], b[maxn];
unordered_map<int, int> mp[30];
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
void dfs(int x, int p) {
  if (x == N + 1) {
    int s = 0;
    for (int i = 1; i <= cnt; i++) s += b[i];
    if (mp[cnt].count(s)) {
      int q = mp[cnt][s];
      int t = p & q;
      p ^= t, q ^= t;
      int r = 0, c[30], d[30];
      for (int i = 1; i <= 26; i++)
        if (p >> (i - 1) & 1) c[++r] = a[i];
      r = 0;
      for (int i = 1; i <= 26; i++)
        if (q >> (i - 1) & 1) d[++r] = a[i];
      printf("YES\n");
      int x = 0;
      printf("0 ");
      for (int i = 1; i <= r; i++) {
        x = c[i] - x;
        printf("%d ", x);
        x = d[i] - x;
        if (i != r) printf("%d ", x);
      }
      for (int i = 1; i <= n; i++) {
        bool flag = 1;
        for (int j = 1; j <= r; j++) {
          if (c[j] == a[i] || d[j] == a[i]) {
            flag = 0;
            break;
          }
        }
        if (flag) printf("%d ", a[i]);
      }
      exit(0);
    }
    mp[cnt][s] = p;
    return;
  }
  if ((cnt + 1) * 2 <= N) {
    b[++cnt] = a[x];
    dfs(x + 1, p | (1 << (x - 1)));
    cnt--;
  }
  dfs(x + 1, p);
}
int main() {
  cin >> n;
  if (n == 2) {
    cin >> x >> y;
    if (x == y) {
      cout << "YES" << endl;
      cout << 0 << " " << x << endl;
    } else
      cout << "NO" << endl;
    return 0;
  } else if (n == 3) {
    cin >> x >> y >> z;
    if (x == y) {
      cout << "YES" << endl;
      cout << 0 << " " << y << " " << z << endl;
      return 0;
    }
    if (x == z) {
      cout << "YES" << endl;
      cout << 0 << " " << x << " " << y << endl;
      return 0;
    }
    if (y == z) {
      cout << "YES" << endl;
      cout << 0 << " " << x << " " << z << endl;
      return 0;
    }
    if (!((x + y + z) & 1)) {
      int t = (x + y + z) >> 1;
      x = t - x;
      y = t - y;
      z = t - z;
      cout << "YES" << endl;
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
  }
  int t = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if ((a[i] & 1) ^ 1) t = i;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (a[i] == a[j]) {
        printf("YES\n");
        printf("0 ");
        for (int k = 1; k <= n; k++)
          if (k != i) printf("%d ", a[k]);
        return 0;
      }
    }
  if (t) {
    int e1 = 0, e2 = 0, o1 = 0, o2 = 0;
    for (int i = 1; i <= n; i++) {
      if (i == t) continue;
      if (a[i] & 1) {
        if (!o1)
          o1 = i;
        else if (!o2)
          o2 = i;
      } else {
        if (!e1)
          e1 = i;
        else if (!e2)
          e2 = i;
      }
    }
    if (e1 && e2) {
      int tmp = (a[e1] + a[e2] - a[t]) / 2;
      printf("YES\n");
      printf("%d ", tmp);
      for (int i = 1; i <= n; i++)
        if (i != t) printf("%d ", a[i] - tmp);
    } else {
      int tmp = (a[o1] + a[o2] - a[t]) / 2;
      printf("YES\n");
      printf("%d ", tmp);
      for (int i = 1; i <= n; i++)
        if (i != t) printf("%d ", a[i] - tmp);
    }
    return 0;
  }
  N = min(n, 26);
  dfs(1, 0);
  printf("NO\n");
  return 0;
}
