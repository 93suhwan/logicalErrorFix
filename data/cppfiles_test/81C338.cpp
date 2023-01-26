#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  long long f = 1;
  if (c > '9' || c < '0') {
    if (c == '-') {
      f = -1;
    }
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  x *= f;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
const int maxn = 3e5 + 7;
int sum[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(sum, 0, sizeof sum);
    int n, q;
    cin >> n >> q;
    string x;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
      if (x[i] == '-') {
        if (i % 2 == 0) {
          sum[i + 1] = sum[i] + 1;
        } else {
          sum[i + 1] = sum[i] - 1;
        }
      } else {
        if (i % 2 == 0) {
          sum[i + 1] = sum[i] - 1;
        } else {
          sum[i + 1] = sum[i] + 1;
        }
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int d = abs(sum[r] - sum[l - 1]);
      if (d == 0) {
        cout << 0 << '\n';
        continue;
      }
      if (d & 1) {
        cout << 1 << '\n';
      } else {
        cout << 2 << '\n';
      }
    }
  }
}
