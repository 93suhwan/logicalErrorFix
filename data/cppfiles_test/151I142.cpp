#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_code();
  vector<long long int> v;
  map<pair<long long int, long long int>, long long int> m;
  long long int TT;
  long long int count = 0;
  cin >> TT;
  for (long long int t = 0; t < TT; t++) {
    long long int n;
    cin >> n;
    if (n == 1) {
      long long int tt;
      cin >> tt;
      v.push_back(tt);
      count++;
    } else {
      long long int t1, t2;
      cin >> t1 >> t2;
      m.insert({{t1, count}, t2});
    }
  }
  for (auto x : m) {
    if (x.first.second == 0) {
      continue;
    } else {
      for (long long int j = 0; j < x.first.second; j++) {
        if (v[j] == x.first.first) {
          v[j] = x.second;
        }
      }
    }
  };
  for (auto n : v) {
    cout << n << " ";
  }
  cout << "\n";
  ;
  return 0;
}
