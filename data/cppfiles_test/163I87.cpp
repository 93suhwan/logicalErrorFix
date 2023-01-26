#include <bits/stdc++.h>
using namespace std;
vector<int> pos[1010];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    long long i;
    vector<long long> t;
    for (i = 0; i < N; i++) {
      long long a;
      cin >> a;
      t.push_back(a);
    }
    long long s = 0;
    long long e = 1 << 30;
    while (s != e) {
      vector<long long> plu(N);
      long long m = (s + e + 1) / 2;
      long long j;
      for (j = N - 1; j >= 2; j--) {
        long long di = max(0LL, min(t[j], (t[j] + plu[j] - m)) / 3);
        plu[j] -= di * 3;
        plu[j - 1] += di;
        plu[j - 2] += di * 2;
      }
      for (j = 0; j < N; j++) {
        if (plu[j] + t[j] < m) break;
      }
      if (j == N)
        s = m;
      else
        e = m - 1;
    }
    cout << s << '\n';
  }
}
