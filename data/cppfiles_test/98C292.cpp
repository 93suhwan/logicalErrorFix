#include <bits/stdc++.h>
using namespace std;
void solve() {
  string k, s;
  cin >> k >> s;
  int t = 0, memo = -1;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < k.size(); j++) {
      if (memo != -1 && s[i] == k[j]) t = t + abs(j - memo);
      if (s[i] == k[j]) memo = j;
    }
  }
  cout << t;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T-- > 0) {
    solve();
    cout << "\n";
  }
}
