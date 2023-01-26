#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 2e5;
int fw[MAX * 3][3];
int sum(int k, int z) {
  int s = 0;
  while (k >= 1) {
    s += fw[k][z];
    k -= k & -k;
  }
  return s;
}
void add(int k, int x, int z) {
  while (k <= MAX) {
    fw[k][z] += x;
    k += k & -k;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<int> v(n + 1), sol(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) {
    int a = v[i];
    sol[i] = sol[i - 1];
    sol[i] += sum(a, 0);
    sol[i] += a * (i - 1);
    for (int j = 1; j <= MAX / a + 1; j++) {
      int b = sum(a * j + a - 1, 0) - sum(a * j - 1, 0);
      int c = sum(a * j + a - 1, 1) - sum(a * j - 1, 1);
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
