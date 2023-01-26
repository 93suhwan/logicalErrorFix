#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
set<long long> s1;
set<long long> s2;
long long p[20];
void gen() {
  p[0] = 1;
  for (long long i = 1; i <= 15; i++) p[i] = p[i - 1] * 10;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k == 1)
    cout << *s1.lower_bound(n) << "\n";
  else
    cout << *s2.lower_bound(n) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  gen();
  for (long long i = 1; i <= 9; i++) {
    long long liczba = 0;
    for (long long j = 1; j <= 10; j++) {
      liczba *= 10;
      liczba += i;
      s1.insert(liczba);
    }
  }
  for (long long i = 0; i <= 9; i++)
    for (long long j = i + 1; j <= 9; j++)
      for (long long l = 0; l <= 10; l++)
        for (long long mask = 0; mask <= (1 << l) - 1; mask++) {
          long long liczba = 0;
          for (long long m = 0; m <= l - 1; m++) {
            if (mask & (1 << m))
              liczba += p[m] * i;
            else
              liczba += p[m] * j;
          }
          s2.insert(liczba);
        }
  int t;
  cin >> t;
  while (t--) solve();
}
