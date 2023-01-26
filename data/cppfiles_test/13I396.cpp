#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char a[maxn][maxn];
int ck(int n, int m, int k) {
  if (n % 2 == 0) {
    int sum = (n / 2) * (m / 2);
    if (k > sum * 2)
      return 0;
    else {
      if (k % 2 == 0)
        return 1;
      else
        return 0;
    }
  } else {
    int sum = (n / 2) * (m / 2) + m / 2;
    if (k > sum * 2 || k < m / 2)
      return 0;
    else {
      if ((k - m / 2) % 2 != 0)
        return 0;
      else
        return 1;
    }
  }
}
void init() {
  for (int i = 1; i <= 105; i++)
    for (int j = 1; j <= 105; j++) a[i][j] = '0';
}
void pt(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
void bt(int n, int m, int k) {
  init();
  if (n % 2 == 1) {
    for (int i = 1; i <= m / 2; i++) {
      a[n][i * 2 - 1] = a[n][i * 2] = ((i & 1) ? 'x' : 'y');
    }
    n--;
    k -= m / 2;
  }
  if (m % 2 == 1) {
    for (int i = 1; i <= n / 2; i++) {
      a[i * 2 - 1][m] = a[i * 2][m] = ((i & 1) ? 'x' : 'y');
    }
    m--;
  }
  for (int i = 1; i <= n; i += 2) {
    if (k == 0) break;
    for (int j = 1; j <= m; j += 2) {
      if (k == 0) break;
      a[i][j] = a[i][j + 1] = 'a' + (j / 2) % 26;
      a[i + 1][j] = a[i + 1][j + 1] = 'a' + (j / 2 + 1) % 26;
      k -= 2;
    }
  }
  int top = 3;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= m / 2; j++) {
      if (a[i * 2][j * 2] != '0') continue;
      a[i * 2 - 1][j * 2] = a[i * 2][j * 2] = (((i + j) & 1) ? 'a' : 'b');
      a[i * 2 - 1][j * 2 - 1] = a[i * 2][j * 2 - 1] =
          (((i + j) & 1) ? 'c' : 'd');
      top++;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (ck(n, m, k)) {
      cout << "YES" << endl;
      bt(n, m, k);
      pt(n, m);
    } else
      cout << "NO" << endl;
  }
}
