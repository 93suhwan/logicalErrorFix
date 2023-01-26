#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T, z;
  cin >> T;
  for (z = 0; z < T; z++) {
    long long int N, i, j, num, L, R;
    cin >> N;
    vector<long long int> Hash((N + 1), 0);
    vector<pair<long long int, long long int>> Ran(N + 1);
    map<pair<long long int, long long int>, long long int> mp;
    for (i = 0; i < N; i++) {
      cin >> L >> R;
      Ran[i] = {L, R};
      mp[{Ran[i]}] = -1;
      if (L == R) {
        mp[{Ran[i]}] = L;
        Hash[L] = 1;
      }
    }
    sort(Ran.begin(), Ran.end() - 1);
    for (j = 0; j < N; j++) {
      if (mp[{Ran[j]}] == -1) {
        for (i = 1; i <= N; i++) {
          if (Hash[i] != 1) {
            if (mp[{i + 1, Ran[j].second}] != 0) {
              Hash[i] = 1;
              mp[{Ran[j]}] = i;
              break;
            } else if (mp[{Ran[j].first, i - 1}] != 0) {
              Hash[i] = 1;
              mp[{Ran[j]}] = i;
              break;
            }
          }
        }
      }
    }
    for (i = 0; i < N; i++) {
      cout << Ran[i].first << " " << Ran[i].second << " " << mp[{Ran[i]}]
           << "\n";
    }
    cout << "\n";
  }
  return 0;
}
