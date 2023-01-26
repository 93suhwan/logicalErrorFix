#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n - 2; i++) {
      string a;
      cin >> a;
      v.push_back(a);
    }
    string ans = v[0];
    bool f = true;
    int i;
    for (i = 1; i < n - 2; i++) {
      if (v[i][0] == v[(i - 1)][1]) {
        ans = ans + v[i][1];
      } else {
        f = false;
        if (v[(i - 1)][1] == 'a') {
          ans = ans + "b" + v[i][1];
        } else {
          ans = ans + "a" + v[i][1];
        }
      }
    }
    long long int n1 = ans.size();
    if (f) {
      if (ans[n1 - 1] == 'a') {
        ans = ans + "b";
      } else {
        ans = ans + "a";
      }
    }
    cout << ans << endl;
  }
  return 0;
}
