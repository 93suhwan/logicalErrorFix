#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int powe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long int mpowe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  t %= 1000000007;
  if (m % 2 == 0) return (t * t) % 1000000007;
  return (((t * t) % 1000000007) * n) % 1000000007;
}
long long int logtwo(long long int n) {
  if (n == 1) return 0;
  return logtwo(n / 2) + 1;
}
long long int binpow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int calculateNcR(long long int n, long long int r) {
  if (n < r) return 0;
  long long int p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long int m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}
long long int stringToInt(string s) {
  long long int num = 0;
  for (long long int i = 0; i < s.length(); i++) {
    num = num * 10 + (s[i] - '0');
  }
  return num;
}
void output(long long int n) { cout << "Case #" << n << ": "; }
struct Node {
  long long int data;
  struct Node* left;
  struct Node* right;
  Node(long long int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};
struct ListNode {
  long long int val;
  struct ListNode* next;
  ListNode(long long int v) {
    val = v;
    next = NULL;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int u, v;
    map<long long int, long long int> make_pair;
    for (long long int i = 0; i < m; i++) {
      cin >> u >> v;
      if (u < v)
        make_pair[u]++;
      else
        make_pair[v]++;
    }
    long long int ans = 0;
    for (long long int i = 1; i <= n; i++) {
      if (make_pair[i] == 0) ans++;
    }
    long long int q;
    cin >> q;
    while (q--) {
      long long int type;
      cin >> type;
      if (type == 1) {
        cin >> u >> v;
        if (u < v) {
          if (make_pair[u] == 0) ans--;
          make_pair[u]++;
        } else {
          if (make_pair[v] == 0) ans--;
          make_pair[v]++;
        }
      } else if (type == 2) {
        cin >> u >> v;
        if (u < v) {
          if (make_pair[u] == 1) ans++;
          make_pair[u]--;
        } else {
          if (make_pair[v] == 1) ans++;
          make_pair[v]--;
        }
      } else {
        cout << ans;
        cout << '\n';
      }
    }
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
