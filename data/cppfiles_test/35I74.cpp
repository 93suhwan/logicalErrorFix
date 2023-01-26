#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ull = unsigned long long;

#define endl '\n'
#define ALL(c) begin(c), end(c)
#define cint(...) int __VA_ARGS__; [](auto&...x){(cin>>...>>x);}(__VA_ARGS__);

int const maxn = 1e6 + 5;
int a[maxn];
int prime[maxn];
int L[maxn];
vector<int> pos[maxn];

inline void add(int x, int l) {
    L[l] = l;
    while (x > 1) {
        pos[prime[x]].push_back(l);
        x /= prime[x];
    }
}

inline void del(int x, int l) {
    if (x == 1) {
        L[l] = l;
        return;
    }
    while (x > 1) {
        if ((int) pos[prime[x]].size() == 0) {
            L[l] = 0;
            return;
        }
        L[l] = min(L[l], pos[prime[x]].back());
        pos[prime[x]].pop_back();
        x /= prime[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cint(n)
    for (auto i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (auto i = 2; i < maxn; i++) {
        if (prime[i] == 0) {
            prime[i] = i;
            if (i > 1000) continue;
            for (auto j = i * i; j < maxn; j += i) {
                prime[j] = i;
            }
        }
    }

    char type;
    for (auto i = 1; i <= n; i++)
    {
        cin >> type;
        if (type == '*') add(a[i], i);
        else del(a[i], i);
    }

    ll answer = 0;
    vector<pi> f;
    for (auto i = n; i >= 1; i--)
    {
        int cnt = 1;
        while ((int) f.size() > 0 && f.back().first >= L[i])
        {
            cnt += f.back().second;
            f.pop_back();
        }
        f.push_back({L[i], cnt});
        if (L[i] == i) answer += (ll)cnt;
    }
    cout << answer;
}
