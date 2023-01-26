#include <bits/stdc++.h>
using namespace std;
long long countt(long long n) {
  set<long long> s;
  for (long long i = 1; i <= sqrt(n); i++) s.emplace(i * i);
  for (long long i = 1; i <= cbrt(n); i++) s.emplace(i * i * i);
  return s.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << countt(n) << "\n";
  }
  return 0;
}
