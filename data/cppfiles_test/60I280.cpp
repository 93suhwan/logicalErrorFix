#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  int a[n];
  int minn = INT_MAX;
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxx = max(maxx, a[i]);
  }
  minn = *min_element(a, a + n);
  return minn & maxx;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    cout << solve() << endl;
  }
}
