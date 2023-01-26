#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  if (n % 2 == 0) {
    cout << "YES";
  } else {
    bool cool = true;
    for (long long int i = 1; i < n; i++) {
      if (vec[i - 1] >= vec[i]) {
        cout << "YES";
        return;
      } else if (vec[i - 1] < vec[i])
        cool = false;
    }
    if (cool)
      cout << "YES";
    else
      cout << "NO";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
    cout << '\n';
  }
  return 0;
}
