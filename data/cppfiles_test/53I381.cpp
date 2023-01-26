#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, k, t, r, p = 0;
  cin >> t;
  for (long long r = 0; r < t; r++) {
    p = 0;
    char ch;
    string s;
    cin >> n >> ch;
    cin >> s;
    vector<long long> v;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] != ch) v.push_back(i + 1);
    }
    if (s[s.size() - 1] == ch) p = 1;
    if (v.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    if (p == 1) {
      cout << 1 << endl;
      cout << s.size() << endl;
      continue;
    } else {
      if (s.size() == 1) {
        cout << 1 << endl;
        cout << s.size() - 1 << endl;
        continue;
      } else {
        cout << 2 << endl;
        cout << s.size() - 1 << " " << s.size() << endl;
        continue;
      }
    }
  }
  return 0;
}
