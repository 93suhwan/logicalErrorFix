#include <bits/stdc++.h>
using namespace std;
vector<long long int> vl, wg;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m = 0, cnt = 0;
    char c;
    string s, s2;
    cin >> n >> c;
    cin >> s2;
    s = "s";
    s = s + s2;
    for (int i = 1; i <= n; i++) {
      int j = i, k = 0, cnt = 0;
      while (j <= n) {
        k++;
        if (s[j * k] == c) {
          cnt++;
        } else
          break;
      }
      if (cnt == n / i) {
        if (i == 1) {
          cout << "0" << endl;
          m = -1;
        } else {
          cout << "1" << endl << i << endl;
          m = -1;
        }
        break;
      }
    }
    if (m == 0) {
      cout << "2" << endl << n << " " << n - 1 << endl;
    }
  }
  return 0;
}
