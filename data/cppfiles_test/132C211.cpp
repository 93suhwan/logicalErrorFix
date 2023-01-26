#include <bits/stdc++.h>
using namespace std;
void code() {
  long long n = 7;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    code();
  }
  return 0;
}
