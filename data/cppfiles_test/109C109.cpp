#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j;
  cin >> t;
  while (t--) {
    long long s = 0;
    int n;
    string a;
    cin >> n;
    cin >> a;
    for (j = 0; j < n - 1; j++) {
      if (a[j] != '0') s = s + (a[j] - '0') + 1;
    }
    s = s + (a[n - 1] - '0');
    cout << s << endl;
  }
}
