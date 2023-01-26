#include <bits/stdc++.h>
using namespace std;
long long int combi(int n, int k) {
  long long int ans = 1;
  if (k > n) {
    ans = 0;
  } else {
    k = k > n - k ? n - k : k;
    long long int j = 1;
    for (; j <= k; j++, n--) {
      if (n % j == 0) {
        ans *= n / j;
      } else if (ans % j == 0) {
        ans = ans / j * n;
      } else {
        ans = (ans * n) / j;
      }
    }
  }
  return ans;
}
unordered_map<int, int> hm;
void countFreq(int b[], int n) {
  for (int i = 0; i < n; i++) hm[b[i]]++;
  int max_count = 0, res = -1;
  for (auto i : hm) {
    if (max_count < i.second) {
      res = i.first;
      max_count = i.second;
    }
  }
}
int query(int x) { return hm[x]; }
int previousFibonacci(int n) {
  double a = n / ((1 + sqrt(5)) / 2.0);
  return round(a);
}
int maxRepeating(string str) {
  int n = str.length();
  int count = 0;
  char res = str[0];
  int cur_count = 1;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && str[i] == str[i + 1]) {
      cur_count++;
    } else {
      if (cur_count > count) {
        count = cur_count;
        res = str[i];
      }
      cur_count = 1;
    }
  }
  return count;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int findIndex(int n) {
  float fibo = 2.078087 * log(n) + 1.672276;
  return round(fibo);
}
string fib(int n) {
  int a = 0, b = 1, c, i;
  string s0 = "0", s1 = "1", s;
  for (i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
    s = s1 + s0;
    s0 = s1;
    s1 = s;
  }
  return s1;
}
int findSubSequence(string s, int num) {
  int res = 0;
  int i = 0;
  while (num) {
    if (num & 1) res += s[i] - '0';
    i++;
    num = num >> 1;
  }
  return res;
}
int combinedSum(string s) {
  int n = s.length();
  int c_sum = 0;
  int range = (1 << n) - 1;
  for (int i = 0; i <= range; i++)
    c_sum += (findSubSequence(s, i) % 1000000007);
  return c_sum;
}
int maxFreq(int *arr, int n) {
  int res = 0;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[res]) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      res = i;
      count = 1;
    }
  }
  return arr[res];
}
int getIndex(vector<string> v, string K) {
  auto it = find(v.begin(), v.end(), K);
  int index;
  if (it != v.end()) {
    index = it - v.begin();
  } else {
    index = -1;
  }
  return index;
}
int const N = 10000000;
int is_prime[N];
bool sieve() {
  int i = 2;
  while (i * i <= N) {
    if (is_prime[i] == 0) {
      i++;
      continue;
    }
    int j = 2 * i;
    while (j < N) {
      is_prime[j] = 0;
      j += i;
    }
    i++;
  }
}
int mod(string num, int a) {
  int res = 0;
  for (int i = 0; i < num.length(); i++)
    res = (res * 10 + (int)num[i] - '0') % a;
  return res;
}
string decimalToBinary(long long int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int power(long long x, unsigned int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long calculate(long long int p, long long int q) {
  long long int mod = 998244353, expo;
  expo = mod - 2;
  while (expo) {
    if (expo & 1) {
      p = (p * q) % mod;
    }
    q = (q * q) % mod;
    expo >>= 1;
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, ans = 0;
    cin >> n >> k;
    long long int a[n];
    vector<long long int> v, p, neg;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= 0)
        p.push_back(a[i]);
      else
        neg.push_back(a[i]);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    sort(neg.begin(), neg.end());
    for (int i = 0; i < p.size(); i = i + k) {
      v.push_back(p[i]);
    }
    for (int i = 0; i < neg.size(); i = i + k) {
      v.push_back(-1 * neg[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ans += v[0];
    for (int i = 1; i < v.size(); i++) ans += (2 * v[i]);
    cout << ans << endl;
  }
}
