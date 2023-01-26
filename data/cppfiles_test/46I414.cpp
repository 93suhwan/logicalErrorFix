#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
void solve() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto& it : c) {
    cin >> it;
  }
  long long answer = 0;
  for (int i = 0; i < n; i += 2) {
    long long curr = c[i];
    for (int j = i + 1; j < n; ++j) {
      if (j % 2 == 0) {
        curr += c[j];
      } else {
        curr -= c[j];
        if (curr < 0 && -curr <= c[j]) {
          answer += min(1ll * c[i], c[j] + curr);
        }
        if (curr > 0 && curr <= c[i]) {
          answer += min(c[i] - curr, 1ll * c[j]);
        }
        if (curr == 0) {
          answer += min(c[i], c[j]);
        }
      }
      if (curr < 0) {
        break;
      }
    }
  }
  cout << answer << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  int i = 1;
  while (t--) {
    solve();
  }
  return 0;
}
