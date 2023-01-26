#include <bits/stdc++.h>
using namespace std;
int a[200100];
int sub[200100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      sub[i] = sub[i - 1] + a[i - 1];
      a[i] = a[i] - sub[i];
    }
    sort(a + 1, a + 1 + n);
    cout << a[n] << endl;
    memset(sub, 0, sizeof(sub));
  }
}
