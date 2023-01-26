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
      for (int i = n - 1; i >= 0 && a[i] == 'a'; --i) {
        a[i] = 'b';
      }
    }
    if (ab > 0) {
      for (int i = 0; i < n && a[i] == 'a'; ++i) {
        a[i] = 'b';
      }
    }
    cout << a << endl;
  }
}
