#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long MAXN = 2e5 + 100;
long long A[MAXN];
long long f(long long x) { return (x % MOD + MOD) % MOD; }
struct st {
  vector<pair<long long, long long>> vect;
  long long cant = 0;
  long long acum = 0;
  long long sum = 0;
  void insert(long long x, long long c) {
    vect.push_back({f(x - acum), c});
    cant = cant + c;
    sum = f(sum + x * c);
  }
  void add(long long x) {
    acum = f(acum + x);
    sum = f(sum + x * cant);
  }
  void erase(long long c) {
    while (c) {
      if (vect.back().second <= c) {
        c -= vect.back().second;
        sum = f(sum - (vect.back().first + acum) * vect.back().second % MOD);
        cant = cant - vect.back().second;
        vect.pop_back();
      } else {
        sum = f(sum - (vect.back().first + acum) * c % MOD);
        cant = cant - c;
        long long xxx = f(vect.back().first + acum);
        long long yyy = vect.back().second - c;
        vect.pop_back();
        vect.push_back({xxx, yyy});
        c = 0;
        break;
      }
    }
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N;
  cin >> N;
  st pp1, pp2;
  for (long long i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (long long i = 1; i <= N; i++) {
    if (i == 1) {
      pp1.insert(1, A[i]);
      pp2.insert(f(-1), A[i]);
      continue;
    }
    long long tam = pp1.cant;
    if (tam > A[i]) {
      pp1.erase(tam - A[i]);
      pp2.erase(tam - A[i]);
    }
    long long tot = 0;
    if ((i + 1) & 1)
      tot = pp1.sum;
    else
      tot = pp2.sum;
    if (i & 1) {
      pp1.add(tot);
      pp2.add(f(-tot));
    } else {
      pp1.add(f(-tot));
      pp2.add(tot);
    }
    tam = pp1.cant;
    if (tam < A[i]) {
      if (i & 1) {
        pp1.insert(tot, A[i] - tam);
        pp2.insert(f(-tot), A[i] - tam);
      } else {
        pp1.insert(f(-tot), A[i] - tam);
        pp2.insert(tot, A[i] - tam);
      }
    }
  }
  if (N & 1) {
    cout << pp1.sum << '\n';
  } else {
    cout << pp2.sum << '\n';
  }
  return 0;
}
