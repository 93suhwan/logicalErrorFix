#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long t;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    long long n;
    cin >> n;
    bool found = false;
    char sym, prev;
    string s;
    cin >> prev;
    s.push_back(prev);
    for (long long i = 1; i < (n - 2) * 2; i++) {
      cin >> sym;
      if (i % 2 == 0) {
        if (sym != prev) {
          found = true;
          s.push_back(prev);
        }
        s.push_back(sym);
      }
      prev = sym;
    }
    s.push_back(sym);
    if (!found) s.push_back('a');
    cout << s << endl;
  }
}
