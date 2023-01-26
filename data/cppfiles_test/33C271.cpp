#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(long long a, long long b) { return (a > b); }
int main() {
  c_p_c();
  cout << fixed << setprecision(10);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    int s = 0;
    cin >> n;
    long long a[n + 1];
    long long maxa = INT_MIN;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 1; i < n; i++) {
      maxa = max(maxa, a[i] * a[i - 1]);
    }
    cout << maxa << "\n";
  }
  return 0;
}
