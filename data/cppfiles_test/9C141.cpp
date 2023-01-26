#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int arr[26];
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      arr[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (arr[i] > 0) {
        if (arr[i] < 3) {
          ans += arr[i];
        } else {
          ans += 2;
        }
      }
    }
    ans = ans / 2;
    cout << ans << endl;
  }
  return 0;
}
