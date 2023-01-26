#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N];
char b[N];
int c[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (b[i] == '0') p++;
    }
    int l = 1;
    for (int i = 1; i <= n; i++) {
      if (b[i] == '0')
        c[i] = l++;
      else
        c[i] = ++p;
    }
    for (int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << endl;
  }
  return 0;
}
