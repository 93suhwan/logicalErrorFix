#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n - 2; i++) {
      string a;
      cin >> a;
      v.push_back(a);
    }
    string ans = "";
    ans += v[0][0];
    bool flag = false;
    for (int i = 1; i < v.size(); i++) {
      if (v[i][0] == v[i - 1][1]) {
        ans += v[i][0];
      } else {
        flag = true;
        ans += v[i - 1][1];
        ans += v[i][0];
      }
    }
    ans += v[v.size() - 1][1];
    if (flag == false) {
      ans += v[v.size() - 1][1];
    }
    cout << ans << endl;
  }
  return 0;
}
