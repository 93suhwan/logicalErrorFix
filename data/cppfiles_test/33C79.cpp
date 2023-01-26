#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> vec(n, 0);
    for (int i = 0; i < n; i++) cin >> vec[i];
    long long int ans = 0;
    for (int i = 0; i < n - 1; i++)
      if (ans < vec[i] * vec[i + 1]) ans = vec[i] * vec[i + 1];
    cout << ans << endl;
  }
  return 0;
}
