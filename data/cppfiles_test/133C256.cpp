#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    string s;
    cin >> n;
    long long int te = n - 3;
    string se;
    cin >> se;
    s += se;
    while (te--) {
      cin >> se;
      if (s[s.size() - 1] == se[0]) {
        s += se[1];
      } else {
        s += se;
      }
    }
    if (s.size() == n) {
      cout << s << "\n";
    } else {
      long long int m = n - s.size();
      string sw(m, 'a');
      s += sw;
      cout << s << "\n";
    }
  }
  return 0;
}
