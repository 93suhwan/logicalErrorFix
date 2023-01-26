#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
template <class T>
inline bool maxx(T &A, T B) {
  return A < B ? (A = B, 1) : 0;
}
template <class T>
inline bool minn(T &A, T B) {
  return A > B ? (A = B, 1) : 0;
}
using namespace std;
void files() {}
const int N = 2e5;
const long long mod = 1e9 + 7;
int n, a[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  files();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int dem = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dem += a[i];
    }
    if (dem % n == 0)
      cout << 0;
    else
      cout << 1;
    cout << '\n';
  }
}
