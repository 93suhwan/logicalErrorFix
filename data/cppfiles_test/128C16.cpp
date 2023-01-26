#include <bits/stdc++.h>
using namespace std;
void input(vector<long long int> &arr) {
  for (int i = 0; i < arr.size(); i++) cin >> arr[i];
}
void output(vector<long long int> &arr) {
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << "\n";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int smallans = power(a, b / 2);
  long long int myans = (smallans * smallans) % 1000000007;
  if ((b & 1)) myans = (myans * a) % 1000000007;
  return myans;
}
long long int multiply(long long int a, long long int b) {
  long long int ans = ((a % 1000000007) * (b % 1000000007)) % 1000000007;
  return ans;
}
long long int divide(long long int a, long long int b) {
  return multiply(a, power(b, 1000000007 - 2));
}
void manageLazy(vector<long long int> &tree, vector<long long int> &lazy,
                long long int idx) {
  tree[2 * idx + 1] += lazy[idx];
  lazy[2 * idx + 1] += lazy[idx];
  tree[2 * idx + 2] += lazy[idx];
  lazy[2 * idx + 2] += lazy[idx];
  lazy[idx] = 0;
}
void build(vector<long long int> &tree, vector<long long int> &arr,
           long long int left, long long int right, long long int idx) {
  if (left == right) {
    tree[idx] = arr[left];
    return;
  }
  long long int mid = (left + right) / 2;
  build(tree, arr, left, mid, 2 * idx + 1);
  build(tree, arr, mid + 1, right, 2 * idx + 2);
  tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}
void update(vector<long long int> &tree, vector<long long int> &lazy,
            long long int tl, long long int tr, long long int l,
            long long int r, long long int idx, long long int val) {
  if (l > r) return;
  if (l == tl && tr == r) {
    tree[idx] += val;
    lazy[idx] += val;
    return;
  }
  manageLazy(tree, lazy, idx);
  long long int mid = (tl + tr) / 2;
  update(tree, lazy, tl, mid, l, min(r, mid), 2 * idx + 1, val);
  update(tree, lazy, mid + 1, tr, max(l, mid + 1), r, 2 * idx + 2, val);
  tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}
long long int query(vector<long long int> &tree, vector<long long int> &lazy,
                    long long int tl, long long int tr, long long int l,
                    long long int r, long long int idx) {
  if (l > r) return 1e18;
  if (l <= tl && tr <= r) return tree[idx];
  manageLazy(tree, lazy, idx);
  long long int mid = (tl + tr) / 2;
  long long int a = query(tree, lazy, tl, mid, l, min(r, mid), 2 * idx + 1);
  long long int b =
      query(tree, lazy, mid + 1, tr, max(l, mid + 1), r, 2 * idx + 2);
  return min(a, b);
}
void update(vector<long long int> &tree, long long int index,
            long long int val) {
  index++;
  while (index < tree.size()) {
    tree[index] = (tree[index] + val) % 1000000007;
    index += index & (-index);
  }
}
long long int calculate(vector<long long int> &tree, long long int index) {
  long long int sum = 0;
  index++;
  while (index > 0) {
    sum = (sum + tree[index]) % 1000000007;
    index -= index & (-index);
  }
  return sum;
}
long long int findpar(long long int p, vector<long long int> &parent) {
  if (parent[p] == p) return p;
  parent[p] = findpar(parent[p], parent);
  return parent[p];
}
void merge(long long int a, long long int b, vector<long long int> &parent,
           vector<long long int> &size_) {
  a = findpar(a, parent);
  b = findpar(b, parent);
  if (a != b) {
    if (size_[a] < size_[b]) swap(a, b);
    parent[b] = a;
    size_[a] += size_[b];
  }
}
void sieve(vector<bool> &primes, vector<long long int> &count) {
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      count.push_back(i);
      for (int j = i * i; j < primes.size(); j += i) primes[j] = false;
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  long long int a, b, c;
  c = 1;
  long long int t = n - 1;
  if (t % 2) {
    cout << 2 << " " << t - 2 << " " << 1 << "\n";
    return;
  }
  if ((t / 2) % 2 == 0)
    cout << t / 2 + 1 << " " << t / 2 - 1 << " " << 1 << "\n";
  else
    cout << t / 2 + 2 << " " << t / 2 - 2 << " " << 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
