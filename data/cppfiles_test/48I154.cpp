#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T;
int n, a[N], b[N];
int main(int argc, char *argv[]) {
  cin >> T;
  while (T--) {
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i]) res++;
    }
    if (res == n) {
      puts("YES");
      continue;
    }
    if (n - res <= 2) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
