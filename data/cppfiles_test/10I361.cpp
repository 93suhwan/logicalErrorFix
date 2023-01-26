#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int T, n, m;
int a[N];
int b[N];
int c[N];
bool st[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> n >> m;
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      b[a[i]]++;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] < m) {
        cnt += b[i];
        st[i] = true;
      } else
        b[i] = m;
    }
    cnt = cnt / m;
    int k = m;
    for (int i = 1; i <= n; i++) {
      if (st[a[i]]) {
        if (cnt) {
          c[i] = k--;
          if (k == 0) {
            cnt--;
            k = m;
          }
        }
      } else {
        if (b[a[i]]) c[i] = b[a[i]]--;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << c[i] << ' ';
    }
    puts("");
  }
  return 0;
}
