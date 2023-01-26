#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    long long answer = 0, b = a[n - 1];
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] > b) {
        b = a[i];
        answer++;
      }
    }
    cout << answer << endl;
  }
  return 0;
}
