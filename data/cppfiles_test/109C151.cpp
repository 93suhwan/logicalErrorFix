#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int len;
    cin >> len;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '0')
        continue;
      else {
        res += s[i] - '0';
        res++;
      }
    }
    if (s[len - 1] != '0') res--;
    cout << res << "\n";
  }
}
