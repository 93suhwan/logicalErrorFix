#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char str[N], t[N];
    cin >> str;
    strcpy(t, str);
    int a[N], b[N];
    sort(t, t + n);
    int i;
    for (i = 0; i < n; i++) {
      a[i] = str[i] - 'a';
      b[i] = t[i] - 'a';
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != b[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
