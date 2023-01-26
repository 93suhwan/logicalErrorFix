#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.length(); i++) {
    m[s[i]]++;
  }
  int count = 0, temp = 0;
  for (auto i : m) {
    if (i.second >= 2) {
      count++;
    } else if (i.second == 1) {
      temp++;
    }
  }
  count += (temp / 2);
  cout << count << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
