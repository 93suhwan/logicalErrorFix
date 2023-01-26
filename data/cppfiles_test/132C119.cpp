#include <bits/stdc++.h>
using namespace std;
void sol() {
  vector<long long> v(7);
  for (long long i = 0; i < 7; i++) cin >> v[i];
  cout << v[0] << " " << v[1] << " " << (v[6] - (v[0] + v[1])) << "\n";
}
int main() {
  long long t = 0;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
