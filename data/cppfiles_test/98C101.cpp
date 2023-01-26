#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s, word;
  cin >> s >> word;
  int sum = 0;
  char a = word[0];
  int indexO = s.find(a) + 1;
  for (char &c : word) {
    sum += abs(int(s.find(c) + 1 - indexO));
    indexO = s.find(c) + 1;
  }
  cout << sum << "\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
