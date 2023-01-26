#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++) {
      v[s[i] - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      if (v[i] >= 2) {
        cnt += 2;
      }
      if (v[i] == 1) {
        cnt++;
      }
    }
    cnt = cnt / 2;
    cout << cnt << endl;
  }
}
