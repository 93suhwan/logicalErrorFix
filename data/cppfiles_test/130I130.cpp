#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 30010;
int i, j, k, n, m, T, s[maxn], is[maxn], tmp[maxn];
int c0 = 0, c1 = 0;
void work(int x) {
  if (s[x])
    c1 = tmp[x], c0 = tmp[x + 3];
  else
    c1 = tmp[x + 3], c0 = tmp[x];
}
int main() {
  cin >> T;
  while (T--) {
    memset(is, -1, sizeof(is));
    memset(s, -1, sizeof(s));
    cin >> n;
    c0 = c1 = 0;
    for (i = 1; i <= n; i++) tmp[i] = (i - 1) % n + 1;
    for (i = 1; i <= n; i += 3) {
      cout << "? " << tmp[i] << ' ' << tmp[i + 1] << ' ' << tmp[i + 2] << endl;
      cin >> s[i];
    }
    for (i = 1; i <= n - 3; i += 3)
      if (s[i] != s[i + 3]) {
        cout << "? " << tmp[i + 1] << ' ' << tmp[i + 2] << ' ' << tmp[i + 3]
             << endl;
        cin >> s[i + 1];
        cout << "? " << tmp[i + 4] << ' ' << tmp[i + 2] << ' ' << tmp[i + 3]
             << endl;
        cin >> s[i + 2];
        if (s[i] != s[i + 1])
          work(i);
        else if (s[i + 1] != s[i + 2])
          work(i + 1);
        else
          work(i + 2);
        break;
      }
    if (!c0) {
      cout << "? " << 2 << ' ' << 3 << ' ' << 4 << endl;
      cin >> s[2];
      cout << "? " << 5 << ' ' << 3 << ' ' << 4 << endl;
      cin >> s[3];
      if (s[1] != s[2])
        work(1);
      else if (s[2] != s[3])
        work(2);
      else if (s[3] != s[4])
        work(3);
      else {
        int w = 0;
        cout << "? " << 1 << ' ' << 2 << ' ' << 4 << endl;
        cin >> w;
        if (w != s[1]) {
          if (w)
            c1 = 4, c0 = 3;
          else
            c0 = 4, c1 = 3;
        } else {
          cout << "? " << 1 << ' ' << 2 << ' ' << 5 << endl;
          if (w != s[1]) {
            if (w)
              c1 = 2, c0 = 4;
            else
              c0 = 2, c1 = 4;
          } else if (s[1])
            c0 = 3, c1 = 4;
          else
            c1 = 3, c0 = 4;
        }
      }
    }
    is[c0] = 0;
    is[c1] = 1;
    cout << "!!! c0=" << c0 << " c1=" << c1 << endl;
    for (i = 1; i <= n; i += 3) {
      if (is[i] != -1 || is[i + 1] != -1 || is[i + 2] != -1) {
        if (is[i] == -1) {
          cout << "? " << i << ' ' << c0 << ' ' << c1 << endl;
          cin >> is[i];
        }
        if (is[i + 1] == -1) {
          cout << "? " << i + 1 << ' ' << c0 << ' ' << c1 << endl;
          cin >> is[i + 1];
        }
        if (is[i + 2] == -1) {
          cout << "? " << i + 2 << ' ' << c0 << ' ' << c1 << endl;
          cin >> is[i + 2];
        }
      } else {
        if (s[i]) {
          int k1, k2;
          cout << "? " << c0 << ' ' << i << ' ' << i + 1 << endl;
          cin >> k1;
          cout << "? " << c0 << ' ' << i << ' ' << i + 2 << endl;
          cin >> k2;
          if (k1 && k2)
            is[i] = is[i + 1] = is[i + 2] = 1;
          else if (!k1 && !k2)
            is[i] = 0, is[i + 1] = is[i + 2] = 1;
          else if (!k1)
            is[i + 1] = 0, is[i] = is[i + 2] = 1;
          else
            is[i + 2] = 0, is[i] = is[i + 1] = 1;
        } else {
          int k1, k2;
          cout << "? " << c1 << ' ' << i << ' ' << i + 1 << endl;
          cin >> k1;
          cout << "? " << c1 << ' ' << i << ' ' << i + 2 << endl;
          cin >> k2;
          if (!k1 && !k2)
            is[i] = is[i + 1] = is[i + 2] = 0;
          else if (k1 && k2)
            is[i] = 1, is[i + 1] = is[i + 2] = 0;
          else if (k1)
            is[i + 1] = 1, is[i] = is[i + 2] = 0;
          else
            is[i + 2] = 1, is[i] = is[i + 1] = 0;
        }
      }
    }
    int ans = 0;
    for (i = 1; i <= n; i++) ans += (is[i] == 0);
    cout << "! " << ans;
    for (i = 1; i <= n; i++)
      if (!is[i]) cout << ' ' << i;
    cout << endl;
  }
  return 0;
}
