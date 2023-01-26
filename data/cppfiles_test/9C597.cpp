#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char a[60];
    cin >> a;
    int num = 0;
    int n = strlen(a);
    int ans = 0;
    int s[1000] = {0};
    for (int i = 0; i < n; i++) {
      s[a[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[a[i]] == 1) {
        cnt++;
        s[a[i]] = 0;
      } else if (s[a[i]] >= 2) {
        cnt += 2;
        s[a[i]] = 0;
      }
    }
    cout << cnt / 2 << endl;
  }
}
