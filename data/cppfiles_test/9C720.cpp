#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;
int a[maxn];
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int ans = 0;
    for (int j = 0; j < 26; j++) {
      a[j] = 0;
    }
    for (int j = 0; j < s.size(); j++) {
      if (a[s[j] - 'a'] < 2) {
        ans++;
      }
      a[s[j] - 'a']++;
    }
    cout << ans / 2 << "\n";
  }
}
