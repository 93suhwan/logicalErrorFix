#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = (ans * x) % 1000000007;
      n = n - 1;
    } else {
      x = (x * x) % 1000000007;
      n = n / 2;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != s2[i]) cnt++;
    }
    cout << cnt << endl;
  }
}
