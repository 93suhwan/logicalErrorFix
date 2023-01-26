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
const int prime_max = 1100001;
vector<int> prime;
int NP, divp[prime_max];
signed long long chash[prime_max];
signed long long FS[prime_max];
unordered_map<signed long long, int> rev;
int N;
void cprime() {
  if (NP) return;
  for (int i = 2; i < prime_max; i++)
    if (divp[i] == 0) {
      prime.push_back(i);
      NP++;
      for (signed long long j = i; j >= i && j < prime_max; j += i)
        if (divp[j] == 0) divp[j] = i;
    }
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  cprime();
  srand(time(NULL));
  signed long long th = 0;
  for (i = 2; i <= N; i++) {
    chash[i] = ((1LL * rand()) << 31) + rand();
    FS[i] = FS[i - 1];
    x = i;
    while (x > 1) {
      FS[i] ^= chash[divp[x]];
      x /= divp[x];
    }
    th ^= FS[i];
    rev[FS[i]] = i;
  }
  vector<int> exc;
  if (th == 0) {
    exc = {};
  } else if (rev.count(th)) {
    exc = {rev[th]};
  } else {
    for (i = 2; i <= N; i++) {
      signed long long tmp = th ^ FS[i];
      if (rev.count(tmp) && rev[tmp] != i) {
        exc = {i, rev[tmp]};
        break;
      }
    }
    if (exc.empty()) {
      exc = {2, N, N / 2};
    }
  }
  cout << N - (exc.size()) << endl;
  for (i = 1; i <= N; i++) {
    if (count((exc.begin()), (exc.end()), i) == 0) cout << i << " ";
  }
  cout << endl;
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
