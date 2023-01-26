#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int T;
signed long long S, N, K;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> T;
  while (T--) {
    cin >> S >> N >> K;
    if (S == K) {
      cout << "YES" << endl;
    } else {
      signed long long a = (S + 1) / (2 * K) * K;
      signed long long b = min((S + 1) % (2 * K), K);
      if (a + b > N)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
}
int main(int argc, char **argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
