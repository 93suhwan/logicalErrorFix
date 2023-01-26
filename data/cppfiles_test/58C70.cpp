#include <bits/stdc++.h>
using namespace std;
char a[1000], b[1000];
int main() {
  int l;
  cin >> l;
  for (int j = 1; j <= l; j++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    int o = 0;
    for (int i = 2; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        cout << "NO";
        o++;
        break;
      }
    }
    if (o == 0) cout << "YES";
    cout << endl;
  }
  return 0;
}
