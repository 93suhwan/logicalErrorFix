#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
char a[N], b[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf(" %c", &a[i]);
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == b[i]) ans++;
    cout << n - ans << "\n";
  }
  return 0;
}
