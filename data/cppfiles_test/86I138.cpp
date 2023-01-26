#include <bits/stdc++.h>
using namespace std;
int n;
char a[1001000], b[1001000];
void init() {
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
}
void work() {
  int ans = 0;
  int count[2];
  count[1] = count[0] = 0;
  for (int i = 0; i < n; ++i) {
    count[a[i] - '0']++;
    count[b[i] - '0']++;
    if (count[0] > 0 && count[1] > 0) {
      ans += 2;
      count[0] = count[1] = 0;
    } else if (count[0] > 2) {
      count[0] -= 2;
      ans++;
    }
  }
  if (count[0] > 0) ans++;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    init();
    work();
  }
  return 0;
}
