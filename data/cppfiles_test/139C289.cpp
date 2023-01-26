#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 1;
bool comparator(int a, int b) { return a > b; }
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (n % 2 != 0) {
    cout << "NO" << endl;
  } else {
    int low = 0;
    int high = n / 2;
    bool flag = true;
    while (high < n) {
      if (s[low] == s[high]) {
        low++;
        high++;
        continue;
      } else {
        flag = false;
      }
      low++;
      high++;
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
