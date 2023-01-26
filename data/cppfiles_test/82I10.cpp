#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

template<class T> using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// MACROS_BEGIN
#define CLEAR() cerr << endl;
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for (LET(it, (v).begin()); it != (v).end(); ++it)
#define REPEAT(i, n) for (int i = 0; i < (n); ++i)
// MACROS_END

// GENERIC_UTILITIES_BEGIN
template <class T> inline int rsize(const T& c) {return (int) c.size();}
inline long long two(int x) {return (1LL << (x));}

struct Splitter {
  static int pCounter(string s) {
    int counter = 0;

    for (int i = 0; i < rsize(s); ++i) {
      if (s[i] == '(') ++counter;
      else if (s[i] == ')') --counter;
    }

    return counter;
  }

  static vector<string> intermediateSplit(string s, string delim) {
    s += delim[0];
    string tmp;
    vector<string> result;

    for (int i = 0; i < rsize(s); ++i) {
        if (delim.find(s[i]) == string::npos) {
            tmp.push_back(s[i]);
        }
        else {
            trim(tmp);
            if (tmp != "") result.push_back(tmp);
            tmp.clear();
        }
    }

    return result;
  }

  static void trim(string& s) {
    while (rsize(s) > 0 && s.back() == ' ') {
        s.pop_back();
    }

    while (rsize(s) > 0 && s.front() == ' ') {
        s.erase(s.begin());
    }
  }

  static vector<string> finalSplit(vector<string> intermediate) {
    int iter = 0;
    vector<string> result;

    while (iter < rsize(intermediate)) {
      if (pCounter(intermediate[iter]) != 0) {
        int pending = 0;
        string tmp, separator;

        do {
          tmp += separator + intermediate[iter];
          pending += pCounter(intermediate[iter]);
          separator = ", ";
          ++iter;
        } while (iter < rsize(intermediate) && pending != 0);

        result.push_back(tmp);
      } else {
        result.push_back(intermediate[iter]);
        ++iter;
      }
    }

    return result;
  }

  static vector<string> split(string s, string delim) {
    vector<string> intermediate = intermediateSplit(s, delim);
    // BUG()
    vector<string> output = finalSplit(intermediate);
    return output;
  }
};

// GENERIC_UTILITIES_END

// FAST_IO_BEGIN
// FAST_IO_END

// STANDARD_IO_BEGIN
#ifndef USING_FAST_IO
int readInt() {int N = -1; scanf("%d", &N); return N;}
double readDouble() {double D; scanf("%lf", &D); return D;}
string readString() {char buffer[1 << 20]; scanf("%s", buffer); return buffer;}
long long readLongLong() {long long N = -1; scanf("%lld", &N); return N;}
#endif // NOT DEFINED USING_FAST_IO
// STANDARD_IO_END


// OUTPUT_UTILITIES_BEGIN
template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p);
template <class T> ostream& operator << (ostream& o, const vector<T>& v);
template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m);
template <class T> ostream& operator << (ostream& o, const set<T>& s);
template <class T> ostream& operator << (ostream& o, const multiset<T>& s);
template <class T> ostream& operator << (ostream& o, const OrderedSet<T>& s);
template <class T> ostream& operator << (ostream& o, const queue<T>& q);
template <class T> ostream& operator << (ostream& o, const stack<T>& s);

template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p) {
    o << "(" << p.first << "," << p.second << ")"; return o;
}

template <class T> ostream& operator << (ostream& o, const vector<T>& v) {
    o << "{"; bool first = true; FOREACH(it, v) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m) {
    o << "{"; bool first = true; FOREACH(it, m) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const set<T>& s) {
    o << "{"; bool first = true; FOREACH(it, s) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const multiset<T>& s) {
    o << "{"; bool first = true; FOREACH(it, s) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const OrderedSet<T>& s) {
    o << "{"; bool first = true; FOREACH(it, s) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const queue<T>& q) {
    o << "{"; bool first = true; queue<T> p = q; while (!p.empty()) { if (!first) o << ","; first = false; o << p.front(); p.pop(); } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const stack<T>& s) {
    o << "{"; bool first = true; stack<T> r = s; while (!r.empty()) { if (!first) o << ","; first = false; o << r.top(); r.pop(); } return o << "}";
}
// OUTPUT_UTILITIES_END

// DEBUGGING_UTILITIES_BEGIN
// DEBUGGING SWITCH
#define PHOENIX_DEBUG

#ifdef PHOENIX_DEBUG
#define BUG(...) __f(__LINE__, #__VA_ARGS__, __VA_ARGS__)

template<typename Arg> void __print(const string& name, Arg&& arg) {
    cerr << "\t" << name << ": " << arg << endl;
}

void __printLine(int line) {
    cerr << "LINE " << line << ":" << endl;
    cerr << boolalpha;    
}

template<typename Arg> void __g(vector<string>& names, int idx, Arg&& arg) {
    __print(names[idx], arg);
}

template<typename Arg, typename... Args> void __g(vector<string>& names, int idx, Arg&& arg, Args&&... args) {
    __g(names, idx, arg); __g(names, idx + 1, args...);
}

template <typename Arg> void __f(int line, const string& name, Arg&& arg) {
    __printLine(line);
    __print(name, arg); CLEAR();
}

template <typename Arg, typename... Args> void __f(int line, const string& _names, Arg&& arg, Args&&... args) {
    __printLine(line);
    vector<string> names = Splitter::split(_names, ","); __g(names, 0, arg, args...); CLEAR();
}
#else
#define BUG(...)
#endif
// DEBUGGING_UTILITIES_END

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double epsilon = 1e-8;
const int infinite    = 2000000000; // 2 * 10^9
const long long infiniteLL = 2000000000000000000LL; // 2 * 10^18
const long long modulo = 1000000007;

