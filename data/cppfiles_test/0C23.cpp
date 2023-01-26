#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
int MOD = 1e9 + 7;
double eps = 1e-12;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  string* arr = new string[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (j % 2 == 1) {
        arr[i][j] = 'A' + (25 - (arr[i][j] - 'A'));
      }
    }
  }
  map<string, long long> umap;
  for (long long i = 0; i < n; i++) {
    umap[arr[i]] = i + 1;
  }
  for (auto i = umap.begin(); i != umap.end(); i++) {
    cout << i->second << " ";
  }
  cout << "\n";
}
