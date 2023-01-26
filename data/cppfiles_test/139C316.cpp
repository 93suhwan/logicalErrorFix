#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long n;
  long long t;
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    string s1, s2;
    if (n % 2)
      cout << "NO" << endl;
    else {
      s1 = s.substr(0, n / 2);
      s2 = s.substr(n / 2, n / 2);
      if (s1 == s2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
