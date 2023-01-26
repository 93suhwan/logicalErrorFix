#include <bits/stdc++.h>
using namespace std;
string get_ans(long long int i, long long int n, long long int distinct,
               string nw, long long int k, string str) {
  if (distinct > k) {
    return "";
  }
  if (nw.substr(0, i) < str.substr(0, i)) {
    return "";
  }
  if (i >= n) return nw;
  for (char ch = '0'; ch <= '9'; ch++) {
    nw[i] = ch;
    bool b = true;
    for (long long int j = 0; j < i; j++) {
      if (nw[j] == ch) {
        b = false;
        break;
      }
    }
    string temp = get_ans(i + 1, n, distinct + b, nw, k, str);
    if (temp.size()) {
      return temp;
    }
  }
  return "";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string str = to_string(n);
    string ans = get_ans(0, str.size(), 0, string(str.size(), '0'), k, str);
    cout << ans << "\n";
  }
}
