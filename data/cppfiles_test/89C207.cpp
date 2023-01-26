#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x = 0;
  cin >> n;
  long long arr[n];
  bool ok = false;
  ;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    long long divi = i + 2;
    if (arr[i] % divi != 0)
      x++;
    else {
      ok = false;
      for (int j = 1; j <= x; j++) {
        if (arr[i] % (divi - j) != 0) {
          x++;
          ok = true;
          break;
        }
      }
      if (ok == false) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
