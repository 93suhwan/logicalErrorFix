#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using namespace chrono;
void ip(vector<long long int> &arr) {
  for (long long int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  long long int sum = 0;
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]]++;
  }
  long long int z = m[0];
  long long int ans = ((1LL << z)) * (m[1]);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto start1 = high_resolution_clock::now();
  long long int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  cerr << "Time: " << duration.count() / 1000 << "\n";
}
