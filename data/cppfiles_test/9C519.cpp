#include <bits/stdc++.h>
using namespace std;
void solve() {
  string st;
  map<char, int> m;
  cin >> st;
  for (auto i : st) {
    m[i]++;
  }
  int c = 0, s = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    if (m[i] > 0) {
      if (m[i] == 1) {
        c++;
      } else {
        s++;
      }
    }
  }
  c /= 2;
  cout << s + c << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long queries = 1;
  cin >> queries;
  while (queries--) {
    solve();
  }
  return 0;
}
