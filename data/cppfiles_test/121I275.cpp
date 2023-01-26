#include <bits/stdc++.h>
using namespace std;
struct CompressedLetter {
  long long num;
  char letter;
};
long long readLL();
string readStr();
void resolve();
void resolveTest();
bool isPrime(long long n);
vector<bool> detectPrimes(long long n);
long long minPosInArray(const vector<long long> &nums);
long long maxPosInArray(const vector<long long> &nums);
vector<long long> calcPrefixSum(const vector<long long> &nums);
vector<long long> calcSuffixSum(const vector<long long> &nums);
vector<long long> getDigits(long long n);
long long sumNumRange(long long start, long long finish);
long long calcNumLength(long long n);
vector<CompressedLetter> processCompressedStr(const string &str);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  resolve();
  return 0;
}
void resolve() {
  long long queryNum = readLL();
  while (queryNum--) {
    resolveTest();
  }
}
void resolveTest() {
  long long length = readLL();
  string src1 = readStr();
  string res = readStr();
  if (src1 == res) {
    cout << 0 << '\n';
    return;
  }
  long long onePos = -1;
  for (int i = 0; i < src1.length(); ++i) {
    if (src1[i] == '1') {
      if (res[i] == '1' || onePos == -1) {
        onePos = i;
      }
    }
  }
  if (onePos == -1) {
    cout << -1 << '\n';
    return;
  }
  long long src1OneNum = 0;
  long long src2OneNum = 0;
  long long resOneNum = 0;
  string src2 = src1;
  for (int i = 0; i < src2.length(); ++i) {
    if (i != onePos) {
      if (src2[i] == '0') {
        src2[i] = '1';
      } else {
        src2[i] = '0';
      }
    }
    src1OneNum += src1[i] == '1';
    src2OneNum += src2[i] == '1';
    resOneNum += res[i] == '1';
  }
  if (resOneNum != src1OneNum && resOneNum != src2OneNum) {
    cout << -1 << '\n';
    return;
  }
  long long diff1 = 0;
  long long diff2 = 0;
  for (int i = 0; i < length; ++i) {
    if (src1[i] == '0' && res[i] == '1') {
      diff1++;
    }
    if (src2[i] == '0' && res[i] == '1') {
      diff2++;
    }
  }
  cout << min(diff1 * 2, diff2 * 2 + 1) << '\n';
}
long long readLL() {
  long long num;
  cin >> num;
  return num;
}
string readStr() {
  string str;
  cin >> str;
  return str;
}
bool isPrime(long long n) {
  if (n == 0 || n == 1) {
    return false;
  }
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
vector<bool> detectPrimes(long long n) {
  vector<bool> nums(n + 1, true);
  nums[0] = false;
  nums[1] = false;
  for (long long i = 2; i <= n; ++i) {
    if (nums[i]) {
      for (long long j = i * i; j <= n; j += i) {
        nums[j] = false;
      }
    }
  }
  return nums;
}
long long minPosInArray(const vector<long long> &nums) {
  long long pos = 0;
  for (long long i = 1; i < nums.size(); ++i) {
    if (nums[pos] > nums[i]) {
      pos = i;
    }
  }
  return pos;
}
long long maxPosInArray(const vector<long long> &nums) {
  long long pos = 0;
  for (long long i = 1; i < nums.size(); ++i) {
    if (nums[pos] < nums[i]) {
      pos = i;
    }
  }
  return pos;
}
vector<long long> getDigits(long long n) {
  vector<long long> digits;
  while (n > 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  return digits;
}
vector<long long> calcPrefixSum(const vector<long long> &nums) {
  vector<long long> prefix(nums.size());
  prefix[0] = nums[0];
  for (long long i = 1; i < nums.size(); ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }
  return prefix;
}
vector<long long> calcSuffixSum(const vector<long long> &nums) {
  vector<long long> suffix(nums.size());
  suffix[nums.size() - 1] = nums[nums.size() - 1];
  for (long long i = (long long)nums.size() - 2; i >= 0; --i) {
    suffix[i] = suffix[i + 1] + nums[i];
  }
  return suffix;
}
long long sumNumRange(long long start, long long finish) {
  if (finish < start) {
    return 0;
  }
  if (start > 1) {
    return sumNumRange(1, finish) - sumNumRange(1, start - 1);
  }
  if (finish % 2 == 1L) {
    return sumNumRange(1, finish - 1) + finish;
  } else {
    return finish * (finish + 1) / 2;
  }
}
vector<CompressedLetter> processCompressedStr(const string &str) {
  vector<CompressedLetter> res;
  long long pos = 0;
  while (pos < str.length()) {
    long long numLength = 0;
    while ('0' <= str[pos] && str[pos] <= '9') {
      numLength++;
      pos++;
    }
    if (numLength == 0) {
      res.push_back({1, str[pos]});
    } else {
      res.push_back({stoi(str.substr(pos, numLength)), str[pos + numLength]});
    }
    pos += numLength + 1;
  }
  return res;
}
long long calcNumLength(long long n) {
  long long res = 0;
  while (n > 0) {
    n /= 10;
    res++;
  }
  return res;
}
