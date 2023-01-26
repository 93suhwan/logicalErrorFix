#include <bits/stdc++.h>
using namespace std;
int main() {
  ofstream out("out.txt");
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int hash[26]{0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      hash[s[i] - 'a']++;
    }
    int cnt = 0, uncolored = 0;
    for (int i = 0; i < 26; ++i) {
      if (hash[i] == 1) {
        uncolored++;
        if (uncolored == 2) {
          cnt++;
          uncolored = 0;
        }
      } else if (hash[i] > 1) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
