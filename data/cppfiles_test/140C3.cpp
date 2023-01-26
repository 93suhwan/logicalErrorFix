#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = sqrt((double)n);
    int k = cbrt((double)n);
    int p = cbrt((double)a);
    int ans = a + (k - p);
    cout << ans << endl;
  }
}
