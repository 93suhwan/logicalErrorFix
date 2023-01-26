#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    long long ab = 0;
    long long n = a.size();
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 'a' && a[i + 1] == 'b') {
        ab++;
      }
      if (a[i + 1] == 'a' && a[i] == 'b') {
        ab--;
      }
    }
    if (ab < 0) {
      if (a[n - 1] == 'a') {
        a[n - 1] = 'b';
      } else {
        a[0] = 'a';
      }
    } else if (ab > 0) {
      if (a[n - 1] == 'b') {
        a[n - 1] = 'a';
      } else {
        a[0] = 'b';
      }
    }
    cout << a << endl;
  }
}
