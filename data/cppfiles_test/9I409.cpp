#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int c1 = 0;
  int arr[26] = {0};
  int n = s.length();
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      if (arr[s[i] - 'a'] == 0) {
        c1++;
      }
      arr[s[i] - 'a']++;
    }
  } else if (n % 2 == 1) {
    for (int i = 0; i < n - 1; i += 2) {
      if (arr[s[i] - 'a'] == 0) {
        c1++;
      }
      arr[s[i] - 'a']++;
    }
  }
  cout << c1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
