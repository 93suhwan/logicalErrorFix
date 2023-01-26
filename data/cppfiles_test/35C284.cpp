#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
using namespace std;
long long int mod = 1000000007LL;
template <class A = long long int>
void Out(vector<A> a) {
  for (long long int i = (long long int)0; i < (long long int)a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
template <class A = long long int>
void In(vector<A> &a, long long int N) {
  A cur;
  for (long long int i = (long long int)0; i < (long long int)N; i++) {
    cin >> cur;
    a.push_back(cur);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  for (long long int t = (long long int)0; t < (long long int)T; t++) {
    long long int N, M;
    cin >> N >> M;
    if (N > M) {
      cout << 0 << endl;
      continue;
    }
    M++;
    long long int D = (long long int)log2(4LL * M);
    long long int y = 0LL;
    for (long long int i = D - 1; i >= 0; i--) {
      long long int dN = N & (1LL << i);
      long long int dM = M & (1LL << i);
      if (dN != 0LL && dM == 0LL) {
        break;
      }
      if (dN == 0LL && dM != 0LL) {
        y += (1LL << i);
      }
    }
    cout << y << endl;
  }
  return 0;
}
