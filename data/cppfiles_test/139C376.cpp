#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string a;
    cin >> a;
    string x, y;
    for (int j = 0; j < a.length() / 2; j++) x.push_back(a[j]);
    for (int j = a.length() / 2; j < a.length(); j++) y.push_back(a[j]);
    if (x == y)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
