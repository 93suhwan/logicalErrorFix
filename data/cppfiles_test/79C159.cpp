#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
const long long nax = 1000001;
set<int> pr = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (auto& x : s) {
      if (x == '1' || x == '4' || x == '6' || x == '8' || x == '9') {
        cout << "1\n" << x << '\n';
        goto NEXT;
      }
    }
    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < k; ++j) {
        int d = (s[i] - '0') * 10 + (s[j] - '0');
        if (!pr.count(d)) {
          cout << "2\n" << d << '\n';
          goto NEXT;
        }
      }
    }
    cout << k << '\n' << s << '\n';
  NEXT:;
  }
}
