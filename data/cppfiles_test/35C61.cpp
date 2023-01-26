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
void foo() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(*max_element(a.begin(), a.end()) + 5);
  string s;
  cin >> s;
  stack<int> st;
  vector<unordered_map<int, int>> st2;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      st.push(i);
      st2.emplace_back();
      continue;
    }
    if (s[i] == '*') {
      st.push(i);
      st2.emplace_back();
    }
    auto divide = [&](int p) {
      while (st.size()) {
        int &v = st2.back()[p];
        if (v == 0) {
          ans += i - st.top();
          if (st2.size() > 1) {
            auto &pm = st2[st2.size() - 2];
            if (st2.back().size() > pm.size()) {
              pm.swap(st2.back());
            }
            for (const auto &[k, val] : st2.back()) {
              pm[k] += val;
            }
          }
          st.pop();
          st2.pop_back();
        } else {
          v--;
          break;
        }
      }
    };
    const vector<int> f = factorize(a[i]);
    if (s[i] == '*') {
      for (int p : f) {
        st2.back()[p]++;
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
