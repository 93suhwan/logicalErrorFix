#include <bits/stdc++.h>
using namespace std;
string solve() {
  string n;
  int k;
  cin >> n >> k;
  while (true) {
    set<char> s;
    for (int c = 0; c < n.size(); c++) s.insert(n[c]);
    if (s.size() <= k) return n;
    s.clear();
    int ptr = 0;
    for (;; ptr++) {
      s.insert(n[ptr]);
      if (s.size() > k) {
        if (n[ptr] == '9') ptr--;
        n[ptr]++;
        for (int i = ptr + 1; i < n.size(); i++) n[i] = '0';
        break;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solve() << '\n';
  return 0;
}
