#include <bits/stdc++.h>
const long long int mod1 = 1000000007;
const long long int mod2 = 998244353;
const long long int infi = 1e18;
const long long int eps = 1e-9;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int m;
    cin >> m;
    vector<vector<long long int>> v(2, vector<long long int>(m)),
        v1(2, vector<long long int>(m, 0));
    for (long long int j = 0; j < m; j++) {
      cin >> v[0][j];
    }
    for (long long int j = 0; j < m; j++) {
      cin >> v[1][j];
    }
    if (m == 1) {
      cout << "0"
           << "\n";
      continue;
    }
    v1[0][0] = v[0][0] = 0;
    v1[1][m - 1] = v[1][m - 1] = 0;
    for (long long int j = 1; j < m; j++) {
      v1[0][j] = v1[0][j - 1] + v[0][j];
    }
    for (int j = m - 2; j >= 0; j--) {
      v1[1][j] = v1[1][j + 1] + v[1][j];
    }
    long long int ma = INT_MIN, c = 0;
    vector<long long int> re;
    for (long long int j = 0; j < m; j++) {
      re.push_back(max(v1[1][0] - v1[1][j], v1[0][m - 1] - v1[0][j]));
    }
    cout << *min_element(re.begin(), re.end()) << "\n";
  }
}
