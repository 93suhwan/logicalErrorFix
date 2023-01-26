#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<long long> ans1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      vec[i] = int(s[i]) - int('0');
    }
    long long cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (vec[i] > 0) cnt++;
      ans += vec[i];
    }
    if (vec[n - 1] != 0) ans--;
    ans1.push_back(ans + cnt);
  }
  for (int i = 0; i < ans1.size(); i++) cout << ans1[i] << endl;
}
