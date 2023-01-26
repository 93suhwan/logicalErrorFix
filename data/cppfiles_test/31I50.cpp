#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
  } else {
    printf("%d %d %d ", a[3], a[3], -a[1] - a[2]);
    for (int i = 4; i <= n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
  }
  puts("");
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
