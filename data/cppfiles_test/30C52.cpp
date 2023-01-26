#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
void Google(long long ans, long long i) {
  cout << "Case #" << i << ": " << ans << endl;
}
void debug(vector<pair<int, int>> A) {
  cout << "DEBUG: " << endl;
  for (int i = 0; i < A.size(); i++) {
    cout << "First: " << A[i].first << endl;
    cout << "Second: " << A[i].second << endl;
  }
}
void debug(set<pair<int, int>> s) {
  cout << "DEBUG: " << endl;
  for (auto i : s) {
    cout << "First: " << i.first << endl;
    cout << "Second: " << i.second << endl;
  }
}
bool mycomp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) {
    return true;
  }
  return false;
}
bool mycomp2(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.second) {
    return true;
  }
  return false;
}
int SUM(vector<int> a, int from, int to) {
  int Sum = 0;
  for (int i = from; i < to + 1; i++) {
    Sum += a[i];
  }
  return Sum;
}
bool is_integer(double k) { return std::floor(k) == k; }
void Print(vector<int> &BITS) {
  for (auto i : BITS) {
    cout << i << " ";
  }
  cout << endl;
}
void swap(int i, int j, string &s) {
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}
void swapEvery2(vector<int> &arr) {
  int i = 0;
  while (i + 1 < arr.size()) {
    arr[i] = arr[i] ^ arr[i + 1];
    arr[i + 1] = arr[i] ^ arr[i + 1];
    arr[i] = arr[i] ^ arr[i + 1];
    i += 2;
  }
}
void XOR(string s1, string s2) {
  for (int i = 0; i < s1.length(); i++) {
    int a = s1[i];
    int b = s2[i];
    if (a - b == 0) {
      cout << 0;
    } else {
      cout << 1;
    }
  }
  cout << endl;
}
int nextPrime(int n) {
  int i = 1;
  bool Printed = false;
  for (; i < 100; i++) {
    if ((n + i) % 2 != 0 && (n + i) % 3 != 0 && (n + i) % 5 != 0 &&
            (n + i) % 7 != 0 && (n + i) % 11 != 0 && (n + i) % 13 != 0 ||
        (n + i == 2 || n + i == 5 || n + i == 7 || n + i == 11 || n + i == 13 ||
         n + i == 3)) {
      Printed = true;
      break;
    }
  }
  if (Printed) {
    return n + i;
  } else {
    return -1;
  }
}
bool Find(set<pair<int, int>> &s, pair<int, int> a) {
  for (auto i : s) {
    if (a.first == i.first && a.second == i.second) {
      return true;
    }
  }
  return false;
}
bool check(set<pair<int, int>> &s, pair<int, int> a) {
  bool lftrgtlwrupr[4] = {false};
  for (auto i : s) {
    if (i.first > a.first && i.second == a.second) {
      lftrgtlwrupr[1] = true;
    } else if (i.first < a.first && i.second == a.second) {
      lftrgtlwrupr[0] = true;
    } else if (i.first == a.first && i.second < a.second) {
      lftrgtlwrupr[2] = true;
    } else if (i.first == a.first && i.second > a.second) {
      lftrgtlwrupr[3] = true;
    }
  }
  return (lftrgtlwrupr[0] && lftrgtlwrupr[1] && lftrgtlwrupr[2] &&
          lftrgtlwrupr[3]);
}
unordered_map<string, int> dp;
int rec(string s, int &Min, int count) {
  if (s.length() == 1 || s == "") {
    return count;
  }
  if (dp.find(s) != dp.end()) {
    return dp[s];
  }
  if (s[0] == s[s.length() - 1]) {
    int temp = rec(s.substr(1, s.length() - 2), Min, count);
    dp[s] = temp;
  } else {
    int temp1 = rec(s.substr(1, s.length() - 1), Min, count + 1);
    int temp2 = rec(s.substr(0, s.length() - 1), Min, count + 1);
    dp[s] = min(temp1, temp2);
  }
  return dp[s];
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
bool isValid(string s) {
  if (s.length() == 0) {
    return true;
  } else {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        i += 1;
        j -= 1;
      } else {
        return false;
      }
    }
    return true;
  }
}
int rec(int count, char chosechar, string curr) {
  if (isValid(curr)) {
    return count;
  }
  if (curr[0] == curr[curr.length() - 1]) {
    return rec(count, chosechar, curr.substr(1, curr.length() - 2));
  } else {
    if (curr[0] == chosechar) {
      return rec(count + 1, chosechar, curr.substr(1, curr.length() - 1));
    } else if (curr[curr.length() - 1] == chosechar) {
      return rec(count + 1, chosechar, curr.substr(0, curr.length() - 1));
    } else {
      return -1;
    }
  }
}
long long handler(string s) {
  if (s.length() == 0 || s.length() == 1) {
    return 0;
  }
  if (s[0] == s[s.length() - 1]) {
    return handler(s.substr(1, s.length() - 2));
  } else {
    long long ret1 = rec(1, s[0], s.substr(1, s.length() - 1));
    long long ret2 = rec(1, s[s.length() - 1], s.substr(0, s.length() - 1));
    if (ret1 == -1 || ret2 == -1) {
      return max(ret1, ret2);
    }
    return min(ret1, ret2);
  }
}
long long iteration(string s, char chosechar) {
  long long i = 0, j = s.length() - 1;
  long long count = 0;
  while (i < j) {
    if (s[i] == s[j]) {
      i += 1;
      j -= 1;
    } else if (s[i] == chosechar) {
      i += 1;
      count += 1;
    } else if (s[j] == chosechar) {
      j -= 1;
      count += 1;
    } else {
      return -1;
    }
  }
  return count;
}
void solution(int caseNum) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long Min = INT_MAX;
  for (int i = 0; i < 26; i++) {
    long long ret = iteration(s, (char)('a' + i));
    if (ret != -1) {
      Min = min(Min, ret);
    }
  }
  if (Min == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << Min << endl;
  }
  return;
}
int main() {
  int t;
  cin >> t;
  int org = t;
  while (t--) {
    solution(org - t);
  }
  return 0;
}
