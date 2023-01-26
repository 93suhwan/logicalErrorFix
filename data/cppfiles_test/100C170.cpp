#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
long long a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    long long maxx = a[1];
    for (int i = 2; i <= n; i++) {
      if (a[i] - a[i - 1] > maxx) maxx = a[i] - a[i - 1];
    }
    cout << maxx << endl;
  }
}
