#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << (count(s.begin(), s.end(), 'N') == 1 ? "NO\n" : "YES\n");
  }
}
