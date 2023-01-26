#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
bool is_p(long long num) {
  for (long long i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (!is_p(sum)) {
    cout << n << "\n";
    for (long long i = 1; i <= n; i++) {
      cout << i << " ";
    }
    return;
  }
  cout << n - 1 << "\n";
  for (long long i = 0; i < n; i++) {
    if (!is_p(sum - v[i])) {
      for (long long j = 0; j < n; j++) {
        if (j != i) {
          cout << j + 1 << " ";
        }
      }
      return;
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
