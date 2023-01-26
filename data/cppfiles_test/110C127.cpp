#include <bits/stdc++.h>
bool time_seed = 0;
using namespace std;
using namespace std::chrono;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void show_vi(vector<int> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << ",";
  }
  cout << endl;
}
void show_vp(vector<pair<int, int>> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i].first << " " << t[i].second << "::";
  }
  cout << endl;
}
void show_vd(vector<double> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << ",";
  }
  cout << endl;
}
void show_vll(vector<long long int> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << ",";
  }
  cout << endl;
}
void show_vt(vector<tuple<long long, long long>> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << get<0>(t[i]) << " " << get<1>(t[i]) << "::";
  }
  cout << endl;
}
void show_vb(vector<bool> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << " ";
  }
  cout << endl;
}
void show_vvi(vector<vector<int>> ans) {
  cout << "---------------------------" << endl;
  for (int i = 0; i < ans.size(); i++) {
    show_vi(ans[i]);
  }
  cout << endl;
}
int randd() {
  timeval start_time;
  long milli_time, seconds, useconds;
  gettimeofday(&start_time, NULL);
  seconds = start_time.tv_sec;
  useconds = start_time.tv_usec;
  milli_time = ((seconds)*1000 + useconds / 1000.0);
  if (time_seed == 0) {
    time_seed = 1;
    srand(milli_time);
  }
  int k = rand();
  return k;
}
void show_vvvi(vector<vector<vector<int>>> ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << "******************" << endl;
    show_vvi(ans[i]);
  }
  cout << endl;
}
void show_vvb(vector<vector<bool>> ans) {
  cout << "---------------------------" << endl;
  for (int i = 0; i < ans.size(); i++) {
    show_vb(ans[i]);
  }
  cout << endl;
}
void show_vs(vector<string> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << "::";
  }
  cout << endl;
}
void show_vc(vector<char> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i];
  }
  cout << endl;
}
void show_vvc(vector<vector<char>> A) {
  cout << "---------------------------" << endl;
  for (int i = 0; i < A.size(); i++) {
    show_vc(A[i]);
  }
}
void show_vvs(vector<vector<string>> A) {
  for (int i = 0; i < A.size(); i++) {
    show_vs(A[i]);
  }
}
void show_vvvs(vector<vector<vector<string>>> ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << "******************" << endl;
    show_vvs(ans[i]);
  }
  cout << endl;
}
void show_um(unordered_map<int, int> &map) {
  unordered_map<int, int>::iterator it;
  it = map.begin();
  while (it != map.end()) {
    cout << it->first << " " << it->second << "::";
    it++;
  }
  cout << endl;
}
long long int ncr(long long int n, long long int r) {
  if (r > n - r) r = n - r;
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) {
      C[j] = (C[j] + C[j - 1]);
      C[j] %= 1000000007;
    }
  }
  return C[r];
}
vector<long long int> prime_factors(long long int n) {
  vector<long long int> ans;
  while (n % 2 == 0) {
    ans.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) ans.push_back(n);
  return ans;
}
long long int pow_m(long long int a, long long int b) {
  if (b == 0) return 1 % 1000000007;
  long long int k = (long long int)pow_m(a, b / 2);
  if (b % 2) {
    return (((k * k) % 1000000007) * a) % 1000000007;
  } else
    return (k * k) % 1000000007;
}
long long int poww(long long int a, long long int b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long int k = poww(a, b / 2);
  if (b % 2) {
    return k * k * a;
  } else
    return k * k;
}
long long int modInverse(long long int a, long long int m) {
  return pow_m(a, m - 2);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
string int_to_hex(int a) {
  if (a == 0) return "0";
  string ans;
  while (a) {
    int k = a % 16;
    if (k <= 9) {
      ans += ('0' + k);
    } else {
      ans += ('A' + (k - 10));
    }
    a /= 16;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long int ncrr(long long int a, long long int b) {
  long long int ans = 1;
  if (b > a / 2) {
    b = a - b;
  }
  for (int i = 0; i < b; i++) {
    ans *= a;
    a--;
    ans %= 1000000007;
  }
  for (int i = 1; i <= b; i++) {
    ans *= (modInverse(i, 1000000007));
    ans %= 1000000007;
  }
  return ans;
}
void init_code() {}
class KMP {
 public:
  vector<int> LPS(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n) {
      if (s[i] == s[len]) {
        lps[i++] = ++len;
      } else {
        if (len != 0) {
          len = lps[len - 1];
        } else {
          lps[i++] = 0;
        }
      }
    }
    return lps;
  }
  vector<int> match(string A, string B) {
    auto lps = LPS(B);
    vector<int> ans;
    int n = A.size();
    int m = B.size();
    int i = 0;
    int j = 0;
    while (i < n) {
      if (A[i] == B[j]) {
        i++;
        j++;
      }
      if (j == m) {
        ans.push_back(i - j);
        j = lps[j - 1];
      } else if (i < n && A[i] != B[j]) {
        if (j == 0)
          i++;
        else
          j = lps[j - 1];
      }
    }
    return ans;
  }
};
class fast_segtree {
 public:
  static const long long int N = 2e5 + 15;
  long long int n = N;
  long long int t[2 * N];
  void build() {
    for (long long int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
  }
  void modify(long long int p, long long int value) {
    for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  }
  long long int query(long long int l, long long int r) {
    long long int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
  fast_segtree(vector<long long int> &A) {
    n = A.size();
    for (long long int i = 0; i < A.size(); i++) t[i + n] = A[i];
    build();
  };
  fast_segtree(long long int n1) {
    n = n1;
    for (long long int i = 0; i < n; i++) t[i + n] = 0;
    build();
  };
};
class segtree {
 public:
  vector<long long int> A;
  long long int n;
  segtree(long long int n1) {
    n = n1;
    A.clear();
    A.resize(4 * n + 5);
  };
  void sett(long long int id, long long int s, long long int e,
            long long int idx, long long int val) {
    if (idx < s || idx > e) return;
    A[id] += val;
    if (s == e) return;
    long long int mid = (s + e) / 2;
    sett(2 * id, s, mid, idx, val);
    sett(2 * id + 1, mid + 1, e, idx, val);
  }
  long long int gett(long long int id, long long int s, long long int e,
                     long long int l, long long int r) {
    if (s >= l && e <= r) return A[id];
    if (min(e, r) < max(s, l)) return 0;
    long long int mid = (s + e) / 2;
    long long int ans = 0;
    ans += gett(2 * id, s, mid, l, r);
    ans += gett(2 * id + 1, mid + 1, e, l, r);
    return ans;
  }
  void sett(long long int id, long long int val) { sett(1, 0, n - 1, id, val); }
  long long int gett(long long int l, long long int r) {
    return gett(1, 0, n - 1, l, r - 1);
  }
};
vector<long long int> djikstra(int sr, vector<vector<pair<int, int>>> &gr) {
  int n = gr.size();
  vector<long long int> ans(n, 1e15);
  priority_queue<pair<int, int>> pq;
  pq.push({0, sr});
  while (pq.size()) {
    auto top = pq.top();
    pq.pop();
    int id = top.second;
    int val = -top.second;
    if (ans[id] > val) {
      ans[id] = val;
      for (int j = 0; j < gr[id].size(); j++) {
        long long int new_dis = -val - gr[id][j].second;
        int des = gr[id][j].first;
        if (ans[des] > -new_dis) {
          pq.push({new_dis, des});
        }
      }
    }
  }
  return ans;
}
class union_find {
 public:
  const int max_sz = 2e5 + 5;
  vector<int> rank;
  vector<int> parent;
  union_find(int n) {
    rank.resize(n);
    parent = rank;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  };
  int find(int i) {
    if (parent[i] == i) return i;
    return find(parent[i]);
  }
  int connect(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a == b) return -1;
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
    return 0;
  }
};
const int max_sz = 2e5 + 5;
vector<set<int>> gr, gr1;
vector<int> vis;
vector<int> vis1;
bool cyc = 0;
void dfs1(int i) {
  if (vis[i] == 1) cyc = 1;
  if (vis[i] == 2 || cyc) return;
  vis[i] = 1;
  int maxa = -1;
  for (int j : gr[i]) {
    dfs1(j);
    maxa = max(maxa, j);
  }
  if (maxa < i) {
    vis1[i] = 1;
  }
  vis[i] = 2;
}
void help() {
  int n;
  cin >> n;
  gr.clear();
  gr1.clear();
  vis.clear();
  vis1.clear();
  gr.resize(n);
  gr1 = gr;
  vis.resize(n);
  vis1.resize(n);
  cyc = 0;
  vector<int> out(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    out[i] = k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      a--;
      gr[i].insert(a);
      gr1[a].insert(i);
    }
  }
  for (int i = 0; i < n; i++) {
    dfs1(i);
  }
  if (cyc) {
    cout << -1 << endl;
    return;
  }
  int ans = 0;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (out[i] == 0) {
      q.push(i);
    }
  }
  vector<int> maxas(n, -1);
  for (int i = 0; i < n; i++) {
    if (gr[i].size()) maxas[i] = *(gr[i].rbegin());
  }
  while (q.size()) {
    vector<int> t;
    ans++;
    set<int> s1;
    while (q.size()) {
      auto top = q.front();
      q.pop();
      for (int j : gr1[top]) {
        out[j]--;
        if (out[j] == 0 && maxas[j] < j) {
          q.push(j);
        } else if (out[j] == 0) {
          t.push_back(j);
        }
        gr[j].erase(top);
        s1.insert(j);
      }
    }
    for (int k : s1) {
      if (out[k] == 0)
        maxas[k] = -1;
      else
        maxas[k] = *(gr[k].rbegin());
    }
    for (int k : t) {
      q.push(k);
    }
  }
  cout << ans << endl;
}
int main() {
  init_code();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    help();
  }
  return 0;
}
