#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int SieveOfEratosthenes(int n) {
  int count = 0;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++) {
    if (prime[p]) count++;
  }
  return (count);
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n], number = 0;
    for (int x = 0; x < n; x++) {
      cin >> ar[x];
    }
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      for (int x = 1; x < n; x++) {
        if (ar[x] > ar[x - 1]) number++;
      }
      if (number != n - 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
