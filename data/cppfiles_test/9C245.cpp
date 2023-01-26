#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      cnt[s[i] - 'a']++;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 2) cnt[i] = 2;
      sum += cnt[i];
    }
    cout << sum / 2 << endl;
  }
}
