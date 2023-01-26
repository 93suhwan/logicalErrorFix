#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] != s[n - 1])
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
