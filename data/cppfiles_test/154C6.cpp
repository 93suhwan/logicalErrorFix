#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
void ps() { cout << "\n"; }
template <typename First, typename... Rest>
void ps(First&& first, Rest&&... rest) {
  cout << forward<First>(first) << " ";
  ps(forward<Rest>(rest)...);
}
const int N = (1 << 21) + 2;
long long a[N];
long long fac[N];
vector<long long> g[N];
long long mod = 1e9 + 7;
class BITTree {
 public:
  std::vector<long long> data;
  int size;
  BITTree(int size) {
    this->size = size + 1;
    this->data = std::vector<long long>(size + 1);
  }
  BITTree(std::vector<long long> arr) {
    this->size = arr.size() + 1;
    this->data = std::vector<long long>(size + 1);
    for (int i = 0; i < arr.size(); i++) this->update(i + 1, arr[i]);
  }
  void update(int index, long long value) {
    while (index <= size) {
      data[index] += value;
      index += (index & (-index));
    }
  }
  long long rangeSum(int l, int r) {
    long long res = 0;
    l--;
    while (l > 0) {
      res -= data[l];
      l -= (l & (-l));
    }
    while (r > 0) {
      res += data[r];
      r -= (r & (-r));
    }
    return res;
  }
};
struct seg_tree {
  int n;
  int def = 0;
  int tree[(1 << 21) + 1];
  int lazy[(1 << 21) + 1];
  seg_tree(int size) { n = size; }
  inline int combine(int a, int b) { return max(a, b); }
  inline void push(int pos) {
    if (lazy[pos] != def) {
      tree[(pos << 1LL)] = lazy[pos];
      tree[(pos << 1LL) + 1] = lazy[pos];
      lazy[(pos << 1LL)] = lazy[pos];
      lazy[(pos << 1LL) + 1] = lazy[pos];
      lazy[pos] = def;
    }
  }
  inline void update(int l, int r, int val, int left = 0, int right = INT_MIN,
                     int pos = 1) {
    if (right == INT_MIN) right = n - 1;
    if (l > r) return;
    if (l == left && r == right) {
      tree[pos] = val;
      lazy[pos] = val;
    } else {
      push(pos);
      int mid = (left + right) >> 1;
      update(l, min(mid, r), val, left, mid, pos << 1);
      update(max(l, mid + 1), r, val, mid + 1, right, (pos << 1) + 1);
      tree[pos] = combine(tree[pos << 1], tree[(pos << 1) + 1]);
    }
  }
  inline int read(int l, int r, int left = 0, int right = INT_MIN,
                  int pos = 1) {
    if (right == INT_MIN) right = n - 1;
    if (l > r) return def;
    if (left == l && right == r)
      return tree[pos];
    else {
      push(pos);
      int mid = (left + right) >> 1;
      return combine(read(l, min(r, mid), left, mid, pos << 1),
                     read(max(l, mid + 1), r, mid + 1, right, (pos << 1) + 1));
    }
  }
};
void max_heapify_array(long long* arr, int index, int size) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int largest = index;
  if (left < size && arr[left] > arr[largest]) largest = left;
  if (right < size && arr[right] > arr[largest]) largest = right;
  if (largest != index) {
    swap(arr[index], arr[largest]);
    max_heapify_array(arr, largest, size);
  }
}
void heap_array(long long* arr, int size) {
  for (int i = size / 2; i >= 0; i--) max_heapify_array(arr, i, size);
}
long long heap_extract_max_array(long long* arr, int size) {
  size--;
  long long val = arr[0];
  swap(arr[0], arr[size]);
  size--;
  max_heapify_array(arr, 0, size);
  return val;
}
void heap_insert_array(long long* arr, long long val, int size) {
  arr[size] = val;
  while (size > 0 && arr[(size + 1) / 2 - 1] < arr[size]) {
    swap(arr[(size + 1) / 2 - 1], arr[size]);
    size = (size + 1) / 2 - 1;
  }
}
long long fact(long long n, long long mod) {
  if (n <= 1) return 1;
  long long res = 1;
  for (int i = 2; i <= n; i++) res = (i * res) % mod;
  return res;
}
long long power(long long base, long long pow, long long mod) {
  long long res = 1;
  base %= mod;
  while (pow > 0) {
    if ((pow & 1) == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    pow >>= 1;
  }
  return res;
}
long long mod_inv(long long x, long long mod) { return power(x, mod - 2, mod); }
long long nCr(long long n, long long r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  int i;
  if (fac[0] != 1) {
    fac[0] = 1;
    for (i = 1; 1 < N ? i < N : i > N; 1 < N ? i += 1 : i -= 1) {
      fac[i] = (fac[i - 1] * i) % mod;
    }
  }
  return (fac[n] * mod_inv(fac[r], p) % p * mod_inv(fac[n - r], p) % p) % p;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
void solve() {
  long long i, j, n, m;
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] == a[1] && a[2] % 2 == 0)
    ps("YES");
  else if (a[1] == a[2] && a[0] % 2 == 0)
    ps("YES");
  else if (a[2] == a[0] + a[1])
    ps("YES");
  else
    ps("NO");
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
