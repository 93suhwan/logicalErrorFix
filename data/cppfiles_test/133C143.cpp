#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string ans;
    cin >> ans;
    long long l = 2;
    bool flag = false;
    for (long long i = 1; i < n - 2; i++) {
      string temp;
      cin >> temp;
      if (ans[l - 1] == temp[0]) {
        ans += temp[1];
        l++;
      } else {
        ans += temp;
        l += 2;
        flag = true;
      }
    }
    if (!flag) {
      ans += 'a';
    }
    cout << ans << endl;
  }
}
