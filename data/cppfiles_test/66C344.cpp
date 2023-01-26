#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, count = 1;
    cin >> n;
    while (n > 0) {
      if (count % 3 != 0 && count % 10 != 3) {
        count++;
        n--;
      } else {
        count++;
      }
    }
    int ans = count - 1;
    cout << ans << endl;
  }
}
