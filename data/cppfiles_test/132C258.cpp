#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
class Items {
 public:
  long long first;
  long long second;
  long long weight;
  Items(long long a, long long b, long long value) : weight(value) {
    first = a;
    second = b;
  }
  friend bool operator<(const Items &i1, const Items &i2) {
    return i1.weight > i2.weight;
  }
};
class FenwickTree {
 private:
  vector<long long> bit;
  long long n;

 public:
  FenwickTree(long long n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<long long> &a) : FenwickTree(a.size()) {
    for (long long i = 0; i < a.size(); i++) {
      add(i, a[i]);
    }
  }
  long long sum(long long r) {
    long long res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      res += bit[r];
    }
    return res;
  }
  void add(long long idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
      bit[idx] += delta;
    }
  }
  friend vector<long long> tree(const FenwickTree &f1) { return f1.bit; }
};
class Segtree {
 public:
  vector<long long> tree;
  long long n;
  Segtree(long long n) {
    this->n = n;
    tree.assign(2 * n, 0);
  }
  Segtree(vector<long long> &a) : Segtree(a.size()) {
    for (long long i = 0; i < a.size(); i++) {
      add(i, a[i]);
    }
  }
  void add(long long k, long long delta) {
    k += n;
    tree[k] += delta;
    for (k /= 2; k >= 1; k /= 2) {
      tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
  }
  long long sum(long long a, long long b) {
    a += n;
    b += n;
    long long res = 0;
    while (a <= b) {
      if (a % 2 == 1) {
        res += tree[a++];
      }
      if (b % 2 == 0) {
        res += tree[b--];
      }
      b /= 2;
      a /= 2;
    }
    return res;
  }
};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return (gcd(b, a % b));
}
class Trienode {
 public:
  Trienode *arr[26];
  bool iscomplete;
  Trienode() {
    for (long long i = 0; i < 26; i++) {
      arr[i] = nullptr;
    }
    iscomplete = false;
  }
  void add(string str) {
    Trienode *temp = this;
    for (long long i = 0; i < str.length(); i++) {
      long long k = str[i] - 'a';
      if (temp->arr[k] == nullptr) {
        Trienode *n = new Trienode();
        temp->arr[k] = n;
      }
      temp = temp->arr[k];
    }
    temp->iscomplete = true;
  }
  bool search(string str) {
    Trienode *temp = this;
    for (long long i = 0; i < str.length(); i++) {
      long long idx = str[i] - 'a';
      if (temp->arr[idx] == nullptr) return false;
      temp = temp->arr[idx];
    }
    return (temp != nullptr && temp->iscomplete);
  }
};
vector<long long> calcPrimes() {
  vector<long long> vt;
  vector<bool> primes(1e5 + 1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for (long long i = 2; i <= 1e5; i++) {
    if (primes[i] == 1) {
      vt.push_back(i);
      for (long long j = i * i; j <= 1e5; j += i) {
        primes[j] = 0;
      }
    }
  }
  return vt;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + 7);
    if (arr[0] + arr[1] + arr[2] == arr[6])
      cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    else if (arr[0] + arr[2] + arr[3] == arr[6])
      cout << arr[0] << " " << arr[2] << " " << arr[3] << endl;
    else if (arr[0] + arr[1] + arr[3] == arr[6])
      cout << arr[0] << " " << arr[1] << " " << arr[3] << endl;
    else
      cout << arr[1] << " " << arr[2] << " " << arr[3] << endl;
  }
}
