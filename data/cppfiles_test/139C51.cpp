#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int l = s.size();
    s.substr(0, l / 2) == s.substr(l / 2) ? cout << "YES" : cout << "NO";
    cout << endl;
  }
}
