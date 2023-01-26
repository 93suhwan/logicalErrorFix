#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    long long l = s.size();
    long long cn = 0;
    for (long long i = 0; i < l; i++) {
      if (s[i] == 'N') cn++;
    }
    if (cn == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
