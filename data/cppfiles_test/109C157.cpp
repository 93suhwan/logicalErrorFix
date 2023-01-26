#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  int i, j, k;
  cin >> t;
  while (t--) {
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0;
    for (i = 0; i < n; i++) {
      if (str[i] > '0') cnt += str[i] - '0' + 1;
    }
    if (str.back() > '0') cnt--;
    cout << cnt << "\n";
  }
}
