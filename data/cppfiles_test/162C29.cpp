#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 5;
long long n;
long long arr[maxn];
bool bs(long long val) {
  vector<long long> temp;
  temp.reserve(n);
  vector<long long> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = 0;
    temp.emplace_back(arr[i]);
  }
  for (int i = n - 1; i >= 2; i--) {
    long long give = min(max(0LL, res[i] + temp[i] - val), temp[i]);
    give /= 3;
    res[i - 1] += give;
    res[i - 2] += 2 * give;
    temp[i] -= 3 * give;
  }
  for (int i = 0; i < n; i++) {
    if (res[i] + temp[i] < val) {
      return false;
    }
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long l = 1, r = inf, m;
  while (l != r - 1) {
    m = (l + r) >> 1;
    if (bs(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
