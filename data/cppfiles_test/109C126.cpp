#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T, t, N, n, count;
  string s;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> N;
    cin >> s;
    count = s[N - 1] - '0';
    for (n = N - 2; n >= 0; n--) {
      if (s[n] != '0') {
        count = count + (s[n] - '0') + 1;
      }
    }
    cout << count << "\n";
  }
}
