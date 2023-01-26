#include <bits/stdc++.h>
using namespace std;
const long long N = 1000009;
const long long INF = 0x3f3f3f3f;
long long dta[N];
long long L[N];
char sing[N];
long long prime[N];
vector<long long> pos[N];
signed main(void) {
  for (long long i = 2; i < N; i++)
    if (prime[i] == 0) {
      prime[i] = i;
      for (long long j = i * i; j < N; j += i) prime[j] = i;
    }
  long long n;
  long long temp;
  cin >> n;
  for (long long i = 1; i <= n; i++) L[i] = INF;
  for (long long i = 1; i <= n; i++) cin >> dta[i];
  cin >> sing + 1;
  for (long long i = 1; i <= n; i++) {
    L[i] = i;
    if (sing[i] == '*') {
      temp = dta[i];
      while (temp > 1) {
        pos[prime[temp]].push_back(i);
        temp /= prime[temp];
      }
    } else {
      temp = dta[i];
      while (temp > 1) {
        if (pos[prime[temp]].empty()) {
          L[i] = -1;
          break;
        }
        L[i] = min(L[i], pos[prime[temp]].back());
        pos[prime[temp]].pop_back();
        temp /= prime[temp];
      }
    }
  }
  long long ans = 0;
  vector<long long> vec;
  for (long long i = 1; i <= n; i++) {
    while (!vec.empty() && vec.back() > L[i]) vec.pop_back();
    if (i == L[i]) vec.push_back(i);
    ans += vec.size();
  }
  cout << ans << endl;
  return 0;
}
