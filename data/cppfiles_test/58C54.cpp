#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long N = 1e5 + 5;
const long long p = 998244353;
class Solution {
 public:
  void Case() {
    long long n;
    cin >> n;
    string str1[2];
    cin >> str1[0] >> str1[1];
    for (long long j = 0; j < n; j++) {
      if (str1[0][j] == '1' && str1[1][j] == '1') {
        cout << "NO \n";
        return;
      }
    }
    cout << "YES \n";
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    Solution obj;
    obj.Case();
  }
  return 0;
}
