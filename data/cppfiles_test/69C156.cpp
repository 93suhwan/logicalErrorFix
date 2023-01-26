#include <bits/stdc++.h>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<long long> v(60);
void func() {
  for (int i = 0; i < 60; i++) {
    v[i] = pow(2, i);
  }
}
vector<int> get_dig(long long n) {
  vector<int> ans;
  while (n > 0) {
    ans.push_back(n % 10);
    n /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1, tt = 0;
  cin >> t;
  func();
  while (t--) {
    long long n;
    cin >> n;
    vector<int> d1 = get_dig(n);
    int s1 = d1.size(), s2, ans = INT_MAX;
    for (int k = 0; k < 60; k++) {
      vector<int> d2 = get_dig(v[k]);
      int pre = -1, ct = 0, f = 0;
      s2 = d2.size();
      for (int i = 0; i < s2; i++) {
        f = 0;
        for (int j = 0; j < s1; j++) {
          if (d2[i] == d1[j] && j > pre) {
            ct++;
            f = 1;
            pre = j;
            break;
          }
        }
        if (!f) break;
      }
      ans = min(ans, s2 - ct + s1 - ct);
    }
    cout << ans << endl;
  }
  return 0;
}
