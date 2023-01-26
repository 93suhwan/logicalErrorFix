#include <bits/stdc++.h>
using namespace std;
int n;
const long long MAX = 2e5 + 5;
long long fw[MAX + 20][3];
long long sum(int k, int z) {
  long long s = 0;
  while (k >= 1) {
    s += fw[k][z];
    k -= k & -k;
  }
  return s;
}
void add(int k, long long x, int z) {
  while (k <= MAX) {
    fw[k][z] += x;
    k += k & -k;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<long long> v(n + 1);
  vector<long long> sol(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (long long i = 1; i <= n; i++) {
    long long a = v[i];
    sol[i] = sol[i - 1];
    sol[i] += sum(a, 0);
    sol[i] += a * (i - 1);
    for (long long j = 1; j <= MAX / a + 1; j++) {
      long long b = sum(min(MAX, a * j + a - 1), 0) - sum(a * j - 1, 0);
      long long c = sum(min(MAX, a * j + a - 1), 1) - sum(a * j - 1, 1);
      sol[i] += b - a * j * c;
    }
    sol[i] -= sum(a, 2);
    add(a, a, 0);
    add(a, 1, 1);
    for (int j = a; j <= MAX; j += a) add(j, a, 2);
  }
  for (int i = 1; i <= n; i++) cout << sol[i] << " ";
  cout << "\n";
  return 0;
}
