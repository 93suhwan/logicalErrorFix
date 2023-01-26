#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void build(int n) {
  prime = vector<int>(n + 1);
  iota(prime.begin(), prime.end(), 0);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (prime[j] == j) {
          prime[j] = i;
        }
      }
    }
  }
}
vector<int> factorize(int n) {
  assert((int)prime.size() - 1 >= n);
  vector<int> prime_div;
  while (n > 1) {
    int curr = prime[n];
    while (prime[n] == curr) {
      prime_div.push_back(curr);
      n /= curr;
    }
  }
  return prime_div;
}
struct my_map {
  vector<int> m;
  vector<int> in;
  my_map(int size) { m.assign(size, 0); }
  int operator[](int k) { return m[k]; }
  void clear() {
    for (int x : in) {
      m[x] = 0;
    }
    in.clear();
  }
  void update(int key, int add) {
    in.push_back(key);
    m[key] += add;
  }
};
void foo() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int M = *max_element(a.begin(), a.end()) + 5;
  build(M);
  string s;
  cin >> s;
  stack<int> st;
  my_map changes(M);
  vector<vector<pair<int, int>>> st2;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    st.push(i);
    vector<pair<int, int>> archive;
    for (int x : changes.in) {
      archive.emplace_back(x, changes[x]);
    }
    changes.clear();
    st2.push_back(archive);
    auto divide = [&](int p) {
      while (st.size()) {
        if (changes[p] == 0) {
          ans += i - st.top();
          for (const auto &[k, val] : st2.back()) {
            changes.update(k, val);
          }
          st2.pop_back();
          st.pop();
        } else {
          changes.update(p, -1);
          break;
        }
      }
    };
    const vector<int> f = factorize(a[i]);
    if (s[i] == '*') {
      for (int p : f) {
        changes.update(p, 1);
      }
    } else {
      for (int p : f) {
        divide(p);
      }
    }
  }
  while (st.size()) {
    ans += n - st.top();
    st.pop();
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
