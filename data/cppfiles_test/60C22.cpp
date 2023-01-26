#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, minn = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < minn) minn = a[i];
    }
    int sum = 0;
    while (minn) {
      sum++;
      minn >>= 1;
    }
    string s = "";
    for (int i = 0; i < sum; i++) {
      int flag = 1;
      for (int j = 0; j < n; j++) {
        int tot = a[j] >> i & 1;
        if (tot == 0) {
          flag = 0;
          break;
        }
      }
      if (flag)
        s += "1";
      else
        s += "0";
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '1') ans += (int)pow(2, i);
    printf("%d\n", ans);
  }
  return 0;
}
