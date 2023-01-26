#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    if ((x + y) & 1) {
      int l = (y - x) / 2, r = (y + x) - (y - x) / 2;
      printf("%d\n", r - l + 1);
      for (int i = l; i <= r; i++) printf("%d ", i);
      puts("");
    } else {
      int l = (y - x) / 2, r = (y + x) - (y - x) / 2;
      printf("%d\n", ((r - l + 2) / 2));
      for (int i = l; i <= r; i += 2) printf("%d ", i);
      puts("");
    }
  }
}
