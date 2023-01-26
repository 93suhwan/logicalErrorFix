#include <bits/stdc++.h>
using namespace std;
int cnt(string s, string r) {
  int sc = 0, rc = 0, t = 0;
  while (sc < (int)s.length() && rc < (int)r.length()) {
    if (s[sc] == r[rc]) {
      t++;
      rc++;
    }
    sc++;
  }
  return (int)s.length() + (int)r.length() - 2 * t;
}
vector<string> store;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (long long i = 1; i < (long long)2e18; i *= 2) {
    store.push_back(to_string(i));
  }
  int test;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    int mn = s.length() + 1;
    for (auto &r : store) {
      mn = min(mn, cnt(s, r));
    }
    cout << mn << "\n";
  }
  return 0;
}
