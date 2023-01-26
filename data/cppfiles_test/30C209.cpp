#include <bits/stdc++.h>
using namespace std;
const long long Max = 1e5 + 1;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long n;
string s;
void read() { cin >> n >> s; }
void solve() {
  long long ans = INT_MAX;
  for (char i = 'a'; i <= 'z'; ++i) {
    long long best = 0;
    long long left = 0;
    long long right = s.size() - 1;
    while (left < right) {
      if (s[left] == s[right])
        left++, right--;
      else if (s[left] == i or s[right] == i) {
        best++;
        if (s[left] == i)
          left++;
        else
          right--;
      } else {
        best = INT_MAX;
        break;
      }
    }
    ans = min(ans, best);
  }
  if (ans != INT_MAX)
    cout << ans << '\n';
  else
    cout << "-1\n";
}
void restart() {}
int32_t main() {
  nos();
  long long teste;
  cin >> teste;
  while (teste--) {
    read();
    solve();
    restart();
  }
  return 0;
}
