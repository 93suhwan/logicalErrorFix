#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  char m[50], a[50];
  scanf("%s", &a);
  for (int i = 0; i < n; i++) {
    m[i] = a[i];
  }
  sort(&m[0], &m[n]);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (m[i] != a[i]) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
