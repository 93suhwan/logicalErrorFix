#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int temp, prev, curr, i, j, k;
  long long int t, n;
  cin >> t;
  while (t-- > 0) {
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    long long int cnt = 0;
    vector<long long int> ans;
    if (s[n - 1] != c) {
      ans.push_back(n - 1);
      cnt++;
    }
    if (s[n - 2] != c) {
      ans.push_back(n);
      cnt++;
    }
    if (!cnt) {
      for (i = 0; i < n - 2; i++) {
        if (s[i] != c) {
          cnt++;
          ans.push_back(n);
          break;
        }
      }
    }
    cout << cnt;
    cout << "\n";
    for (auto x : ans) {
      cout << x << " ";
    }
    if (cnt) cout << "\n";
  }
}
