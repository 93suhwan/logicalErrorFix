#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  for (int ii = 0; ii < tt; ii++) {
    string a;
    cin >> a;
    a[a.length() - 1] = a[0];
    cout << a << endl;
  }
  return 0;
}
