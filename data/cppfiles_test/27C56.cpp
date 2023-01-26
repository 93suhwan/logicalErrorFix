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
  cout << '\n';
}
void show_vp(vector<pair<int, int>> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i].first << " " << t[i].second << "::";
  }
  cout << '\n';
}
void show_vd(vector<double> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << ",";
  }
  cout << '\n';
}
void show_vll(vector<long long int> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << ",";
  }
  cout << '\n';
}
void show_vt(vector<tuple<long long, long long>> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << get<0>(t[i]) << " " << get<1>(t[i]) << "::";
  }
  cout << '\n';
}
void show_vb(vector<bool> t) {
  for (int i = 0; i < t.size(); i++) {
    cout << t[i] << " ";
  }
  cout << '\n';
}
void show_vvi(vector<vector<int>> ans) {
  cout << "---------------------------" << '\n';
  for (int i = 0; i < ans.size(); i++) {
    show_vi(ans[i]);
  }
  cout << '\n';
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
    cout << "******************" << '\n';
    show_vvi(ans[i]);
  }
  cout << '\n';
}
void show_vvb(vector<vector<bool>> ans) {
  cout << "---------------------------" << '\n';
  for (int i = 0; i < ans.size(); i++) {
    show_vb(ans[i]);
  }
  cout << '\n';
}
void show_vs(vector<string> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << "::";
  }
  cout << '\n';
}
void show_vc(vector<char> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i];
  }
  cout << '\n';
}
void show_vvc(vector<vector<char>> A) {
  cout << "---------------------------" << '\n';
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
    cout << "******************" << '\n';
    show_vvs(ans[i]);
  }
  cout << '\n';
}
void show_um(unordered_map<int, int> &map) {
  unordered_map<int, int>::iterator it;
  it = map.begin();
  while (it != map.end()) {
    cout << it->first << " " << it->second << "::";
    it++;
  }
  cout << '\n';
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
int fact(int n) {
  return (n == 0) ? 1 : (long long int)(n * fact(n - 1)) % 1000000007;
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
  if (b == 1) return a % 1000000007;
  if (b == 0) return 1 % 1000000007;
  long long int k = (long long int)pow_m(a, b / 2);
  if (b % 2) {
    return (((k * k) % 1000000007) * a) % 1000000007;
  } else
    return (((k * k) % 1000000007));
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
int modInverse(int a, int m) { return pow_m(a, m - 2); }
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
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
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
bool check(int f, int s, int t, int rem) {
  if (s == f) return 0;
  if (s < f) {
    return check(s, f, 1 - t, rem);
  }
  int w;
  if (t == 0)
    w = (rem + 1) / 2;
  else
    w = rem / 2;
  if (f + w < s)
    return 1;
  else
    return 0;
}
bool check(int i, string &A, string &B) {
  int j = 1;
  i++;
  while (i < A.size() && j < B.size()) {
    if (B[j] == A[i]) {
      j++;
      i++;
    } else {
      i += 2;
    }
  }
  if ((A.size() - i) % 2) return 0;
  if (j == B.size()) {
    cout << "YES" << '\n';
  }
  return j == B.size();
}
void help() {
  string A, B;
  cin >> A >> B;
  bool b1, b2;
  b1 = b2 = 1;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == B[0] && b1 && i % 2 == 0) {
      b1 = 0;
      if (check(i, A, B)) return;
    }
    if (A[i] == B[0] && b2 && i % 2 == 1) {
      b2 = 0;
      if (check(i, A, B)) return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    help();
  }
  return 0;
}
