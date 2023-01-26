#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void item() {
  int n, cnt = 0, i = 1;
  cin >> n;
  for (; i < 1e8; i++) {
    if (i % 3 != 0 && i % 10 != 3) cnt++;
    if (cnt == n) break;
  }
  cout << i << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    item();
  }
  return 0;
}
