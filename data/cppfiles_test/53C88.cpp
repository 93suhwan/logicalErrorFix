#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    bool all_clear = true;
    int one_clear = 0, biggest_pos = 0;
    int ans = 0, n;
    char c;
    string str;
    cin >> n >> c;
    cin >> str;
    for (int i = 0; i < n; i++) {
      if (str[i] == c)
        biggest_pos = i + 1;
      else
        all_clear = false;
    }
    if (all_clear) {
      cout << "0"
           << "\n";
    } else {
      if (biggest_pos > n / 2) {
        cout << "1"
             << "\n"
             << biggest_pos << "\n";
      } else {
        cout << "2"
             << "\n";
        int ans = n % 2 == 0 ? n - 1 : n;
        cout << "2 " << ans << "\n";
      }
    }
  }
}
