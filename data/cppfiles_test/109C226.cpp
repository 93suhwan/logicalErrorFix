#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    ;
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      ans += s[i] - '0';
    }
    for (int i = s.length() - 2; i >= 0; i--) {
      if (s[i] > '0' && s[i] <= '9') ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
