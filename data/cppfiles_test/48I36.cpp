#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int query(int BITree[], int index) {
  int sum = 0;
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}
void update(int BITree[], int n, int index, int val) {
  while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
  }
}
int inversion_count(int arr[], int n) {
  int ans = 0;
  int BIT[200005] = {0};
  for (int i = n - 1; i >= 0; i--) {
    ans += query(BIT, arr[i] - 1);
    update(BIT, 200005, arr[i], 1);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int v[n];
    for (long long i = 0; i < n; i++) cin >> v[i];
    bool ans = false;
    int inv = inversion_count(v, n);
    if (inv % 2 == 0)
      ans = true;
    else {
      sort(v, v + n);
      for (long long i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1]) ans = true;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}
