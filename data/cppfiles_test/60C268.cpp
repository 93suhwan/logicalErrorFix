#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int enu;
  cin >> enu;
  vector<int> v(enu);
  long long int sumation = 0;
  map<int, int> mp;
  for (int i = 0; i < enu; i++) {
    cin >> v[i];
    sumation += v[i];
  }
  sumation *= 2;
  if (sumation % enu != 0) {
    cout << 0 << "\n";
    return;
  }
  sumation /= enu;
  long long int countt = 0;
  for (int i = 0; i < enu; i++) {
    long long int x = sumation - v[i];
    countt += mp[x];
    mp[v[i]]++;
  }
  cout << countt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
