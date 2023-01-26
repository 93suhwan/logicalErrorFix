#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int T, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1) {
      puts("a");
      continue;
    }
    if (n == 2) {
      puts("ab");
      continue;
    }
    if (n == 3) {
      puts("abc");
      continue;
    }
    int k = n / 2;
    if (n & 1) {
      for (int i = 1; i <= k; ++i) putchar('a');
      putchar('b');
      putchar('c');
      for (int i = 1; i < k; ++i) putchar('a');
    } else {
      for (int i = 1; i <= k; ++i) putchar('a');
      putchar('b');
      putchar('c');
      for (int i = 1; i < k; ++i) putchar('a');
    }
    putchar('\n');
  }
  return 0;
}
