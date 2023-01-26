#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000005;
const long long INFLL = 500000000000000002ll;
const long long MOD = 1000000007;
inline long long min(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
inline long long min(long long a, long long b, long long c, long long d) {
  return min(min(min(a, b), c), d);
}
inline long long max(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
inline long long max(long long a, long long b, long long c, long long d) {
  return max(max(max(a, b), c), d);
}
int Last[2], N, T;
string S;
vector<int> V;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tt = (1); tt <= (T); tt++) {
    cin >> S;
    sort(S.begin(), S.end());
    int ans = 0, col = 0;
    for (int i = (0); i <= (1); i++) Last[i] = '!';
    for (int i = (0); i <= (((int)S.size()) - 1); i++) {
      if (Last[col] != S[i]) {
        Last[col] = S[i];
        col ^= 1;
        if (col == 0) ans++;
      }
    }
    cout << ans << "\n";
  }
}
