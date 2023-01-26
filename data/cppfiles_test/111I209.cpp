#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      long long open = n;
      long long close = n;
      while (open > 0) {
        for (int i = 0; i < n; i++) {
          cout << '(';
          open--;
        }
        cout << ')';
        close--;
      }
      for (int i = 0; i < close; i++) {
        cout << ')';
      }
      cout << endl;
    }
  }
  return 0;
}
