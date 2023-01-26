#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  int top = n * (n - 1) / 2;
  int bt = n - 1;
  k -= 2;
  if (m >= bt && m <= top && k >= 0) {
    if (n == 1) {
      puts("YES");
    } else {
      if (m == top && k >= 1) {
        puts("YES");
      } else {
        if (k >= 2) {
          puts("YES");
        } else {
          puts("NO");
        }
      }
    }
  } else {
    puts("NO");
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
