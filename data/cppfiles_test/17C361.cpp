#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 2.5 * 1e6 + 5;
const long long int MOD = 1000000007;
const int MN = 4e5 + 1;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
void getip(long long int n, vector<long long int> &v) {
  for (long long int(i) = 0; (i) < n; (i)++) cin >> v[i];
}
void MAIN(long long int tt) {
  long long int n;
  cin >> n;
  vector<vector<long long int> > v(n, vector<long long int>(5));
  for (long long int(i) = 0; (i) < n; (i)++) getip(5, v[i]);
  long long int res = 0;
  for (int i = 1; i < n; ++i) {
    int sc = 0;
    for (int j = 0; j < 5; ++j) {
      if (v[i][j] < v[res][j]) sc++;
    }
    if (sc >= 3) res = i;
  }
  for (int i = 0; i < res; ++i) {
    int sc = 0;
    for (int j = 0; j < 5; ++j) {
      if (v[i][j] < v[res][j]) sc++;
    }
    if (sc >= 3) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << res + 1 << "\n";
}
int main() {
  fast();
  long long int TEST_CASES = 1;
  cin >> TEST_CASES;
  for (long long int(i) = 0; (i) < TEST_CASES; (i)++) MAIN(i + 1);
  return 0;
}
