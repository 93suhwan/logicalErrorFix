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
    long long visited[n];
    memset(visited, 0, sizeof(visited));
    long long ans{0};
    for (long long j = 0; j < n; j++) {
      if (matrix[0][j] == '1' && matrix[1][j] == '0') {
        ans += 2;
      } else if (matrix[0][j] == '0' && matrix[1][j] == '1') {
        ans += 2;
      } else if (matrix[0][j] == '0' && matrix[1][j] == '0') {
        ans += 1;
      } else {
        if (j - 1 >= 0 && matrix[0][j - 1] == '0' && matrix[1][j - 1] == '0' &&
            visited[j - 1] == 0) {
          ans += 1;
          visited[j - 1] = 1;
        } else if (j + 1 < n && matrix[0][j + 1] == '0' &&
                   matrix[1][j + 1] == '0' && visited[j + 1] == 0) {
          ans += 1;
          visited[j + 1] = 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
