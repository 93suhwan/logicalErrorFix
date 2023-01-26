#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, cnt = 0, ans = 0;
  cin >> a;
  vector<int> v;
  for (int i = 2; i <= a; i++) {
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        if (j % 2 != 0 && j % 3 != 0 && j % 5 != 0 && j % 7 != 0 &&
                j % 11 != 0 && j % 13 != 0 && j % 17 != 0 && j % 19 != 0 &&
                j % 23 != 0 && j % 29 != 0 && j % 31 != 0 && j % 37 != 0 &&
                j % 41 != 0 && j % 43 != 0 ||
            j == 2 || j == 3 || j == 5 || j == 7 || j == 11 || j == 13 ||
            j == 17 || j == 19 || j == 23 || j == 29 || j == 31 || j == 37 ||
            j == 41 || j == 43)
          cnt++;
      }
    }
    if (cnt == 2) ans++;
    cnt = 0;
  }
  cout << ans << endl;
}
