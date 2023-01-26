#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long N, K;
    cin >> N >> K;
    vector<long long> vect;
    for (long long i = 0; i < N; i++) {
      long long n;
      cin >> n;
      vect.push_back(n);
    }
    sort(vect.begin(), vect.end());
    long long res = 0;
    for (long long i = 0; i < N - 2 * K; i++) {
      res += vect[i];
    }
    for (long long i = 0; i < K; i++) {
      res += vect[N - 2 * K + i] / vect[N - 2 * K + i + K];
    }
    cout << res << '\n';
  }
  return 0;
}
