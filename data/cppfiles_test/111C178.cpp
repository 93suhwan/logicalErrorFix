#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int open = n;
      int close = n;
      while (open > 0) {
        for (int j = 1; j <= i && open > 0; j++) {
          cout << '(';
          open--;
        }
        cout << ')';
        close--;
      }
      for (int k = 1; k <= close; k++) {
        cout << ')';
      }
      cout << endl;
    }
  }
  return 0;
}
