#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e9 + 7;
const long long int mod = 1e9 + 7;
void call_priyanshu() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
long long int mini(long long int a, long long int b) {
  if (a >= b) return b;
  return a;
}
long long int maxi(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> A(n + 1);
  for (long long int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  long long int val = 1;
  vector<long long int> B;
  long long int ma = 1;
  long long int x = 0;
  if (n % 2 != 0) {
    for (long long int i = 2; i <= n; i++) {
      if (A[i] > A[i - 1])
        continue;
      else {
        cout << "YES";
        cout << "\n";
        return;
      }
    }
  }
  x ^= val;
  ma = maxi(ma, val);
  if (n % 2 != 0) {
    cout << "NO";
  } else
    cout << "YES";
  cout << "\n";
}
int main() {
  call_priyanshu();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
