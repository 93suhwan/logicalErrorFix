#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  static long long min_left[1001][1001], min_right[1001][1001];
  int n;
  vector<int> c;
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i += 2) {
    min_left[i][i] = 1;
    long long cur_level = 0;
    for (int j = i + 2; j <= n; j += 2) {
      min_left[i][j] = max(min_left[i][j - 2], cur_level + c[j - 2]);
      cur_level += c[j - 2] - c[j - 1];
    }
  }
  for (int j = n - (n + 1) % 2; j >= 0; j -= 2) {
    min_right[j][j] = 1;
    long long cur_level = 0;
    for (int i = j - 2; i >= 0; i -= 2) {
      min_right[i][j] = max(min_right[i + 2][j], cur_level + c[i + 1]);
      cur_level += c[i + 1] - c[i];
    }
  }
  long long result = 0;
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 1; j < n; j += 2) {
      long long cnt = max(
          min(c[i] + 1 - min_left[i + 1][j], c[j] + 1 - min_right[i + 1][j]),
          0LL);
      result += cnt;
    }
  }
  cout << result << '\n';
  return 0;
}
