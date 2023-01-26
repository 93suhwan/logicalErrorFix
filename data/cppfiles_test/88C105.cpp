#include <bits/stdc++.h>
using namespace std;
template <typename A1>
void prn(A1&& arg) {
  cout << arg << '\n';
}
template <typename A1, typename... A>
void prn(A1&& arg, A&&... args) {
  cout << arg << ' ';
  prn(args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long l = n * m;
    vector<array<long long, 2>> v(l);
    for (long long i = 0; i < l; i++) {
      cin >> v[i][0];
      v[i][1] = i + 1;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = 0; i < l; i++) v[i][1] = -v[i][1];
    for (long long i = 0; i < n; i++) {
      multiset<array<long long, 2>> ms;
      long long tmp = 0;
      sort(v.begin() + (i * m), v.begin() + (i * m + m));
      for (long long j = i * m; j < (i * m + m); j++) v[j][1] = -v[j][1];
      for (long long j = 0; j < m; j++) {
        tmp = 0;
        for (auto p : ms) {
          if (p[1] >= v[i * m + j][0])
            break;
          else {
            if (p[0] < v[i * m + j][1])
              tmp++;
            else
              break;
          }
        }
        ans += tmp;
        ms.insert({v[i * m + j][1], v[i * m + j][0]});
      }
    }
    prn(ans);
  }
}
