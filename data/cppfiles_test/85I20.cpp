#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    long long int i = 0, cnt = 0;
    while (i < s.size()) {
      if ((s[i] == '1' && s[i + 1] == '0') ||
          (s[i] == '0' && s[i + 1] == '1')) {
        cnt++;
        i += 2;
      } else
        i++;
    }
    long long int cnt0 = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (s[i] == '0') cnt0++;
    }
    if (cnt == 0) {
      if (cnt0 == s.size())
        cout << 1 << endl;
      else
        cout << 0 << endl;
    } else
      cout << min(cnt, (long long int)2) << endl;
  }
}
