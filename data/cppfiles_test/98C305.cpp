#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    string val;
    cin >> val;
    int ans = 0;
    for (int i = 1; i < val.size(); i++) {
      int x = s.find(val[i - 1]) - s.find(val[i]);
      ans += abs(x);
    }
    cout << ans << endl;
  }
  return 0;
}
