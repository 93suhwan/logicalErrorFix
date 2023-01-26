#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mod = 1e9 + 7;
map<long long, long long> mp;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  cin >> n;
  vector<long long> a(n + 1);
  vector<long long> us(512);
  vector<long long> use(512);
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  us[0] = 1;
  use[0] = -1;
  for (long long i = 1; i < 512; ++i) use[i] = LLONG_MAX;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j < 512; ++j)
      if (us[j] && use[j] < a[i]) {
        long long x = j ^ a[i];
        us[x] = 1;
        use[x] = min(a[i], use[x]);
      }
  }
  vector<long long> v;
  for (long long i = 0; i < 512; ++i)
    if (us[i]) v.push_back(i);
  cout << v.size() << "\n";
  for (auto i : v) cout << i << " ";
}
