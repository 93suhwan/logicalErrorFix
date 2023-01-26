#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string a;
    cin >> a;
    int b[4] = {0};
    int i;
    for (i = 0; i < k; i++) {
      if (a[i] == '2')
        b[0]++;
      else if (a[i] == '3')
        b[1]++;
      else if (a[i] == '5')
        b[2]++;
      else if (a[i] == '7')
        b[3]++;
      else
        break;
    }
    if (i == k) {
      cout << 2 << endl;
      if (b[0] >= 2)
        cout << 22 << endl;
      else if (b[1] >= 2)
        cout << 33 << endl;
      else if (b[2] >= 2)
        cout << 55 << endl;
      else if (b[3] >= 2)
        cout << 77 << endl;
      else if (k == 2)
        cout << a << endl;
      else {
        if (a[0] == '2') {
          if (a[1] == '3')
            cout << a[0] << a[2] << endl;
          else
            cout << a[0] << a[1] << endl;
        } else if (a[0] == '3') {
          if (a[1] == '7')
            cout << a[0] << a[2] << endl;
          else
            cout << a[0] << a[1] << endl;
        }
        if (a[0] == '5') {
          if (a[1] == '3')
            cout << a[0] << a[2] << endl;
          else
            cout << a[0] << a[1] << endl;
        }
        if (a[0] == '7') {
          if (a[1] == '3')
            cout << a[0] << a[2] << endl;
          else
            cout << a[0] << a[1] << endl;
        }
      }
    } else {
      cout << 1 << endl << a[i] << endl;
    }
  }
  return 0;
}
