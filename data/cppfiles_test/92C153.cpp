#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    string a;
    cin >> a;
    if (a[0] != a[a.length() - 1]) {
      a[0] = a[a.length() - 1];
      cout << a << endl;
    } else {
      cout << a << endl;
    }
  }
}
