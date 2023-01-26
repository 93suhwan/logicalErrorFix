#include <bits/stdc++.h>
using namespace std;
struct Solution {
  void run() {
    int n;
    string s;
    cin >> n >> s;
    int first = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        first = i;
        break;
      }
    }
    if (first == -1) {
      for (int i = 0; i < n; i++) {
        s[i] = i % 2 == 0 ? 'B' : 'R';
      }
    } else {
      for (int i = first; i < n - 1; i++) {
        if (s[i + 1] == '?') {
          s[i + 1] = s[i] == 'B' ? 'R' : 'B';
        }
      }
      first--;
      while (first >= 0) {
        s[first] = s[first + 1] == 'B' ? 'R' : 'B';
        first--;
      }
    }
    cout << s << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  Solution solution = Solution();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution.run();
  }
  return 0;
}
