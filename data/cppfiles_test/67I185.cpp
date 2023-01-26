#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PB push_back
#define POP pop_back
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= (int)b; i--)
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define endl "\n"
#endif

using namespace std;
using namespace chrono;

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using ld = long double;
using ull = unsigned long long;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
using max_heap = priority_queue<T>;

const int INF = 1e9;
const long long LLINF = 1e18;
const long long MOD = 1e9 + 7;

long long mod(long long x, long long m = MOD) {
    long long t = x % m;
    return t >= 0 ? t : t + m;
}

long long sq(long long x) { return x * x; }

template <class T>
int sign(T x) {
    return (x > 0) - (x < 0);
}

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#ifdef LOCAL
#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_PREFIX string("[") + FILENAME + ":" + to_string(__LINE__) + "]: "
#define LOG_MSG(s) cout << LOG_PREFIX << s << endl
#define LOG1(x) cout << LOG_PREFIX << #x << " = " << x << endl
#define LOG2(x, y) cout << LOG_PREFIX << #x << " = " << x << ", " << #y << " = " << y << endl
#define LOG3(x, y, z) cout << LOG_PREFIX << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define LOG4(x, y, z, w) cout << LOG_PREFIX << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl
#else
#define LOG_MSG(s)
#define LOG1(x)
#define LOG2(x, y)
#define LOG3(x, y, z)
#define LOG4(x, y, z, w)
#endif

#define GET_LOG_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define LOG(...) GET_LOG_MACRO(__VA_ARGS__, LOG4, LOG3, LOG2, LOG1)(__VA_ARGS__)

template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    return is >> p.first >> p.second;
}

template <class T, class Allocator>
istream& operator>>(istream& is, vector<T, Allocator>& v) {
    for (auto& elem : v) is >> elem;
    return is;
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T1>
ostream& operator<<(ostream& os, const tuple<T1>& t) {
    return os << "(" << get<0>(t) << ")";
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const tuple<T1, T2>& t) {
    return os << "(" << get<0>(t) << ", " << get<1>(t) << ")";
}

template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3>& t) {
    return os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
}

template <class T1, class T2, class T3, class T4>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3, T4>& t) {
    return os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << ")";
}

