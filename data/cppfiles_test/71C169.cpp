#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
string n;
int k;
string solve() {
  cin >> n >> k;
  while (1) {
    set<char> s;
    for (auto c : n) s.insert(c);
    if (s.size() <= k) return n;
    s.clear();
    int pos = 0;
    for (;; pos++) {
      s.insert(n[pos]);
      if (s.size() > k) {
        while (n[pos] == '9') pos--;
        n[pos]++;
        for (int i = pos + 1; i < n.size(); i++) n[i] = '0';
        break;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solve() << '\n';
}
