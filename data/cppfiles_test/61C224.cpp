#include <bits/stdc++.h>
using namespace std;
int main() {
  long long _;
  cin >> _;
  while (_--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    vector<long long> cnt1(n), cnt2(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      cnt1[a[i] - 1]++, cnt2[b[i] - 1]++;
    }
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
      cnt += (cnt1[a[i] - 1] - 1) * (cnt2[b[i] - 1] - 1);
    long long all = n * (n - 1) * (n - 2) / 6;
    cout << all - cnt << endl;
  }
  return 0;
}
