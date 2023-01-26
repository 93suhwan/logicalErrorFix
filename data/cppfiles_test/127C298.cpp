#include <bits/stdc++.h>
using namespace std;
void varx(long long t) { cerr << t; }
void varx(int t) { cerr << t; }
void varx(string t) { cerr << t; }
void varx(char t) { cerr << t; }
void varx(long double t) { cerr << t; }
void varx(double t) { cerr << t; }
void varx(unsigned long long t) { cerr << t; }
void varx(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << "\n";
}
void varx(vector<int> arr, int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << "\n";
}
void varx(long long arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << "\n";
}
set<string>::iterator it;
unordered_set<int>::iterator usi;
const long long INF = 2e18;
const long long mod = 1000000007;
const long long mod2 = 998244353;
const long double PI = 3.141592653589793238462;
int getIndex(vector<int> v, int k) {
  auto it = find(v.begin(), v.end(), k);
  if (it != v.end()) {
    int index = it - v.begin();
    return index;
  } else
    return -1;
}
long long fact(int n, int k) {
  return (k == 0 || n <= 1) ? 1 : n * fact(n - 1, --k);
}
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
void dfs(vector<int> adj[], int root, int &ans, int length, int &count,
         bool vis[]) {
  vis[root] = true;
  bool isLeaf = true;
  for (auto i : adj[root]) {
    if (!vis[i]) {
      isLeaf = false;
      dfs(adj, i, ans, length + 1, count, vis);
    }
  }
  if (isLeaf) {
    ans += length;
    count++;
  }
}
double myPow(double x, int n) {
  long double m = x, ans = 1;
  long long p = abs(n);
  while (p > 0) {
    if (p % 2 == 1) {
      ans = ans * m;
      p--;
    } else {
      m = m * m;
      p = p / 2;
    }
  }
  if (n < 0) return 1 / ans;
  return ans;
}
long long myPow(long long x, long long n) {
  long long m = x, ans = 1;
  long long p = abs(n);
  while (p > 0) {
    if (p % 2 == 1) {
      ans = (ans * m) % mod;
      p--;
    } else {
      m = (m * m) % mod;
      p = p / 2;
    }
  }
  return ans;
}
char alpha(int n) {
  string s = "abcdefghijklmnopqrstuvwxyz";
  return s[n];
}
class Trie {
  struct Trienode {
    char val;
    int count;
    int endsHere;
    Trienode *child[26];
  };
  Trienode *root;
  Trienode *getNode(int index) {
    Trienode *newnode = new Trienode();
    newnode->val = 'a' + index;
    newnode->count = newnode->endsHere = 0;
    for (int i = 0; i < 26; ++i) newnode->child[i] = NULL;
    return newnode;
  }

 public:
  Trie() { root = getNode('/' - 'a'); }
  void insert(string word) {
    Trienode *curr = root;
    int index;
    for (int i = 0; word[i] != '\0'; ++i) {
      index = word[i] - 'a';
      if (curr->child[index] == NULL) curr->child[index] = getNode(index);
      curr->child[index]->count += 1;
      curr = curr->child[index];
    }
    curr->endsHere += 1;
  }
  bool search(string word) {
    Trienode *curr = root;
    int index;
    for (int i = 0; word[i] != '\0'; ++i) {
      index = word[i] - 'a';
      if (curr->child[index] == NULL) return false;
      curr = curr->child[index];
    }
    return (curr->endsHere > 0);
  }
  bool startsWith(string prefix) {
    Trienode *curr = root;
    int index;
    for (int i = 0; prefix[i] != '\0'; ++i) {
      index = prefix[i] - 'a';
      if (curr->child[index] == NULL) return false;
      curr = curr->child[index];
    }
    return (curr->count > 0);
  }
};
const int s = 1e6;
long long tree[s] = {0};
void buildSegTree(vector<long long> &arr, int treeIndex, int lo, int hi) {
  if (lo == hi) {
    tree[treeIndex] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
  buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);
  tree[treeIndex] = tree[2 * treeIndex + 1] & tree[2 * treeIndex + 2];
}
void updateValSegTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
  if (lo == hi) {
    tree[treeIndex] = val;
    return;
  }
  int mid = lo + (hi - lo) / 2;
  if (arrIndex > mid)
    updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
  else if (arrIndex <= mid)
    updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
  tree[treeIndex] = tree[2 * treeIndex + 1] & tree[2 * treeIndex + 2];
}
int querySegTree(int treeIndex, int lo, int hi, int i, int j) {
  if (lo > j || hi < i) return 0;
  if (i <= lo && j >= hi) return tree[treeIndex];
  int mid = lo + (hi - lo) / 2;
  if (i > mid)
    return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
  else if (j <= mid)
    return querySegTree(2 * treeIndex + 1, lo, mid, i, j);
  int leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
  int rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);
  return (leftQuery & rightQuery);
}
class disjointset {
 public:
  vector<int> parent;
  vector<int> size;

 public:
  void makeset(int m) {
    for (int i = 0; i < m; i++) {
      parent.push_back(i);
      size.push_back(1);
    }
  }
  int findPar(int x) {
    while (x != parent[x]) x = parent[x];
    return x;
  }
  void unionSet(int x, int y) {
    int p = findPar(x);
    int q = findPar(y);
    if (p == q) {
      return;
    } else {
      if (size[p] >= size[q]) {
        parent[q] = p;
        size[p] = size[p] + size[q];
      } else {
        parent[p] = q;
        size[q] = size[p] + size[q];
      }
    }
  }
};
int bfs(vector<int> graph[], int root, int n, int &answer) {
  vector<int> dist(n, 0);
  dist[root] = 1;
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int curr = q.front();
    for (auto it : graph[curr]) {
      if (dist[it] != 0) {
        continue;
      }
      q.push(it);
      dist[it] = dist[curr] + 1;
    }
    q.pop();
  }
  int maxi = INT_MIN, vertex = -1;
  for (int i = 0; i < n; i++) {
    if (maxi < dist[i]) {
      maxi = dist[i];
      vertex = i;
    }
  }
  answer = maxi;
  return vertex;
}
string decToBinary(long long n) {
  string t = "";
  for (int i = 63; i >= 0; i--) {
    int k = n >> i;
    if (k & 1)
      t += "1";
    else
      t += "0";
  }
  return t;
}
int lengthOfLIS(vector<long long> &nums, bool &ev) {
  vector<long long> subsequence;
  for (int itr = 0; itr < nums.size(); itr++) {
    auto index = lower_bound(subsequence.begin(), subsequence.end(), nums[itr]);
    if (index == subsequence.end()) {
      subsequence.push_back(nums[itr]);
      if (itr % 2 == 1)
        ev = true;
      else
        ev = false;
    } else
      *index = nums[itr];
  }
  return subsequence.size();
}
void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  if (t != "abc") {
    cout << s;
    return;
  }
  bool c = false, b = false, before = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'b') {
      b = true;
      before = true;
    } else if (s[i] == 'c') {
      c = true;
    }
  }
  if (!b || !c || s[0] != 'a') {
    cout << s;
    return;
  }
  int cc = 0;
  int arr[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    int temp = i;
    if (i == 1)
      i = 2;
    else if (i == 2)
      i = 1;
    for (int j = 0; j < arr[i]; j++) {
      cout << char(97 + i);
    }
    i = temp;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " seconds"
       << '\n';
  return 0;
}
