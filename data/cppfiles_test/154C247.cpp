#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
const long long mod = 1e9 + 7;
const long long epsilon = 1e-7;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
void Solve() {
  vector<long long> A(3);
  for (int i = 0; i < 3; i++) cin >> A[i];
  sort((A).begin(), (A).end());
  if (A[0] == A[1] && A[2] % 2 == 0)
    cout << "YES"
         << "\n";
  else if (A[1] == A[2] && A[0] % 2 == 0)
    cout << "YES"
         << "\n";
  else if (A[0] == A[2] && A[1] % 2 == 0)
    cout << "YES"
         << "\n";
  else if (A[0] + A[1] == A[2])
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) Solve();
}
