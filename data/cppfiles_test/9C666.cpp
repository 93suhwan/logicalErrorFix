#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  unordered_map<char, int> cnt;
  for (char c : s) {
    ++cnt[c];
    if (cnt[c] > 2) {
      --n;
    }
  }
  cout << n / 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
