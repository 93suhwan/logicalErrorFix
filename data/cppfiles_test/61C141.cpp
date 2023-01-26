#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    cin.ignore();
    for (int i = 0; i < n; i++) {
      if (a[i] == '?' && i != 0) {
        if (a[i - 1] == 'R')
          a[i] = 'B';
        else
          a[i] = 'R';
      } else if (a[i] == '?' && i == 0) {
        char x;
        int start;
        int j;
        for (j = 0; j < n; j++) {
          if (a[j] != '?') {
            x = a[j];
            start = j - 1;
            break;
          }
        }
        if (j < n) {
          if (x == 'R')
            a[start] = 'B';
          else
            a[start] = 'R';
          for (int k = start - 1; k >= 0; k--) {
            if (a[k + 1] == 'R')
              a[k] = 'B';
            else
              a[k] = 'R';
          }
        } else {
          a[n - 1] = 'B';
          for (int k = n - 2; k >= 0; k--) {
            if (a[k + 1] == 'R')
              a[k] = 'B';
            else
              a[k] = 'R';
          }
        }
      }
    }
    cout << a << endl;
  }
}
