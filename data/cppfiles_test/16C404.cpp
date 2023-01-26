#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    t = s;
    sort(t.begin(), t.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (t[i] != s[i]);
    }
    cout << cnt << '\n';
  }
  return 0;
}
