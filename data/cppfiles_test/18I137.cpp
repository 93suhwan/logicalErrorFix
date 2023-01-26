#include <bits/stdc++.h>
const long long binf = 1000000000000000000;
const long long inf = 1e9 + 5;
using namespace std;
unsigned long long binpow(unsigned long long x, unsigned long long y) {
  if (y == 0) {
    return 1;
  }
  unsigned long long temp = binpow(x, y / 2);
  temp = temp * temp;
  if (y % 2 != 0) {
    temp = x * temp;
  }
  return temp;
}
void solve() {
  long long int n, d;
  cin >> n >> d;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<long long int> ind;
  multiset<long long int> ms;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) {
      ind.insert(i);
      ms.insert(i);
    }
  }
  for (auto it = ind.begin(); it != ind.end(); it++) {
    long long int fn = *it;
    if (ms.find(fn) != ms.end()) {
      ms.erase(ms.find(fn));
      long long int x = (fn + d) % n;
      while (ms.find(x) != ms.end()) {
        ms.erase(ms.find(x));
        x = (x + d) % n;
        if (x == fn) {
          cout << -1 << endl;
          return;
        }
      }
    }
    if (ms.empty()) {
      break;
    }
  }
  map<long long int, long long int> m;
  for (auto it = ind.begin(); it != ind.end(); it++) {
    long long int x = *it;
    long long int y = (x + d) % n;
    pair<long long int, long long int> p = make_pair(y, x);
    m.insert(p);
  }
  long long int ans = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    long long int x = (*it).second;
    long long int y = (*it).first;
    if (ind.find(y) == ind.end()) {
      long long int count = 1;
      while (m.find(x) != m.end()) {
        auto itr = m.find(x);
        x = (*itr).second;
        count++;
      }
      ans = max(ans, count);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tests;
  cin >> tests;
  for (int I = 1; I <= tests; I++) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
