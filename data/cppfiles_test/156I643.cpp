#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    long long sum = accumulate(A.begin(), A.end(), 0);
    long long ans = LLONG_MAX;
    long long hand = 0;
    for (int pick = 0; pick < N; ++pick) {
      long long take = (sum - K - hand + pick) / (pick + 1);
      ans = min(ans, take + pick);
      hand += A[pick] - A[N - 1];
    }
    cout << max(ans, 0LL) << '\n';
  }
}
