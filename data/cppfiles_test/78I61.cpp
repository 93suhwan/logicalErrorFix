#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> res;
    for (int i = 30; i >= 0; i--) {
      int c = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] & (1 << i)) c++;
      }
      if (c > 0 && c % (i + 1) == 0) res.push_back(i + 1);
    }
    reverse(res.begin(), res.end());
    for (auto p : res) cout << p << " ";
    cout << endl;
  }
}
