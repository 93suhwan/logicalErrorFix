#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int flag = 0;
    if (n % 2 == 0)
      flag = 1;
    else {
      for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
