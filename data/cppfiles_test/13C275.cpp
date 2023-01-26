#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int m = count(s.begin(), s.end(), 'B');
    if (2 * m == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
