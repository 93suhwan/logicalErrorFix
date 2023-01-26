#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long MOD = 1000000007;
const long long INF = 5e18;
inline long long po(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <typename T>
struct BIT {
  vector<T> tree;
  BIT(int n) { tree.resize(n); }
  BIT(vector<T>& v) {
    tree.resize(v.size());
    for (int i = (int)1; i < (int)v.size(); ++i) update(i, v[i]);
  }
  T query(int index) {
    T ans = 0;
    while (index > 0) {
      ans += tree[index];
      index -= index & (-index);
    }
    return ans;
  }
  void update(int index, T val) {
    while (index < tree.size()) {
      tree[index] += val;
      index += index & (-index);
    }
  }
};
void testcases(int test) {
  int n;
  cin >> n;
  vector<int> hold;
  vector<int> a(n);
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> a[i];
    hold.push_back(a[i]);
  }
  sort(hold.begin(), hold.end());
  map<int, int> id;
  int curid = 1;
  id[hold[0]] = curid++;
  for (int i = (int)1; i < (int)hold.size(); ++i)
    if (hold[i] != hold[i - 1]) id[hold[i]] = curid++;
  long long ans = 0;
  BIT<int> b(curid + 1);
  for (int i = (int)0; i < (int)n; ++i) {
    long long tans =
        min(b.query(id[a[i]] - 1), b.query(curid) - b.query(id[a[i]]));
    ans += tans;
    b.update(id[a[i]], 1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  int t;
  cin >> t;
  for (int i = (int)0; i < (int)t; ++i) {
    testcases(i);
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
