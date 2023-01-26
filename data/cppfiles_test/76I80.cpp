#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
int mod = 1e9 + 7;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int n, m;
vector<map<int, int>> g(2e5 + 7);
vector<vector<int>> h(5000, vector<int>(5000));
void F(vector<int>& v, int last = 0) {
  if (v.size() == 5) {
    bool f = false;
    for (int i = 0; i < v.size() - 1; i++) {
      for (int j = i + 1; j < v.size(); j++) {
        f |= h[v[i]][v[j]];
      }
    }
    if (!f) {
      for (auto& u : v) cout << u << " ";
      exit(0);
    }
    for (int i = 0; i < v.size() - 1; i++) {
      for (int j = i + 1; j < v.size(); j++) {
        f &= h[v[i]][v[j]];
      }
    }
    if (f) {
      for (auto& u : v) cout << u << " ";
      exit(0);
    }
  }
  for (int i = last + 1; i < n + 1; i++) {
    v.push_back(i);
    F(v, i);
    v.pop_back();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  if (n >= 5000) {
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[a][b]++;
      g[b][a]++;
    }
    for (int i = 0; i < 1000; i++) {
      set<int> st;
      while (st.size() < 5) {
        st.insert(ran() % n + 1);
      }
      vector<int> v;
      for (auto& u : st) v.push_back(u);
      bool f = false;
      for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          f |= g[v[i]][v[j]];
        }
      }
      if (!f) {
        for (auto& u : v) cout << u << " ";
        return 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    h[a][b]++;
    h[b][a]++;
  }
  if (n < 26) {
    vector<int> v;
    F(v);
    cout << "-1";
    return 0;
  }
  if (n * (n - 1) / 2 > 2 * m) {
    for (int i = 0; i < 1e5; i++) {
      set<int> st;
      while (st.size() < 5) {
        st.insert(ran() % n + 1);
      }
      vector<int> v;
      for (auto& u : st) v.push_back(u);
      bool f = false;
      for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          f |= h[v[i]][v[j]];
        }
      }
      if (!f) {
        for (auto& u : v) cout << u << " ";
        return 0;
      }
    }
    for (int i = 0; i < 1e5; i++) {
      set<int> st;
      while (st.size() < 5) {
        st.insert(ran() % n + 1);
      }
      vector<int> v;
      for (auto& u : st) v.push_back(u);
      bool f = true;
      for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          f &= h[v[i]][v[j]];
        }
      }
      if (f) {
        for (auto& u : v) cout << u << " ";
        return 0;
      }
    }
  } else {
    for (int i = 0; i < 1e5; i++) {
      set<int> st;
      while (st.size() < 5) {
        st.insert(ran() % n + 1);
      }
      vector<int> v;
      for (auto& u : st) v.push_back(u);
      bool f = true;
      for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          f &= h[v[i]][v[j]];
        }
      }
      if (f) {
        for (auto& u : v) cout << u << " ";
        return 0;
      }
    }
    for (int i = 0; i < 1e5; i++) {
      set<int> st;
      while (st.size() < 5) {
        st.insert(ran() % n + 1);
      }
      vector<int> v;
      for (auto& u : st) v.push_back(u);
      bool f = false;
      for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          f |= h[v[i]][v[j]];
        }
      }
      if (!f) {
        for (auto& u : v) cout << u << " ";
        return 0;
      }
    }
  }
  cout << "-1";
}
