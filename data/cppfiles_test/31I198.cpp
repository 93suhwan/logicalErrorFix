#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N], b[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      b[i] = a[i + 1];
      b[i + 1] = -a[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += (long long)a[i] * b[i];
    }
    if (sum != 0) exit(0);
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    puts("");
  } else {
    b[1] = a[3];
    b[2] = a[3];
    b[3] = -a[1] - a[2];
    for (int i = 4; i <= n; i += 2) {
      b[i] = a[i + 1];
      b[i + 1] = -a[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += (long long)a[i] * b[i];
    }
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    puts("");
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
