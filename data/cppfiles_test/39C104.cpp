#include <bits/stdc++.h>
using namespace std;
void kout() { cerr << endl; }
template <class T, class... U>
void kout(T a, U... b) {
  cerr << a << ' ', kout(b...);
}
template <class T>
void pary(T L, T R) {
  while (L != R) cerr << *L << " \n"[++L == R];
}
const long long MAXN = 100;
long long N;
long long pos;
long long ans[MAXN + 1];
long long par[MAXN + 1];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N;
  for (long long i = 1; i <= N; i++) {
    cout << '?';
    for (long long j = 1; j <= N; j++) cout << ' ' << 1 + (j == i);
    cout << endl;
    cin >> pos;
    if (pos != i) {
      par[i] = pos;
    }
    cout << '?';
    for (long long j = 1; j <= N; j++) cout << ' ' << 2 - (j == i);
    cout << endl;
    cin >> pos;
    if (pos != i) {
      par[pos] = i;
    }
  }
  long long cur = par[0];
  for (long long i = 1; i <= N; i++) {
    ans[cur] = i;
    cur = par[cur];
  }
  cout << '!';
  for (long long i = 1; i <= N; i++) {
    cout << ' ' << ans[i];
  }
  cout << endl;
}
