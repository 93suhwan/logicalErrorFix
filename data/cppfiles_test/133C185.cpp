#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    bool test = 0;
    string s;
    char prev;
    vector<char> v;
    for (long long i = 0; i < n - 2; i++) {
      cin >> s;
      if (!test) {
        v.push_back(s[0]);
        v.push_back(s[1]);
        prev = s[1];
        test = 1;
      } else {
        if (s[0] != prev) {
          v.push_back(s[0]);
          v.push_back(s[1]);
        } else
          v.push_back(s[1]);
        prev = s[1];
      }
    }
    int nb = 0;
    for (auto it : v) {
      cout << it;
      nb++;
    }
    if (nb != n) cout << "b";
    cout << '\n';
  }
}
