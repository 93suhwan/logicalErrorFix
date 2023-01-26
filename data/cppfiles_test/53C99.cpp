#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    long long int n, cnt = 0, temp = 0;
    char ch;
    string s;
    cin >> n >> ch;
    cin >> s;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == ch) continue;
      cnt++;
    }
    if (cnt != 0) {
      temp--;
      for (long long int i = 2; i <= n; i++) {
        long long int flag = 1, j = i;
        while (j <= n) {
          if (s[j - 1] == ch) {
            j += i;
            continue;
          }
          flag = 0;
          break;
        }
        if (!flag) continue;
        temp = i;
        break;
      }
      if (temp != -1) {
        cout << 1 << "\n";
        cout << temp << "\n";
      } else {
        if (s[n - 1] == ch) {
          cout << 1 << "\n";
          cout << n << "\n";
        } else {
          if (cnt != 1) {
            cout << 2 << "\n";
            cout << n << " " << n - 1 << "\n";
          } else {
            cout << 1 << "\n";
            cout << n - 1 << "\n";
          }
        }
      }
    } else
      cout << 0 << "\n";
  }
}
