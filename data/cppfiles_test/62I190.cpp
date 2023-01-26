#include <bits/stdc++.h>
using namespace std;
long long a[1000005], b[1000005];
int main() {
  cin.tie(nullptr);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    ;
    if (a[1] == 1) {
      cout << n + 1 << " ";
      for (long long i = 2; i <= n + 1; i++) {
        cout << i - 1 << " ";
      }
      cout << endl;
      continue;
    }
    if (a[n] == 0) {
      for (long long i = 2; i <= n + 2; i++) {
        cout << i - 1 << " ";
      }
      cout << endl;
      continue;
    }
    vector<long long> v;
    long long i;
    for (i = 1; i < n; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        v.push_back(i + 1);
        v.push_back(n + 1);
        i++;
        break;
      } else
        v.push_back(i + 1);
    }
    while (i < n) {
      v.push_back(i + 1);
      i++;
    }
    if (v.size() != n + 2) {
      cout << -1 << endl;
    } else {
      for (i = 1; i <= n + 1; i++) cout << v[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
