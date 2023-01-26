#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    long long int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        c0++;
      }
    }
    long long int x = 1, y = c0 + 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cout << x << " ";
        x++;
      } else {
        cout << y << " ";
        y++;
      }
    }
    cout << endl;
  }
}
