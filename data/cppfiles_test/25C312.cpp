#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  FAST();
  long long t;
  cin >> t;
  while (t--) {
    int n;
    string s, t;
    cin >> s >> t;
    n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int ptr = 0;
        int flag = 0;
        for (int k = i; k <= j; k++) {
          if (ptr == t.size()) {
            ans = 1;
            break;
          }
          if (s[k] == t[ptr]) {
            ptr++;
          } else {
            flag = 1;
            break;
          }
        }
        int ptr2 = j - 1;
        while (ptr < t.size() && ptr2 >= 0) {
          if (s[ptr2] == t[ptr]) {
            ptr++;
            ptr2--;
          } else {
            flag = 1;
            break;
          }
        }
        if (ptr != t.size()) {
          flag = 1;
        }
        if (flag == 0) {
          ans = 1;
        }
      }
    }
    if (ans == 0) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}
