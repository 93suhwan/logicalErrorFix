#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  set<long long> s;
  vector<long long> p;
  for (long long i = 1; i <= 100000; i++) {
    if (i * i <= 1e9) s.insert(i * i);
    if (i * i * i <= 1e9) s.insert(i * i * i);
  }
  for (auto i : s) {
    p.push_back(i);
  }
  while (q--) {
    long long n;
    cin >> n;
    long long l = upper_bound(p.begin(), p.end(), n) - p.begin();
    cout << l << endl;
  }
}
