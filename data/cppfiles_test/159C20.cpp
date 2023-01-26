#include <bits/stdc++.h>
using namespace std;
using big = unsigned __int128;
const int mn = 1000000;
vector<vector<int>> primeFactors(mn + 1);
bitset<mn + 1> isPrime;
mt19937_64 r;
big hashed[mn + 1], factHash[mn + 1];
int main() {
  r.seed(time(0));
  isPrime.set();
  int last = 0;
  for (int i = 2; i <= mn; i++) {
    if (isPrime[i]) {
      hashed[i] = ((big)r() << 64) | (big)r();
      for (int j = 2 * i; j <= mn; j += i) {
        if (i != j) isPrime[j] = false;
        int c = 0, x = j;
        while (x % i == 0) {
          c++;
          x /= i;
        }
        if (c & 1) hashed[j] ^= hashed[i];
      }
      last++;
    }
    factHash[i] ^= factHash[i - 1] ^ hashed[i];
  }
  big def = 0;
  map<big, int> vals;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    def ^= factHash[i];
  }
  if (n == 3) {
    cout << 1 << endl << 1 << endl;
    return 0;
  }
  if (def == 0) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      if ((def ^ factHash[i]) == 0) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; j++) {
          if (j == i) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
      vals.emplace(factHash[i], i);
    }
    for (int i = 1; i <= n; i++) {
      if (vals.count(def ^ factHash[i]) && vals[def ^ factHash[i]] != i) {
        cout << n - 2 << endl;
        int x = vals[def ^ factHash[i]];
        for (int j = 1; j <= n; j++) {
          if (j == x || j == i) continue;
          cout << j << " ";
        }
        cout << endl;
        return 0;
      }
    }
    cout << n - 3 << endl;
    for (int i = 1; i < n; i++) {
      if (i == 2 || i == (n - 1) / 2) continue;
      cout << i << " ";
    }
    cout << endl;
  }
}
