#include <bits/stdc++.h>
using namespace std;
template <class R>
inline void Checkmax(R &A, R B) {
  return A < B ? A = B, 1 : 0;
}
template <class R>
inline void Checkmin(R &A, R B) {
  return A > B ? A = B, 1 : 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    long long Tot = 0;
    for (int i = 1; i <= N; ++i) {
      int A;
      cin >> A;
      Tot += A;
    }
    cout << (Tot % N == 0 ? 0 : 1) << endl;
  }
  return 0;
}
