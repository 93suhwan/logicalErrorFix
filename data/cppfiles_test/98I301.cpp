#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
    }
    int l = 1, r = n;
    while (l < r) {
      if (a == b) {
        cout << l << " " << r << endl;
        break;
      } else if (a < b) {
        if (s[l - 1] == 'b') {
          b--;
          l++;
        } else if (s[r - 1] == 'b') {
          b--;
          r--;
        } else {
          a -= 2;
          l++;
          r--;
        }
      } else {
        if (s[l - 1] == 'a') {
          a--;
          l++;
        } else if (s[r - 1] == 'a') {
          a--;
          r--;
        } else {
          b -= 2;
          l++;
          r--;
        }
      }
    }
    if (l >= r) cout << "-1 -1" << endl;
  }
  return 0;
}
