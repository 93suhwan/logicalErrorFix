#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    for (int i = 0; i < n - 3; i++) {
      string tmp;
      cin >> tmp;
      ans += tmp[1];
    }
    cout << ans << "a" << endl;
  }
  return 0;
}
