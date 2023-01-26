#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    string s[n];
    for (long long i = 0; i < n; i++) cin >> s[i];
    int k = 5;
    while (k--) {
      int x = 0, y = -1, pre = 0;
      vector<int> v;
      v.clear();
      for (long long i = 0; i < n; i++) {
        x = 0;
        for (long long j = 0; j < s[i].size(); j++) {
          if (s[i][j] == ('a' + k))
            x++;
          else
            x--;
        }
        v.push_back(x);
      }
      sort(v.begin(), v.end(), greater<int>());
      for (long long i = 0; i < n; i++) {
        if (pre + v[i] < 1) {
          y = i;
          break;
        }
        pre += v[i];
      }
      if (y == -1) y = n;
      sum = max(sum, y);
    }
    cout << sum << endl;
  }
}
