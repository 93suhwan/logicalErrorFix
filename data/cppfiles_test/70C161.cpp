#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
void dfs(vector<long long int> adj[], long long int v, long long int used[]) {
  used[v] = 1;
  cout << v << " ";
  for (long long int u : adj[v]) {
    if (used[u] == 0) dfs(adj, u, used);
  }
  used[v] = 2;
}
long long int pal(string str) {
  string temp = str;
  reverse(temp.begin(), temp.end());
  if (temp == str) return 1;
  return -1;
}
long long int maxSubArraySum(long long int a[], long long int l,
                             long long int r) {
  long long int max_so_far = a[l];
  long long int curr_max = a[l];
  for (long long int i = l + 1; i < r - l + 1; i++) {
    curr_max = max(a[i], curr_max + a[i]);
    max_so_far = max(max_so_far, curr_max);
  }
  return max_so_far;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}
long long int lcm(long long int a, long long int b) {
  long long int x = gcd(a, b);
  long long int ans = (a * b) / x;
  return ans;
}
long long int ncr(long long int n, long long int r) {
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
long long int modpow(long long int x, long long int y,
                     long long int p = 1000000007) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modadd(long long int a, long long int b,
                     long long int m = 1000000007) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
long long int modmul(long long int a, long long int b,
                     long long int m = 1000000007) {
  return ((a % m) * (b % m)) % m;
}
long long int modi(long long int a, long long int m = 1000000007) {
  return modpow(a, m - 2, m);
}
vector<long long int> g1[100007];
vector<long long int> g2[100007];
long long int com1[100007];
long long int com2[100007];
vector<long long int> conn1[100007];
vector<long long int> conn2[100007];
long long int binarysearchff(
    vector<pair<pair<long long int, long long int>, long long int>> arr,
    long long int l, long long int r, long long int key) {
  long long int ans = -1;
  if (arr[r].first.first <= key) return (r + 1);
  if (arr[l].first.first > key) return l;
  while (l <= r) {
    long long int m = l + (r - l + 1) / 2;
    if (arr[m].first.first <= key)
      l = m + 1;
    else if (arr[m].first.first > key) {
      ans = m;
      r = m - 1;
    }
  }
  return ans;
}
long long int binarysearchss(
    vector<pair<pair<long long int, long long int>, long long int>> arr,
    long long int l, long long int r, long long int key) {
  long long int ans = -1;
  if (arr[r].first.second <= key) return (r + 1);
  if (arr[l].first.second > key) return l;
  while (l <= r) {
    long long int m = l + (r - l + 1) / 2;
    if (arr[m].first.second <= key)
      l = m + 1;
    else if (arr[m].first.second > key) {
      ans = m;
      r = m - 1;
    }
  }
  return ans;
}
void dfs(long long int u, long long int t) {
  if (t == 1) {
    for (auto v : g1[u]) {
      if (com1[v]) continue;
      com1[v] = com1[u];
      conn1[com1[v]].push_back(v);
      dfs(v, t);
    }
  } else {
    for (auto v : g2[u]) {
      if (com2[v]) continue;
      com2[v] = com2[u];
      conn2[com2[v]].push_back(v);
      dfs(v, t);
    }
  }
}
void join(long long int u, long long int v, long long int t, long long int n) {
  long long int init = 0;
  long long int fin = 0;
  if (t == 1) {
    init = com1[v];
    fin = com1[u];
  } else {
    init = com2[v];
    fin = com2[u];
  }
  if (t == 1) {
    for (auto i : conn1[init]) {
      com1[i] = fin;
      conn1[fin].push_back(i);
    }
    conn1[init].clear();
  } else {
    for (auto i : conn2[init]) {
      com2[i] = fin;
      conn2[fin].push_back(i);
    }
    conn2[init].clear();
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    string t;
    cin >> t;
    map<char, long long int> mc;
    map<char, long long int> ms;
    long long int n = t.size();
    reverse(t.begin(), t.end());
    string x = "\0";
    for (long long int i = 0; i < n; i++) {
      mc[t[i]]++;
      if (mc[t[i]] == 1) x.push_back(t[i]);
    }
    reverse(t.begin(), t.end());
    reverse(x.begin(), x.end());
    long long int v = 1;
    for (long long int i = 0; i < x.size(); i++) {
      ms[x[i]] = mc[x[i]] / (i + 1);
      if (mc[x[i]] % (i + 1) != 0) {
        v = 0;
        break;
      }
    }
    if (!v) {
      cout << "-1\n";
      continue;
    }
    long long int sum = 0;
    for (auto it = ms.begin(); it != ms.end(); it++) {
      sum += it->second;
    }
    string s = t.substr(0, sum);
    string y = "\0";
    map<char, long long int> mcheck;
    long long int cur = 0;
    while (cur < x.size()) {
      for (long long int i = 0; i < s.size(); i++) {
        if (mcheck[s[i]] != 1) y.push_back(s[i]);
      }
      mcheck[x[cur]] = 1;
      cur++;
    }
    if (y == t) {
      cout << s << " " << x << endl;
      continue;
    }
    cout << "-1\n";
  }
  return 0;
}
