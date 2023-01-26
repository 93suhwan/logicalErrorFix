#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2", "avx", "fma", "sse", "sse2", "sse3", "ssse3", "sse4")
using namespace std;
const long long int MAXN = 200007;
long long int A[MAXN];
long long int N;
void f(long long int i) {
  if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
  return;
}
bool Sorted() {
  for (long long int g = 0; g < N - 1; ++g)
    if (A[g] > A[g + 1]) return false;
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  for (; T-- > 0;) {
    cin >> N;
    for (long long int g = 0; g < N; ++g) cin >> A[g];
    long long int CNT = 0;
    for (;;) {
      for (long long int g = 1; g <= N; ++g) {
        if (g & 1) {
          for (long long int s = 1; s <= N - 2; s += 2) f(s - 1);
          if (Sorted()) goto jump1;
          ++CNT;
        } else {
          for (long long int s = 2; s <= N - 1; s += 2) f(s - 1);
          if (Sorted()) goto jump1;
          ++CNT;
        }
      }
    }
  jump1:
    cout << (CNT > 0 ? CNT + 1 : CNT) << '\n';
  }
  exit(0);
  return (0);
}
