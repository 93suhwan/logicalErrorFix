#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int k = 1;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i == n - 1) {
        if (a[i] == '1' && b[i] == '1') {
          sum = sum;
        } else if (a[i] == '0' && b[i] == '1' || a[i] == '1' && b[i] == '0') {
          sum = sum + 2;
        } else {
          sum = sum + 1;
        }
        continue;
      }
      if (a[i] == '1' && b[i] == '1') {
        if (a[i + 1] == '1' && b[i + 1] == '1') {
          sum = sum;
        } else {
          sum += 2;
          i++;
        }
      } else if (a[i] == '1' && b[i] == '0' || a[i] == '0' && b[i] == '1') {
        sum = sum + 2;
      } else if (a[i] == '0' && b[i] == '0') {
        if (a[i + 1] == '0' && b[i + 1] == '1' ||
            a[i + 1] == '1' && b[i + 1] == '0') {
          sum = sum + 3;
          i++;
        } else if (a[i + 1] == '1' && b[i + 1] == '1') {
          sum = sum + 2;
          i++;
        } else {
          sum += 1;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
