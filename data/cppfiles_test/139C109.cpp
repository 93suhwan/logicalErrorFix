#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    char a[101], b[51], c[51];
    cin >> a;
    int n = strlen(a);
    if (n % 2 != 0)
      cout << "NO\n";
    else {
      int k = 0, i;
      for (i = 0; i < (n / 2); i++) b[i] = a[i];
      b[i] = '\0';
      for (i = (n / 2); i < n; i++) c[k++] = a[i];
      c[k] = '\0';
      if (!(strcmp(b, c)))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