template <class T, class Allocator>
ostream& operator<<(ostream& os, const vector<T, Allocator>& v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class Key, class Compare, class Allocator>
ostream& operator<<(ostream& os, const set<Key, Compare, Allocator>& s) {
    os << "{";
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template <class Key, class T, class Compare, class Allocator>
ostream& operator<<(ostream& os, const map<Key, T, Compare, Allocator>& m) {
    os << "{";
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it != m.begin()) os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <class Key, class Hash, class KeyEqual, class Allocator>
ostream& operator<<(ostream& os, const unordered_set<Key, Hash, KeyEqual, Allocator>& us) {
    os << "{";
    for (auto it = us.begin(); it != us.end(); it++) {
        if (it != us.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template <class Key, class T, class Hash, class KeyEqual, class Allocator>
ostream& operator<<(ostream& os, const unordered_map<Key, T, Hash, KeyEqual, Allocator>& um) {
    os << "{";
    for (auto it = um.begin(); it != um.end(); it++) {
        if (it != um.begin()) os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <class T, class Container>
ostream& operator<<(ostream& os, stack<T, Container> s) {
    vector<T> vector;
    for (; !s.empty(); s.pop()) vector.push_back(s.top());
    os << "[";
    for (auto it = vector.rbegin(); it != vector.rend(); it++) {
        if (it != vector.rbegin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template <class T, class Container>
ostream& operator<<(ostream& os, queue<T, Container> q) {
    os << "[";
    for (; !q.empty(); q.pop()) {
        os << q.front();
        if (q.size() > 1) os << ", ";
    }
    return os << "]";
}

template <class T, class Allocator>
ostream& operator<<(ostream& os, const deque<T, Allocator>& dq) {
    os << "[";
    for (auto it = dq.begin(); it != dq.end(); it++) {
        if (it != dq.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template <class T, class Container, class Compare>
ostream& operator<<(ostream& os, priority_queue<T, Container, Compare> pq) {
    os << "[";
    for (; !pq.empty(); pq.pop()) {
        os << pq.top();
        if (pq.size() > 1) os << ", ";
    }
    return os << "]";
}

#ifdef LOCAL
#define TIME(name) ScopedTimer name(LOG_PREFIX, #name)
#else
#define TIME(name)
#endif

class ScopedTimer {
  public:
    ScopedTimer(const string& prefix, const string& name) : prefix_(prefix), name_(name), start_(steady_clock::now()) {}

    ~ScopedTimer() {
        const duration<float, milli> dur = steady_clock::now() - start_;
        cout << prefix_ << name_ << " " << dur.count() << " ms" << endl;
    }

  private:
    string prefix_;
    string name_;
    steady_clock::time_point start_;
};

namespace rng {

random_device rd;
mt19937_64 mt(rd());

template <class T>
T get(T low, T high) {
    uniform_int_distribution<T> dist(low, high);
    return dist(mt);
}

template <>
float get(float low, float high) {
    uniform_real_distribution<float> dist(low, high);
    return dist(mt);
}

template <>
double get(double low, double high) {
    uniform_real_distribution<double> dist(low, high);
    return dist(mt);
}

template <class T>
T get() {
    return get<T>(0, numeric_limits<T>::max());
}

}  // namespace rng

#define USE_GNU_PBDS
#ifdef USE_GNU_PBDS
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename Key>
using ordered_set = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key, typename Mapped>
using ordered_map = tree<Key, Mapped, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key>
using hash_set = gp_hash_table<Key, null_type, CustomHash>;

template <typename Key, typename Mapped>
using hash_map = gp_hash_table<Key, Mapped, CustomHash>;

template <typename Key, typename Mapped, typename Cmp_Fn, typename Tag, template <typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_> class Node_Update, typename Allocator>
ostream& operator<<(ostream& os, const tree<Key, Mapped, Cmp_Fn, Tag, Node_Update, Allocator>& t) {
    os << "{";
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (it != t.begin()) os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename Key, typename Cmp_Fn, typename Tag, template <typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_> class Node_Update, typename Allocator>
ostream& operator<<(ostream& os, const tree<Key, null_type, Cmp_Fn, Tag, Node_Update, Allocator>& t) {
    os << "{";
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (it != t.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template <typename Key, typename Mapped, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn, typename Resize_Policy, bool Store_Hash, typename Allocator>
ostream& operator<<(ostream& os, const gp_hash_table<Key, Mapped, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, Store_Hash, Allocator>& gp) {
    os << "{";
    for (auto it = gp.begin(); it != gp.end(); ++it) {
        if (it != gp.begin()) os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename Key, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn, typename Resize_Policy, bool Store_Hash, typename Allocator>
ostream& operator<<(ostream& os, const gp_hash_table<Key, null_type, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, Store_Hash, Allocator>& gp) {
    os << "{";
    for (auto it = gp.begin(); it != gp.end(); ++it) {
        if (it != gp.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

#endif

int main(int argc, char* argv[]) {
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    TIME(main_time);
    int ts;
    cin >> ts;
    while(ts--){    
        int a, b, c;
        cin >> a >> b >> c;
        int d = max(a,b) - min(a,b);
        if(d == 1){
            if((a == 1 || a == 2) && (b == 1 || b == 2)){
                if(c == 1){
                    cout << 2 << endl;
                }
                else if(c == 2){
                    cout << 1 << endl;
                }
            }
            else{
                cout << -1 << endl;
            }
        }
        else if(d == 0){
            cout << -1 << endl;
        }
        else{
            d *= 2;
            if(c > d || a > d || b > d){
                cout << -1 << endl;
            }
            else{
                if(c+d/2 <= d){
                    cout << c+d/2 << endl;
                }
                else{
                    cout << c-d/2 << endl;
                }
            }
        }           
    }
}



