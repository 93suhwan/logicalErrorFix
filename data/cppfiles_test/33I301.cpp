#include <bits/stdc++.h>
using namespace std;
void merge2sortedarratswithoutextraspace(int *arr1, int *arr2, int n, int m) {}
void sole() {
  int n, m, count = 0;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long maxi = a[0];
  for (int i = 0; i < n - 1; i++) {
    long long pro = a[i] * a[i + 1];
    cout << pro << endl;
    maxi = max(maxi, pro);
  }
  cout << maxi << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) sole();
  return 0;
}
