#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] != s[s.size() - 1]) {
      s[0] = s[s.size() - 1];
    }
    cout << s << endl;
  }
  return 0;
}
