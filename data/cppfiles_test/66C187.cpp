#include <bits/stdc++.h>
using namespace std;
long long tc = 1;
int main() {
  ios::sync_with_stdio(0);
  vector<long long> v;
  for (int i = 1; v.size() <= 1000; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    v.push_back(i);
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << v[n - 1] << "\n";
  }
  return 0;
}
