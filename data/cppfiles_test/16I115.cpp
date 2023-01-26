#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num;
  string s, a;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    cin >> s;
    a = s;
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (a[i] != s[i]) {
        cnt++;
      }
    }
    cout << cnt;
  }
  return 0;
}