template<typename T>
struct Node {
    T idx, value;

    Node<T>() {
        // if (typeid(idx) == typeid(int)) {
        //     idx = value = infinite;
        // } else if (typeid(idx) == typeid(long long)) {
            idx = value = infiniteLL;
        // }
    }

    void initialize(T _idx, T _value) {
        idx = _idx;
        value = _value;
    }
};

template <typename T>
struct SegmentTree {
    vector<Node<T>> tree;
    int N;

    void initialize(vector<T>& v) {
        N = rsize(v);
        tree.resize(4 * N);
        recurse(1, 0, N - 1, v);
    }

    void recurse(int node, int b, int e, vector<T>& v) {
        if (b == e) {
            tree[node].initialize(b, v[b]);
        } else {
            int mid = (b + e) / 2;
            int left = (node << 1), right = (node << 1) + 1;
            recurse(left, b, mid, v);
            recurse(right, mid + 1, e, v);
            tree[node] = tree[left].value < tree[right].value ? tree[left] : tree[right];
        }
    }

    Node<T> query(int node, int b, int e, int low, int high) {
        if (b > high || e < low) {
            return Node<T>();
        } else if (b >= low && e <= high) {
            return tree[node];
        } else {
            int mid = (b + e) / 2, left = (node << 1), right = (node << 1) + 1;
            Node<T> n1 = query(left, b, mid, low, high);
            Node<T> n2 = query(right, mid + 1, e, low, high);
            // BUG(b, e, low, high, n1.value, n2.value);
            return n1.value < n2.value ? n1 : n2;
        }
    }

    Node<T> query(int low, int high) {
        if (low > high) {
            return Node<T>();
        }

        return query(1, 0, N - 1, low, high);
    }

    int queryNextIdx(int low, int high, T target) {
        int answer = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            Node<T> n1 = query(low, mid), n2 = query(mid + 1, high);

            if (n1.value < target) {
                answer = mid;
                high = mid - 1;
            } else {
                answer = mid + 1;
                low = mid + 1;
            }
        }

        return answer;
    }
};

struct Task {
    int N, Q, K;
    vector<long long> A, B;
    SegmentTree<long long> tree;
    vector<vector<long long>> C;
    vector<vector<long long>> dp;
    vector<SegmentTree<long long>> dpTree;

    void readInput() {
        N = readInt(), Q = readInt(), K = readInt();
        A.resize(N);

        for (int i = 0; i < N; ++i) {
            A[i] = readInt();
        }
        // BUG(A, K);

        tree.initialize(A);
        B.resize(N);

        for (int i = 0; i < N; ++i) {
            B[i] = tree.query(max(0, i - K), i).value;
            // BUG(max(0, i - K), i, B[i]);
        }
        // BUG(B);

        C.resize(K);
        dp.resize(K);
        dpTree.resize(K);

        for (int i = 0; i < K; ++i) {
            for (int j = i; j < N; j += K) {
                C[i].push_back(B[j]);
            }
        }
        // BUG(C);
    }

    void prefixMinimums() {
        for (int k = 0; k < K; ++k) {
            auto& c = C[k];
            int L = rsize(c);
            vector<int> nxt(L, -1);
            int i = 0, j = 1;

            SegmentTree<long long> T;
            T.initialize(c);
            nxt[L - 1] = -1;

            for (int i = 0; i < L - 1; ++i) {
                if (T.query(i + 1, L - 1).value < c[i]) {
                    nxt[i] = T.queryNextIdx(i + 1, L - 1, c[i]);
                }
            }
            // BUG(nxt);

            dp[k].resize(L);

            for (int i = L - 1; i >= 0; --i) {
                if (nxt[i] != -1) {
                    dp[k][i] = dp[k][nxt[i]] + 1LL * c[i] * (L - i);
                } else {
                    dp[k][i] = 1LL * c[i] * (L - i);
                }
                // BUG(dp[k][i], nxt[i], c[i]);
            }
            // BUG(dp[k]);

            dpTree[k].initialize(dp[k]);
        }
    }

    long long subQuery(int idx, int L, int R) {
        int p = dpTree[idx].query(L, R).idx;
        // BUG(idx, L, R, p, rsize(dp[idx]));
        return dp[idx][L] - dp[idx][p] + 1LL * (R - p + 1) * C[idx][p];
    }

    long long query(int L, int R) {
        // BUG(L, R);
        // L, L + K, L + 2 * K, ..., L + T*K <= R
        // T = (R - L) / K;
        int T = (R - L) / K;
        int b0 = L % K, b1 = L / K;
        // dp[b0][b1]...dp[b0][b1 + T]
        return subQuery(b0, b1, b1 + T);
    }

    // int query(int L, int R) {
    //     int answer = A[L];

    //     for (int i = L + 1; i <= R; ++i) {
    //         answer = min(answer, A[i]);
    //     }

    //     return answer;
    // }

    void solve() {
        prefixMinimums();

        for (int i = 0; i < Q; ++i) {
            int L = readInt() - 1, R = readInt() - 1;
            long long answer = A[L];

            if (L + K <= R) {
                answer += query(L + K, R);
            }

            printf("%lld\n", answer);
        }
    }

    void perform() {
        readInput();
        solve();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Task task;
    task.perform();

    return 0;
}

// Powered by PhoenixAI
