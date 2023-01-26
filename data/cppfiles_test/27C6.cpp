#include <bits/stdc++.h>
using namespace std;
using namespace std;
void solve();
bool comp(pair<long long int, long long int>& a,
          pair<long long int, long long int>& b) {
  if (a.first == b.first) {
    return (a.second > b.second);
  } else {
    return (a.first < b.first);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  k--;
  if (k <= 0) {
    cout << "NO" << endl;
    return;
  }
  if (n == 1 && m == 0 && k > 0) {
    cout << "YES" << endl;
  } else if (n == 1) {
    cout << "NO" << endl;
  } else {
    if (m <= (n * (n - 1) / 2) && m >= n - 1) {
      if (k > 2) {
        cout << "YES" << endl;
      } else if (k > 1 && m == (n * (n - 1)) / 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
