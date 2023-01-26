#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCases;
  cin >> testCases;
  while (testCases--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = s[n - 1] - '0';
    for (int i = 0; i < n - 1; i++) {
      if (s[i] - '0' > 0) {
        ans += (s[i] - '0') + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
