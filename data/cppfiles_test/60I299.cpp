#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long mod = 1e9 + 7;
const long long MULTI_TESTS = 1;
void unstoppable() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0, ThxDem = n; i < ThxDem; i++) cin >> a[i];
  long long mn = *min_element(a.begin(), a.end());
  for (int i = 0, ThxDem = n; i < ThxDem; i++) {
    long long tmp = a[i] & a[n - 1 - i];
    a[i] = tmp;
  }
  cout << min(*max_element(a.begin(), a.end()), mn) << endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (MULTI_TESTS) {
    long long Q;
    cin >> Q;
    while (Q--) {
      unstoppable();
    }
  } else {
    unstoppable();
  }
  return 0;
}
