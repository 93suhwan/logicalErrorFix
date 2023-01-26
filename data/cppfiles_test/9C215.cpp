#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      ++a[s[i] - 'a'];
    }
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) cnt += min(a[i], 2);
    cout << cnt / 2 << '\n';
  }
  return 0;
}
