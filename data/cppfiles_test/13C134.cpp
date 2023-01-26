#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] - '0' == 17) {
        cnt1++;
      } else if (s[i] - '0' == 18) {
        cnt2++;
      } else {
        cnt3++;
      }
    }
    if (cnt2 - cnt1 - cnt3 == 0) {
      cout << "Yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
  return 0;
}
