#include <bits/stdc++.h>
using namespace std;
char str[58];
int a[50];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> str + 1;
    int ans = 0;
    for (int i = 1; i < str[i]; i++) {
      int x = str[i] - 'a';
      if (a[x] < 2) ans++;
      a[x]++;
    }
    memset(a, 0, sizeof a);
    cout << ans / 2 << endl;
  }
}
