#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    ans = s;
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] != s[i]) cnt++;
    }
    cout << cnt << endl;
  }
}
