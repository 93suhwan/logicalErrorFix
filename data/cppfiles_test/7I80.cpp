#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MX = 200001;
long long A[MX], B[MX];
bool mk[MX];
vector<long long> p;
void init() {
  for (long long i = 2; i < 10000LL; i++)
    if (!mk[i]) {
      p.push_back(i);
      for (long long j = i * i; j < 10000LL; j += i) mk[j] = true;
    }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  int sol = 1;
  B[0] = long long((1LL << 62LL));
  for (int tj = 0; tj <= 500; tj++) {
    long long j = p[tj];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      B[i] = A[i] % j;
      if (B[i] != B[i - 1]) {
        cnt = 1;
      } else
        cnt++;
      sol = max(sol, cnt);
    }
  }
  cout << sol << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
