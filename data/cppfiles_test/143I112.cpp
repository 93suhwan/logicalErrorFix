#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ALL(x) (x).begin(), (x).end()

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename K, typename V, typename Hash = std::hash<K>>
using umap = unordered_map<K, V, Hash>;
template <typename K, typename Hash = std::hash<K>>
using uset = unordered_set<K, Hash>;

using namespace __gnu_pbds;
template <typename K, typename V>
using ordmap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K>
using ordset = ordmap<K, null_type>;
// use pair of ints for multiset, the second element needs to be unique (e.g. just use a counter).

// helpers
namespace {

// ostream
namespace {

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T>
ostream& OutputCollection(ostream& os, const T& collection, char s, char e) {
  os << s;
  string separator;
  for (const auto& x : collection) {
    os << separator << x;
    separator = ", ";
  }
  return os << e;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  return OutputCollection(os, v, '[', ']');
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
  return OutputCollection(os, arr, '[', ']');
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_multiset<T>& s) {
  return OutputCollection(os, s, '{', '}');
}
template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  return OutputCollection(os, m, '{', '}');
}
template <typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& m) {
  return OutputCollection(os, m, '{', '}');
}

template <typename T>
ostream& operator<<(ostream& os, const priority_queue<T>& pq) {
  priority_queue<T> copy = pq;
  vector<T> v;
  while (!copy.empty()) {
    v.push_back(copy.top());
    copy.pop();
  }
  return os << v;
}

}  // namespace

// hashing
namespace {

template <class T>
inline void HashCombine(std::size_t& seed, const T& v) {
  seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T, size_t N>
struct ArrayHash {
  size_t operator()(const array<T, N>& a) const {
    size_t seed = 0;
    for (auto e : a) HashCombine(seed, e);
    return seed;
  }
};

}  // namespace

// permutations and combinations, factorials, primes
namespace {

template <typename T>
T nChoosek(T n, T k) {
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;

  if (k > n - k) k = n - k;
  T ret = 1;
  for (T i = 0; i < k; i++) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}

template <typename T>
T fact(T n) {
  T ret = 1;
  for (T i = 1; i <= n; i++) ret *= i;
  return ret;
}

template <typename T>
// Compute n! % p - p must be prime
T fact_mod(T n, T p) {
  if (n >= p) return 0;
  T ret = 1;
  for (T i = 1; i <= n; i++) ret = (ret * i) % p;
  return ret;
}

template <typename T>
// Compute (n!/m) % p - p must be prime
T fact_mod_div(T n, T p, T m) {
  if (n >= p) return 0;
  T ret = 1;
  for (T i = 1; i <= n; i++) {
    if (i != m) ret = (ret * i) % p;
  }
  return ret;
}

// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
constexpr int kMaxPrime = 22;  // largest number you want to check primality
static vector<bool> is_prime(kMaxPrime + 1, true);
void InitAllIsPrime() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= kMaxPrime; i++) {
    if (is_prime[i] && (long long)i * i <= kMaxPrime) {
      for (int j = i * i; j <= kMaxPrime; j += i) is_prime[j] = false;
    }
  }
}

}  // namespace

// Bits
namespace {

int IsBitSet(int a, int bit) { return ((a >> bit) & 1); }
// These are both undefined for v=0 since it has no most significant bit.
uint64_t Msb64(uint64_t v) { return 63ULL - __builtin_clzll(v); }
uint32_t Msb32(uint32_t v) { return 31ULL - __builtin_clz(v); }

}  // namespace

// Aho string matching.

namespace {

struct Aho {
  struct Node {
    Node(int i, int parent, int curchar, const string& str)
        : i(i), parent(parent), curchar(curchar), pathview(&str[0], (size_t)(i + 1)) {
      fill(ALL(next), -1);
    }

    Node* Next(vector<Node>& nodes, int c) {
      if (c == -1) return nullptr;
      return &nodes[next[c]];
    }
    Node* Parent(vector<Node>& nodes) {
      if (parent == -1) return nullptr;
      return &nodes[parent];
    }
    Node* SuffixLink(vector<Node>& nodes) {
      if (suffix_link == -1) return nullptr;
      return &nodes[suffix_link];
    }
    Node* DictSuffixLink(vector<Node>& nodes) {
      if (dict_suffix_link == -1) return nullptr;
      return &nodes[dict_suffix_link];
    }

    array<int, 26> next;

    const int i;
    const int parent;
    const int curchar;
    const string_view pathview = "";  // only valid if you keep all the original strings alive

    int suffix_link = -1;
    int dict_suffix_link = -1;

    bool word_ends_here = false;
  };

  vector<Node> nodes;
  Node* root = nullptr;

  Aho(int max_nodes) {
    nodes.reserve(max_nodes);
    nodes.emplace_back(0, -1, -1, "");  // add a root node
    root = &nodes[0];
  }

  int Insert(const string& str) {
    Node* n = root;
    for (int i = 0; i < str.length(); i++) {
      int c = str[i] - 'a';
      if (n->next[c] == -1) {
        nodes.emplace_back(nodes.size(), n->i, c, str);
        n->next[c] = nodes.back().i;
      }
      n = n->Next(nodes, c);
    }
    n->word_ends_here = true;
    return n->i;
  }

