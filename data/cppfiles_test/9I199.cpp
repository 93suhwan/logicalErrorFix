#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> mp;
  int n = s.size();
  for (char c : s) {
    if (mp[c] > 2) n--;
    mp[c]++;
  }
  cout << n / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
