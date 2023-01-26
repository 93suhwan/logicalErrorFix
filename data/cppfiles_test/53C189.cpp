#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long N, K;
    cin >> N >> K;
    vector<pair<long long, long long> > A(N);
    for (long long i = 0; i < N; i++) {
      cin >> A[i].first;
      A[i].second = i;
    }
    sort(A.begin(), A.end());
    K--;
    for (long long i = 0; i < N - 1; i++)
      if (A[i].second + 1 != A[i + 1].second) K--;
    if (K < 0)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}
