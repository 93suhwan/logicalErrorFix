#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> v) {
  for (auto &x : (v)) cout << x << ' ';
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0, j = 1, n1 = n;
    do {
      n1 = n;
      if (j % 2) {
        for (int i = 0; i < n; ++i) {
          if (s[i] == 'A') {
            cnt++;
          }
          if (s[i] == 'B') {
            cnt++;
          }
        }
        if (cnt == 2) {
          n -= 2;
        }
        cnt = 0;
      } else if (j % 2 == 0) {
        for (int i = 0; i < n; ++i) {
          if (s[i] == 'B') {
            cnt++;
          }
          if (s[i] == 'C') {
            cnt++;
          }
        }
        if (cnt == 2) {
          n -= 2;
        }
        cnt = 0;
      }
      j++;
    } while (n1 != n && n <= 0);
    if (n == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
