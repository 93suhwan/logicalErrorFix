#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1, n = 0;
  cin >> t;
  string a, b;
  while (t--) {
    cin >> n;
    cin >> a;
    cin >> b;
    int count = 0, i = 0;
    for (i = 0; i < n - 1; i++) {
      if (b[i] == '1') {
        if (a[i] == '0') {
          count++;
          a[i] = '2';
        } else if (i == 0 && a[i + 1] == '1') {
          count++;
          a[i + 1] = '2';
        } else if (i != 0 && a[i - 1] == '1') {
          count++;
          a[i - 1] = '2';
        } else if (a[i + 1] == '1') {
          count++;
          a[i + 1] = '2';
        }
      }
    }
    if (b[i] == '1') {
      if (a[i] == '0' || a[i - 1] == '1') count++;
    }
    cout << count << endl;
  }
}
