#include <bits/stdc++.h>
using namespace std;
long long const tax = 1e9 + 7;
void setIO() {}
void helper(vector<string> &v, string s, int n, int m) {
  if (n == 0 && m == 0) {
    v.push_back(s);
    return;
  }
  if (n > 0) helper(v, s + "(", n - 1, m + 1);
  if (m > 0) helper(v, s + ")", n, m - 1);
}
void generateParenthesis(int n) {
  vector<string> ans;
  helper(ans, "", n, 0);
  for (auto e : ans) {
    cout << e << endl;
    ;
  }
}
signed main() {
  setIO();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    generateParenthesis(n);
  }
  return 0;
}