  void SetSuffixLinks() {
    queue<Node*> q;
    for (int node : root->next) {
      if (node != -1) q.push(&nodes[node]);
    }

    for (int c = 0; c < 26; c++) {
      if (root->next[c] == -1) root->next[c] = root->i;
    }

    while (!q.empty()) {
      Node* n = q.front();
      q.pop();

      for (int child : n->next) {
        if (child != -1) q.push(&nodes[child]);
      }

      if (n->Parent(nodes)->suffix_link == -1)
        n->suffix_link = root->i;
      else
        n->suffix_link = n->Parent(nodes)->SuffixLink(nodes)->next[n->curchar];

      for (int c = 0; c < 26; c++) {
        if (n->next[c] == -1) {
          if (n->suffix_link != -1)
            n->next[c] = n->SuffixLink(nodes)->next[c];
          else
            n->next[c] = root->i;
        }
      }

      if (n->suffix_link != -1 && n->SuffixLink(nodes)->word_ends_here)
        n->dict_suffix_link = n->suffix_link;
      else if (n->suffix_link != -1)
        n->dict_suffix_link = n->SuffixLink(nodes)->dict_suffix_link;
    }
  }
};
}  // namespace

struct UnionFind {
  vi parent;

  UnionFind(int n) : parent(n) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int FindRoot(int i) {
    if (i == parent[i]) return i;
    int par = FindRoot(parent[i]);
    return par;
  }

  // make a the parent
  void MergeSets(int a, int b) {
    a = FindRoot(a);
    parent[b] = a;
  }
};

// StrongComponents
namespace {

void dfs1(const vvi& adj, int v, vector<bool>& visited, vi& order) {
  if (visited[v]) return;
  visited[v] = true;
  for (int u : adj[v]) dfs1(adj, u, visited, order);
  order.push_back(v);
}

bool dfs2(const vvi& adj_rev, int v, int c, vi& component) {
  if (component[v] != -1) return false;
  component[v] = c;
  for (auto u : adj_rev[v]) dfs2(adj_rev, u, c, component);
  return true;
}

vvi AdjRev(const vvi& adj) {
  vvi adj_rev(adj.size());
  for (int i = 0; i < adj.size(); i++) {
    for (int v : adj[i]) adj_rev[v].push_back(i);
  }
  return adj_rev;
}

// Returns a vector the same size as the number of nodes in the graph. The number at each index in the returned vector is the
// component of that graph node. The component numbers are just sequential.
vi StrongComponents(const vvi& adj) {
  vi reverse_order = [&adj]() {
    vector<bool> visited(adj.size(), false);
    vi order;
    for (int i = 0; i < adj.size(); i++) dfs1(adj, i, visited, order);
    reverse(ALL(order));
    return order;
  }();

  vvi adj_rev = AdjRev(adj);
  vi component(adj.size(), -1);
  int c = 0;
  for (int v : reverse_order) c += dfs2(adj_rev, v, c, component);
  return component;
}

}  // namespace

template <typename Sum>
class SegTree {
  using Container = typename Sum::ContainerType;
  using ValType = typename Sum::ValType;

 public:
  struct Node {
    int first = -1;
    int last = -1;

    Sum sum;

    Node* l = nullptr;
    Node* r = nullptr;
  };

  Node* root = nullptr;

  SegTree(const Container& c) {
    nodes_.reserve(2 * c.size());
    root = Build(0, c.size() - 1, c);
  }

  void Update(int k, ValType val) { UpdateHelper(root, k, val); }

  Sum GetSum(int first, int last) { return GetSumHelper(root, first, last); }

 private:
  vector<Node> nodes_;

  void UpdateHelper(Node* node, int k, ValType val) {
    if (k == node->first && k == node->last) {
      node->sum = Sum::Init(val);
      return;
    }
    if (k <= node->l->last)
      UpdateHelper(node->l, k, val);
    else
      UpdateHelper(node->r, k, val);

    node->sum = Sum::Combine(node->l->sum, node->r->sum);
  }

  Sum GetSumHelper(Node* node, int first, int last) {
    if (node->first == first && node->last == last) return node->sum;

    if (first >= node->r->first) return GetSumHelper(node->r, first, last);
    if (last <= node->l->last) return GetSumHelper(node->l, first, last);

    return Sum::Combine(GetSumHelper(node->l, first, node->l->last), GetSumHelper(node->r, node->r->first, last));
  }

  Node* Build(int first, int last, const Container& c) {
    nodes_.emplace_back();
    Node* node = &nodes_.back();
    node->first = first;
    node->last = last;

    int sz = last - first + 1;

    if (sz == 1) {
      node->sum = Sum::Init(c[first]);
      return node;
    }

    int lsz = (sz + 1) / 2;
    int rsz = sz / 2;

    node->l = Build(first, first + lsz - 1, c);
    node->r = Build(first + lsz, first + lsz + rsz - 1, c);

    node->sum = Sum::Combine(node->l->sum, node->r->sum);

    return node;
  }
};

//-------------------------------------------------------------------------------------------------------------------------------

}  // namespace

vl Solve(vl& a) {
  vl counts(a.size() + 1, 0);
  for (int x : a) counts[x]++;

  priority_queue<ll> extras;
  vl incs(a.size() + 1, -1);
  for (int i = 0; i <= a.size(); i++) {
    if (counts[i] == 0 && extras.empty()) break;

    if (counts[i] == 0) {
      incs[i] = incs[i - 1] + (i - extras.top());
      extras.pop();
    } else {
      for (int j = 0; j < counts[i] - 1; j++) extras.push(i);
      if (i == 0)
        incs[i] = 0;
      else
        incs[i] = incs[i - 1];
    }
  }

  vl b(a.size() + 1, -1);
  b[0] = counts[0];
  for (int i = 1; i <= a.size(); i++) {
    if (incs[i - 1] == -1) break;
    b[i] = incs[i - 1] + counts[i];
  }

  return b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  (void)freopen("in.txt", "r", stdin);
#endif

  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vl a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int x : Solve(a)) cout << x << " ";
    cout << "\n";
  }
}