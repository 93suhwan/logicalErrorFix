#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
bool isSubstring(string s1, string s2) {
  long long M = s1.length();
  long long N = s2.length();
  for (long long i = 0; i <= N - M; i++) {
    long long j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return 1;
  }
  return 0;
}
long long gcd(long long a, long long b) {
  while (b > 0) {
    long long p = a % b;
    a = b;
    b = p;
  }
  return a;
}
long long binpow(long long b) {
  long long m = mod;
  long long a = 2;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
const long long xx = 1e3 + 5;
vector<long long> index1(xx + 1), index2(xx + 1), par1(xx + 1), par2(xx + 1);
long long find_par(long long a, vector<long long> &par) {
  if (a == par[a]) return a;
  return par[a] = find_par(par[a], par);
}
void make_union(long long a, long long b, vector<long long> &par,
                vector<long long> &index) {
  long long p1 = find_par(a, par);
  long long p2 = find_par(b, par);
  if (p1 != p2) {
    long long ma = max(p1, p2);
    long long mi = p2 + p1 - ma;
    par[mi] = ma;
    index[ma]++;
  }
}
long long lsearch(long long q, vector<long long> a, long long l, long long r) {
  long long ans = 0;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (a[mid] >= q) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
      ans = mid + 1;
    }
  }
  return ans;
}
class Graph {
  long long V;
  list<long long> *adj;
  bool isCyclicUtil(long long v, bool visited[], bool *rs);

 public:
  Graph(long long V);
  void addEdge(long long v, long long w);
  bool isCyclic();
};
Graph::Graph(long long V) {
  this->V = V;
  adj = new list<long long>[V];
}
void Graph::addEdge(long long v, long long w) { adj[v].push_back(w); }
bool Graph::isCyclicUtil(long long v, bool visited[], bool *recStack) {
  if (visited[v] == false) {
    visited[v] = true;
    recStack[v] = true;
    list<long long>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
        return true;
      else if (recStack[*i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}
bool Graph::isCyclic() {
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  for (long long i = 0; i < V; i++) {
    visited[i] = false;
    recStack[i] = false;
  }
  for (long long i = 0; i < V; i++)
    if (isCyclicUtil(i, visited, recStack)) return true;
  return false;
}
vector<bool> arr(200001);
vector<bool> arr2(200001);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  long long k, x, n, m1, m2, q, a, b, c, m;
  string s, a1, a3;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    vector<vector<long long>> v(n);
    for (long long j = 0; j < n; j++) {
      cin >> a;
      for (long long k = 0; k < a; k++) {
        cin >> b;
        v[j].push_back(b);
      }
    }
    cin >> m;
    if (m == 0) {
      for (long long j = 0; j < n; j++) {
        cout << v[j].size() << " ";
      }
      continue;
    }
    map<string, long long> ma;
    vector<string> vv;
    for (long long j = 0; j < m; j++) {
      char g;
      string temp = "";
      for (long long k = 0; k < n; k++) {
        cin >> g;
        temp += g;
      }
      ma[temp]++;
      vv.push_back(temp);
    }
    vector<string> sto;
    for (long long j = 0; j < m; j++) {
      for (long long k = 0; k < n; k++) {
        char c = vv[j][k];
        if (c == '1')
          continue;
        else
          c--;
        vv[j][k] = c;
        if (ma[vv[j]] == 0) {
          sto.push_back(vv[j]);
          ma[vv[j]]++;
        }
      }
    }
    long long ans = 0;
    long long ke = -1;
    for (long long j = 0; j < sto.size(); j++) {
      long long tem = 0;
      for (long long k = 0; k < n; k++) {
        tem += v[k][sto[j][k] - 48];
      }
      if (ans <= tem) {
        ans = tem;
        ke = j;
      }
    }
    for (long long k = 0; k < n; k++) {
      cout << sto[ke][k] << " ";
    }
  }
}
