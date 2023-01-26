#include <bits/stdc++.h>
using namespace std;
const int MM = int(2e5) + 5;
const string io_file = "";
int n;
int a[MM];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long m = -1;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      m = max(m, long long(a[i - 1]) * long long(a[i]));
    }
    cout << m << "\n";
  }
  return 0;
}
