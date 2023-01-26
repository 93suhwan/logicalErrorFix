#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << " ! ";
  err(++it, args...);
}
const long long N = 5e5 + 7, N1 = 25, inf = 2e18;
const long double eps = 1e-8;
const long long M = 1e9 + 7;
long long x, i;
int main() {
  long long tt;
  cin >> tt;
  set<long long> s;
  vector<long long> a;
  for (i = 1; i * i <= M; i++) s.insert(i * i);
  for (i = 1; i * i * i <= M; i++) s.insert(i * i * i);
  for (long long i : s) a.push_back(i);
  while (tt--) {
    cin >> x;
    x = upper_bound(a.begin(), a.end(), x) - a.begin();
    cout << x << "\n";
  }
}
