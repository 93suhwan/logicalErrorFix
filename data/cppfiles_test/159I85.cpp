#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 1e6 + 5;
long long p[N], n, h[N], sum;
map<long long, long long> us, g;
vector<long long> c[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 2; i < N; i++) {
    if (p[i]) continue;
    for (long long j = i; j < N; j += i) {
      p[j] = 1;
      c[j].push_back(i);
    }
    long long v = rnd();
    while (g[v]) v = rnd();
    p[i] = v;
    g[v] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    long long x = i;
    for (auto j : c[i]) {
      long long num = 0;
      while (x % j == 0) x /= j, num++;
      if (num % 2) h[i] ^= p[j];
    }
    h[i] ^= h[i - 1];
    sum ^= h[i];
  }
  if (sum == 0) {
    cout << n << endl;
    for (long long i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    for (long long i = 1; i <= n; i++) {
      if ((sum ^ h[i]) == 0) {
        cout << n - 1 << endl;
        for (long long j = 1; j <= n; j++) {
          if (j == i) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      long long v = (h[i] ^ sum);
      if (us.count(v)) {
        cout << n - 2 << endl;
        for (long long j = 1; j <= n; j++) {
          if (j == i || j == us[v]) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
      us[h[i]] = i;
    }
    cout << n - 3 << endl;
    for (long long i = 1; i <= n; i++) {
      if (i == 2 || i == n || i == (n - 1) / 2) continue;
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
}
