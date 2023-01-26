#include <bits/stdc++.h>
using namespace std;
void printv(vector<long long>& v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}
long long GCD(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return GCD(a - b, b);
  return GCD(a, b - a);
}
long long GCDV(vector<long long>& arr, int idx) {
  if (idx == arr.size() - 1) {
    return arr[idx];
  }
  int a = arr[idx];
  int b = GCDV(arr, idx + 1);
  return GCD(a, b);
}
long long dig(long long n) {
  long long x = 0;
  while (n) {
    n = n / 10;
    x++;
  }
  return x;
}
long long fact(long long n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
long long nCrModpDP(long long n, long long r, long long p) {
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long nCr(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long ni = n % p, ri = r % p;
  return (nCr(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 != 0) {
      cout << "NO" << endl;
      continue;
    }
    int i = 0, j = s.size() / 2;
    if (s.substr(0, j) == s.substr(j, j)) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
