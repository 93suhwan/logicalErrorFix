#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long freq[26];
  memset(freq, 0, sizeof(freq));
  for (char ch : s) freq[ch - 'a']++;
  long long k = 0;
  long long g = 0;
  for (long long i = 0; i < 26; i++) {
    if (freq[i] >= 2) {
      k += 1;
    } else if (freq[i] == 1) {
      g++;
    }
  }
  cout << k + g / 2 << '\n';
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
