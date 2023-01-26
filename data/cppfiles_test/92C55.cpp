#include <bits/stdc++.h>
using namespace std;
void solve() {
  string second;
  cin >> second;
  int ab = 0, ba = 0;
  for (int i = 1; i < second.size(); i++) {
    if (second[i] == 'a' && second[i - 1] == 'b') ba++;
    if (second[i] == 'b' && second[i - 1] == 'a') ab++;
  }
  if (ab == ba) {
    cout << second;
    return;
  }
  if (ab > ba) {
    second[0] = 'b';
  } else
    second[0] = 'a';
  cout << second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t5;
  cin >> t5;
  while (t5--) {
    solve();
    cout << '\n';
  }
  return 0;
}
