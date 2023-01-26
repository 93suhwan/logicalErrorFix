#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long oz = 0, zo = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0') oz++;
      if (a[i] == '0' && b[i] == '1') zo++;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == '1')
        a[i] = '0';
      else if (a[i] == '0')
        a[i] = '1';
    }
    long long oz2 = 0, zo2 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0') oz2++;
      if (a[i] == '0' && b[i] == '1') zo2++;
    }
    if (zo == oz && oz2 + 1 == zo2) {
      cout << min(oz + zo, oz2 + zo2) << "\n";
    } else
      cout << -1 << "\n";
  }
}
