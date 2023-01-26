#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int col, test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    char c1[n], c2[n];
    for (int i = 0; i < n; i++) cin >> c1[i];
    for (int i = 0; i < n; i++) cin >> c2[i];
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
      if (c1[i] == '1')
        count1++;
      else
        count0++;
      if (c2[i] == '1')
        count1++;
      else
        count0++;
    }
    if (count1 > count0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
