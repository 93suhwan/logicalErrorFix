#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int height = 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      if (cnt == 0 && i != 1) {
        height += 5;
      } else {
        height += 1;
        cnt = 0;
      }
    } else if (a[i] == 0) {
      cnt++;
      if (cnt == 2) {
        puts("-1");
        return;
      }
    }
  }
  printf("%d\n", height);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
