#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    for (int i = 1;; i++) {
      if (i % 3 == 0 || i % 10 == 3) continue;
      if (--K == 0) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
