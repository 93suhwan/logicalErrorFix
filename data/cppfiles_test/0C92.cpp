#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first;
    A[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j += 2) {
      A[i].first[j] = 'Z' - A[i].first[j];
    }
  }
  sort(A.begin(), A.end());
  for (auto it : A) {
    cout << it.second << " ";
  }
  cout << "\n";
  return 0;
}
