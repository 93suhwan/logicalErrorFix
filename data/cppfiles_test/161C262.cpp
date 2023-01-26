#include <bits/stdc++.h>
using namespace std;
int cnt[1010], n;
void printd(int l, int r, int step);
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    int a, b;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      for (int j = a; j <= b; j++) {
        cnt[j]++;
      }
    }
    printd(1, n, 1);
  }
  return 0;
}
void printd(int l, int r, int step) {
  if (l == r) {
    cout << l << " " << r << " " << l << endl;
    return;
  }
  int ans;
  for (int i = l; i <= r; i++) {
    if (cnt[i] == step) {
      ans = i;
      break;
    }
  }
  cout << l << " " << r << " " << ans << endl;
  if (l == ans || r == ans) {
    if (l == ans && r == ans)
      printd(ans, ans, step + 1);
    else if (l == ans && r != ans)
      printd(ans + 1, r, step + 1);
    else if (l != ans && r == ans)
      printd(l, ans - 1, step + 1);
  } else {
    printd(l, ans - 1, step + 1);
    printd(ans + 1, r, step + 1);
  }
  return;
}
