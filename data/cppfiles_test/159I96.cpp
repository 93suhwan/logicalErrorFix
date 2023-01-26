#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool mnto(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool mxto(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
int n;
int lp[1000005], hsh[1000005];
vector<int> primes;
map<int, int> mp;
int main() {
  mt19937 rnd(234901);
  scanf("%d", &n);
  for (int i = 2; i < n + 1; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      hsh[i] = rnd();
      primes.push_back(i);
    };
    for (int j = 0; j < primes.size() && primes[j] <= lp[i] &&
                    (long long)primes[j] * i <= n;
         j++) {
      int x = primes[j] * i;
      lp[x] = primes[j];
      hsh[x] = hsh[primes[j]] ^ hsh[i];
      ;
    }
  }
  int tot = 0;
  for (int i = 2; i < n + 1; i++) {
    hsh[i] ^= hsh[i - 1];
    tot ^= hsh[i];
    mp[hsh[i]] = i;
    ;
  };
  if (tot == 0) {
    printf("%d\n", n);
    for (int i = 1; i < n + 1; i++) {
      printf("%d ", i);
    }
    printf("\n");
    return 0;
  }
  for (int i = 1; i < n + 1; i++) {
    if ((tot ^ hsh[i]) == 0) {
      printf("%d\n", n - 1);
      for (int j = 1; j < n + 1; j++) {
        if (j == i) continue;
        printf("%d ", j);
      }
      printf("\n");
      return 0;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    if (mp[tot ^ hsh[i]]) {
      assert(tot ^ hsh[i] ^ hsh[mp[tot ^ hsh[i]]] == 0);
      printf("%d\n", n - 2);
      for (int j = 1; j < n + 1; j++) {
        if (j == i || j == mp[tot ^ hsh[i]]) continue;
        printf("%d ", j);
      }
      printf("\n");
      return 0;
    }
  }
  printf("%d\n", n - 3);
  for (int i = 1; i < n + 1; i++) {
    if (i == 2 || i == (n - 1) / 2 || i == n) continue;
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}
