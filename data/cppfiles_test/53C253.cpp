#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;
    int cnt = count(str.begin(), str.end(), ch);
    if (cnt == n) {
      cout << "0\n";
      continue;
    }
    int bound = n >> 1;
    bound++;
    bool flag = false;
    int ans;
    for (int i = n; i >= bound; i--) {
      if (str[i - 1] == ch) {
        flag = true;
        ans = i;
        break;
      }
    }
    if (flag)
      cout << "1\n" << ans << "\n";
    else {
      cout << 2 << "\n";
      cout << n - 1 << " " << n << "\n";
    }
  }
  return 0;
}
