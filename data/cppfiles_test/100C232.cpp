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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n - 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1)
      cout << a[0] << endl;
    else {
      sort(a, a + n);
      for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
      sort(b, b + n - 1);
      cout << max(b[n - 2], a[0]) << endl;
    }
  }
}
