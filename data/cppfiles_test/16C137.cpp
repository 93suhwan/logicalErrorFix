#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    string s, tem;
    cin >> s;
    tem = s;
    char c = s[0];
    sort(tem.begin(), tem.end());
    for (long long i = 0; i < n; i++) {
      if (s[i] != tem[i]) ans++;
    }
    cout << ans << "\n";
  }
}
