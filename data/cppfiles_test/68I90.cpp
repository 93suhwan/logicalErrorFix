#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> go{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(pair<int, int> p, pair<int, int> n) {
  return p.first >= 0 && p.first < n.first && p.second >= 0 &&
         p.second < n.second;
}
long long get(vector<long long> af1, long long i) {
  if (af1[i] == i) return i;
  return get(af1, af1[i]);
}
void solve() {
  long long n;
  cin >> n;
  long long temp = sqrt(n);
  long long count = n - temp * temp;
  if (count == 0) {
    cout << temp << " " << 1 << "\n";
    return;
  }
  if (count <= 1 + temp) {
    cout << count % (1 + temp) << " " << temp + 1 << "\n";
    return;
  } else {
    cout << 1 + temp << " " << 2 * (1 + temp) - count << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _t = 1;
  cin >> _t;
  for (long long i = 1; i <= _t; i++) {
    solve();
  }
}
