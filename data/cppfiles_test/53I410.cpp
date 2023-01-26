#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, n, i, idx;
  char c;
  string str;
  cin >> t;
  while (t--) {
    cin >> n >> c >> str;
    idx = -1;
    for (i = 0; i < n; i++)
      if (str[i] == c) idx = i;
    if (idx == -1) {
      cout << 0 << endl;
      continue;
    }
    idx++;
    if (idx > n / 2)
      cout << 1 << endl << idx << endl;
    else if (idx == 1)
      cout << 2 << endl << n - 1 << endl << n << endl;
    else if (n % idx == 0)
      cout << 1 << endl << n - 1 << endl;
    else
      cout << 1 << endl << n << endl;
  }
  return 0;
}
