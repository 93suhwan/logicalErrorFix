#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    vector<int> a(3);
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    sort(a.begin(), a.end());
    if (a[0] == a[1] && a[1] == a[2]) {
      if (a[0] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (a[0] == a[1]) {
      if (a[2] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (a[1] == a[2]) {
      if (a[0] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (a[2] == a[0] + a[1])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
