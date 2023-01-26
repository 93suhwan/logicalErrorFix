#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int r1[n];
    int r2[n];
    int occupied[n];
    for (int i = 0; i < n; i++) {
      char a;
      cin >> a;
      r1[i] = a - '0';
      occupied[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      char a;
      cin >> a;
      r2[i] = a - '0';
    }
    for (int i = 0; i < n; i++) {
      if (r2[i] == 1) {
        if (r1[i] == 0 && occupied[i] == 0) {
          occupied[i] = 1;
        } else if (i - 1 >= 0 && r1[i - 1] == 1 && occupied[i - 1] == 0) {
          occupied[i - 1] = 1;
        } else if (i + 1 >= 0 && r1[i + 1] == 1 && occupied[i + 1] == 0) {
          occupied[i + 1] = 1;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (occupied[i] != 0) {
        ans++;
      }
    }
    cout << ans << "\n";
  }
}
