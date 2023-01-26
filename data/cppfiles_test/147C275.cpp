#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    long long length = s.length();
    long long e, n;
    e = 0, n = 0;
    for (int i = 0; i < length; i++) {
      if (s[i] == 'E')
        e++;
      else
        n++;
    }
    if (e == length || n == length || n >= 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
