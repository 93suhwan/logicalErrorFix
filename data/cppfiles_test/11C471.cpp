#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int MOD = 1000000007;
const int MX = 100005;
const long double pie = 2 * acos(0.0);
vector<long long int> dp(MX, 0);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test_c;
  cin >> test_c;
  while (test_c--) {
    int i, j;
    int n;
    cin >> n;
    vector<vector<int>> a(5);
    for (i = 0; i < n; i++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      int tot = (int)(s).size();
      for (j = 0; j < 5; j++) {
        int var = 0;
        if (!binary_search(s.begin(), s.end(), (char)(j + 'a'))) {
          a[j].push_back(var - tot);
          continue;
        }
        var = upper_bound(s.begin(), s.end(), (char)(j + 'a')) -
              lower_bound(s.begin(), s.end(), (char)(j + 'a'));
        a[j].push_back(var - (tot - var));
      }
    }
    int sum = 0;
    for (i = 0; i < 5; i++) {
      int counter = 0;
      int count = 0;
      sort(a[i].begin(), a[i].end());
      reverse(a[i].begin(), a[i].end());
      for (j = 0; j < n; j++) {
        if (counter + a[i][j] > 0) {
          count++;
          counter += a[i][j];
        }
      }
      sum = max(sum, count);
    }
    cout << sum << "\n";
  }
  return 0;
}
