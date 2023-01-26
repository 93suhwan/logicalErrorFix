#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    bool x = true;
    for (long long i = 0; i < n - 1; i++) {
      if ((a[i + 1] == '1') && (b[i] == '1') && (b[i + 1] == '1') &&
          (a[i] == '1')) {
        cout << "NO" << endl;
        x = false;
        break;
      }
    }
    if (x) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
