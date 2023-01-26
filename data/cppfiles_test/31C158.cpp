#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979323846;
long long mod = 1000000000 + 7;
const int N = 1e5 + 5;
vector<bool> prime(N, true);
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}
bool comp(long long a, long long b) { return (a > b); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> vt(n);
  for (long long i = 0; i < n; i += 1) cin >> vt[i];
  vector<long long> b(n);
  for (long long i = 0; i < n - 1; i += 2) {
    if (vt[i] > 0)
      b[i] = abs(vt[i + 1]);
    else
      b[i] = -abs(vt[i + 1]);
    if (vt[i + 1] > 0)
      b[i + 1] = -abs(vt[i]);
    else
      b[i + 1] = abs(vt[i]);
  }
  if (n % 2 == 0) {
    for (auto x : b) cout << x << " ";
  } else {
    long long idx = 0;
    for (long long i = 0; i < n - 1; i += 1) {
      if (vt[i] > 0) {
        if (b[i] + abs(vt[n - 1]) != 0) {
          b[i] += abs(vt[n - 1]);
          idx = i;
          break;
        }
      } else {
        if (b[i] - abs(vt[n - 1]) != 0) {
          b[i] -= abs(vt[n - 1]);
          idx = i;
          break;
        }
      }
    }
    if (vt[n - 1] > 0) {
      b[n - 1] = -abs(vt[idx]);
    } else
      b[n - 1] = abs(vt[idx]);
    for (auto x : b) cout << x << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
