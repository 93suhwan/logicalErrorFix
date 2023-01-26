#include <bits/stdc++.h>
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 7;
vector<long long> primes;
long long modoinv(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
class Node {
 public:
  char data;
  unordered_map<char, Node*> children;
  bool terminal;
  Node(char d) {
    data = d;
    terminal = false;
  }
};
class trie {
 public:
  Node* root;
  long long cnt;
  trie() {
    root = new Node('\0');
    cnt = 0;
  }
  void insert(char* w) {
    Node* temp = root;
    for (long long i = 0; w[i] != '\0'; i++) {
      char ch = w[i];
      if (temp->children.count(ch)) {
        temp = temp->children[ch];
      } else {
        Node* n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->terminal = true;
  }
  bool find(string w) {
    Node* temp = root;
    for (long long i = 0; w[i] != '\0'; i++) {
      char ch = w[i];
      if (temp->children.count(ch) == 0)
        return false;
      else {
        temp = temp->children[ch];
      }
    }
    return temp->terminal;
  }
};
vector<long long> primeFactors(long long n) {
  vector<long long> ans;
  long long cur = 1;
  ans.push_back(1);
  while (n % 2 == 0) {
    cur = cur * 2;
    ans.push_back(cur);
    n = n / 2;
  }
  for (long long i = 3; i * i <= (n); i = i + 2) {
    while (n % i == 0) {
      cur = cur * i;
      ans.push_back(cur);
      n = n / i;
    }
  }
  if (n > 2) ans.push_back(cur * n);
  return ans;
}
vector<long long> sieve(long long p) {
  vector<long long> mark(p, 1);
  mark[2] = 2;
  for (long long i = 3; i < p; i += 2) {
    if (mark[i] == 1) {
      mark[i] = i;
      for (long long j = i * i; j < p; j += 2 * i) {
        if (mark[j] == 1) mark[j] = i;
      }
    }
  }
  return mark;
}
long long mod_exp(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long a = mod_exp(x, n / 2, m);
  if (n % 2 == 0)
    return (a * a) % m;
  else
    return (x * a * a) % m;
}
bool isPrime(long long n) {
  if (n == 1) return 1;
  if (n == 2) return 1;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first > p2.first) return 0;
  if (p1.first < p2.first) return 1;
  return (p1.second > p2.second);
}
void solve(long long arr[], vector<pair<long long, long long>>& vec,
           long long st, long long en, long long j) {
  long long i;
  for (i = st; i >= en; i--) {
    arr[vec[i - 1].second] = j;
    j++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n], i;
    for (i = 0; i < n; i++) cin >> arr[i];
    char ch;
    vector<long long> red, blue;
    for (i = 0; i < n; i++) {
      cin >> ch;
      if (ch == 'R')
        red.push_back(arr[i]);
      else
        blue.push_back(arr[i]);
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    long long flag = 0, m = blue.size(), q = red.size();
    i = 1;
    while ((i <= m) && (!flag)) {
      if (i > blue[i - 1]) flag = 1;
      i++;
    }
    while ((i <= (m + q)) && (!flag)) {
      if (i < red[i - m - 1]) flag = 1;
      i++;
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
