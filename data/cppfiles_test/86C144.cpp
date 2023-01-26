#include <bits/stdc++.h>
using namespace std;
long long getGcd(long long a, long long b) {
  if (a == 0) return b;
  return getGcd(b % a, a);
}
long long getLcm(long long a, long long b) { return (a / getGcd(a, b)) * b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector<int> mex;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i]) {
        if (s1[i] == '0')
          mex.push_back(1);
        else
          mex.push_back(0);
      } else
        mex.push_back(2);
    }
    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (mex[i] == 2) {
        ans += 2;
        last = 2;
      } else if (mex[i] == 1) {
        if (last == 0) {
          ans += 2;
          last = 2;
        } else {
          ans += 1;
          last = 1;
        }
      } else {
        if (last == 1) {
          ans += 1;
          last = 2;
        } else {
          last = 0;
        }
      }
    }
    cout << ans << "\n";
  }
}
