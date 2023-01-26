#include <bits/stdc++.h>
using namespace std;
void preProcess(vector<vector<char>> &pow2) {
  long long int v = 1, cv;
  long long int x = 1e17;
  while (v <= x) {
    cv = v;
    vector<char> tmp;
    while (cv != 0) {
      tmp.push_back('0' + (cv % 10));
      cv = cv / 10;
    }
    reverse(tmp.begin(), tmp.end());
    pow2.push_back(tmp);
    v *= 2;
  }
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<vector<char>> pow2;
    preProcess(pow2);
    string sn = to_string(n);
    long long int ans = INT_MAX;
    for (long long int i = 0; i < pow2.size(); i++) {
      long long int p1 = 0, p2 = 0, mc = 0, cost;
      while (p1 < sn.size() and p2 < pow2[i].size()) {
        if (sn[p1] == pow2[i][p2]) {
          p1 += 1;
          p2 += 1;
          mc += 1;
        } else {
          p1 += 1;
        }
      }
      cost = sn.size() - mc + (pow2[i].size() - p2);
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}
