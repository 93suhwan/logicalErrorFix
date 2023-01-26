#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    int ca = count(str.begin(), str.end(), 'a');
    int cb = count(str.begin(), str.end(), 'b');
    int cc = count(str.begin(), str.end(), 'cc');
    if (cb = cc + ca) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
