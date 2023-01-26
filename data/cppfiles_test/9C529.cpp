#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string S;
    cin >> S;
    vector<int> counts(26, 0);
    for (char c : S) {
      counts[c - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (counts[i] == 0) continue;
      if (counts[i] == 1) ans++;
      if (counts[i] >= 2) ans += 2;
    }
    cout << ans / 2 << endl;
  }
}
