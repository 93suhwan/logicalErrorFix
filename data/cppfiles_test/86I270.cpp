#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t{0};
  cin >> t;
  while (t--) {
    long long n{0};
    cin >> n;
    string matrix[2];
    cin >> matrix[0] >> matrix[1];
    long long allzero{0};
    long long allone{0};
    long long ans{0};
    long long two = 2;
    for (long long j = 0; j < n; j++) {
      if (matrix[0][j] == '0' && matrix[1][j] == '0') {
        allzero++;
      } else if (matrix[0][j] == '1' && matrix[1][j] == '1') {
        allone++;
      } else {
        ans += 2;
        if (allone == 0) {
          ans += (allzero * 1);
        } else {
          if (allzero == 0)
            ans += 0;
          else
            ans += max(two, allzero);
        }
        allzero = 0;
        allone = 0;
      }
    }
    if (allone == 0) {
      ans += (allzero * 1);
    } else {
      if (allzero == 0)
        ans += 0;
      else
        ans += max(two, allzero);
    }
    cout << ans << '\n';
  }
  return 0;
}
