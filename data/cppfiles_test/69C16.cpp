#include <bits/stdc++.h>
using namespace std;
int t;
string n;
const long long P2LIM = (long long)1e18;
int check(string sour, string tar) {
  int token = 0;
  int ss = 0;
  int tt = 0;
  while (ss < sour.size() && tt < tar.size()) {
    if (sour[ss] == tar[tt]) {
      token++;
      ss++;
      tt++;
    } else {
      ss++;
    }
  }
  return sour.size() + tar.size() - 2 * token;
}
int main() {
  cin >> t;
  vector<string> nums;
  for (long long i = 1; i < P2LIM; i *= 2) {
    nums.push_back(to_string(i));
  }
  while (t--) {
    cin >> n;
    int res = n.size() + 1;
    for (string d : nums) {
      res = min(res, check(n, d));
    }
    cout << res << endl;
  }
  return 0;
}
