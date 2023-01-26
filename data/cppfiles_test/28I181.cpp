#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 10;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
long long a[MAX];
long long m[MAX];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int t;
  cin >> t;
  while (t--) {
    memset(m, 0, sizeof(m));
    long long n;
    cin >> n;
    long long mm;
    cin >> mm;
    long long x;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x <= i) {
        int k = i - x;
        m[k]++;
      } else if (x > i) {
        int k = x - i;
        k = n - k;
        m[k]++;
      }
    }
    for (int i = 0; i < n; i++) {
      long long k = n - m[i];
      long long j = (k + 1) / 2;
      if (j <= mm) ans.push_back(i);
    }
    cout << ans.size() << " ";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
    ans.clear();
  }
  return 0;
}
