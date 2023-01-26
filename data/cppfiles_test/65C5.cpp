#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, a[200010], cnt = 1, curl, curr;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  cin >> s;
  for (int i = 1; i <= n - 1; ++i)
    if (s[i] != s[i - 1]) ++cnt;
  int lstl = 0;
  curl = curr = n - cnt;
  --curl;
  long long cur = 0;
  for (int i = 0; i < s.size(); ++i) {
    int p = i;
    while (p < s.size() && s[p] == s[i]) ++p;
    if (s[i] == 'L')
      cur += a[curr];
    else
      cur -= a[curr];
    cout << a[curr++] << ' ' << s[i] << endl;
    if (p - i > 1) {
      for (int j = 0; j < p - i - 1; ++j) {
        if (lstl == 0) {
          if (s[i] == 'R') {
            lstl = 1;
            if (cur + a[curl] < 0) lstl = -1;
          } else {
            lstl = -1;
            if (cur - a[curl] > 0) lstl = 1;
          }
        }
        cout << a[curl--] << ' ' << (lstl == 1 ? 'R' : 'L') << endl;
        lstl = -lstl;
      }
    }
    i = p - 1;
  }
  return 0;
}
