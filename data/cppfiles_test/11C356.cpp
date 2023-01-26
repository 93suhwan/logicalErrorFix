#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int Tst;
  cin >> Tst;
  while (Tst--) {
    long long int N;
    cin >> N;
    vector<string> S(N);
    for (long long int i = 0; i < N; ++i) cin >> S[i];
    long long int ans = 0;
    for (long long int i = 0; i < 5; ++i) {
      vector<long long int> score(N);
      for (long long int j = 0; j < N; ++j) {
        long long int sc = 0;
        for (char c : S[j]) {
          if (c - 'a' == i)
            sc++;
          else
            sc--;
        }
        score[j] = sc;
      }
      sort(score.rbegin(), score.rend());
      long long int tot = 0, ta = 0;
      for (long long int j = 0; j < N; ++j) {
        if (tot + score[j] <= 0) break;
        ta++;
        tot += score[j];
      }
      ans = max(ans, ta);
    }
    cout << ans << '\n';
  }
}
