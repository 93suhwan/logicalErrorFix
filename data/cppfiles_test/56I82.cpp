#ifndef __GNUG__
#error "Not compiled by a GNU C++ compiler"
#elif __cplusplus < 201103L
#error "C++ standard is older than C++11"
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

// ================ Common initialization for competitive programming
inline void cp_init(const char* redirect_input = nullptr, const char* redirect_output = "") {
    static_assert(numeric_limits<unsigned int>::digits >= 32, "unsigned int is less than 32 bits");
    static_assert(numeric_limits<long double>::radix == 2, "long double radix is not 2");
    static_assert(numeric_limits<long double>::digits >= 64, "long double is not extended precision");

    if (redirect_input != nullptr)
        freopen(*redirect_input == 0 ? "input.txt" : redirect_input, "r", stdin);
    if (redirect_output != nullptr && (*redirect_output != 0 || redirect_input != nullptr))
        freopen(*redirect_output == 0 ? "output.txt" : redirect_output, "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ============== Custom randomized hash function

// https://codeforces.com/blog/entry/60445
static const unsigned long long randseed = (unsigned long long) (new char) ^ (unsigned long long) chrono::steady_clock::now().time_since_epoch().count();

template <class Type>
struct randhash {
    size_t operator()(const Type& key) const noexcept {
        // https://codeforces.com/blog/entry/62393
        unsigned long long result = get_hash(key, is_integral<Type>()) + randseed + 0x9e3779b97f4a7c15;
        result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
        result = (result ^ (result >> 27)) * 0x94d049bb133111eb;
        return result ^ (result >> 31);
    }

private:
    static unsigned long long get_hash(Type key, true_type) { return (unsigned long long) key; }
    static unsigned long long get_hash(Type key, false_type) {
        static const hash<Type> hash_instance;
        return hash_instance(key);
    }
};

// ============== Shortcuts for policy-based data structures
// For docs, refer to https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/ and
// https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures.html
// Thanks to https://codeforces.com/blog/entry/11080,
// https://usaco.guide/gold/faster-hashmap?lang=cpp, and
// https://codeforces.com/blog/entry/60737 for introduction

template <class Type, class Compare = less<Type>>
using pqueue = __gnu_pbds::priority_queue<Type, Compare>; // https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/priority_queue.html

template <class Key, class Value, class Hash = randhash<Key>>
using umap = __gnu_pbds::gp_hash_table<
        Key, Value, Hash,
        equal_to<Key>,
        __gnu_pbds::direct_mask_range_hashing<>,
        __gnu_pbds::linear_probe_fn<>,
        __gnu_pbds::hash_standard_resize_policy<__gnu_pbds::hash_exponential_size_policy<>, __gnu_pbds::hash_load_check_resize_trigger<>, true>
>; // https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/gp_hash_table.html
template <class Key, class Value, class Compare = less<Key>>
using omap = __gnu_pbds::tree<
        Key, Value, Compare,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update
>;  // https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree.html,
// https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree_order_statistics_node_update.html

// In order to turn umap/omap into uset/oset, let Value = null_type
using null_type = __gnu_pbds::null_type;

// ============== Unsigned long long bitmasks

char GetBitMaskBuffer_[65];
unsigned int BitmaskEffectiveLength_ = 64;
#define getmask(mask) ( cin >> GetBitMaskBuffer_, (mask) = strtoull(GetBitMaskBuffer_, nullptr, 2) )
#define popcount(mask) __builtin_popcountll(mask)   // the number of 1-bits in mask
#define countms0(mask) (__builtin_clzll(mask) + BitmaskEffectiveLength_ - 64)  // the number of MS 0-bits (undefined if mask == 0)
#define countls0(mask) __builtin_ctzll(mask)  // the number of LS 0-bits (undefined if mask == 0)

// ============== Shortcut type aliases

using ull = unsigned long long;
using lli = long long;
using ldbl = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vs = vector<string>;

// ============== Shortcut loops

#define forab(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define forba(i, b, a) for (int (i) = (b); (i) >= (a); (i)--)
#define forn(i, n) for (int (i) = 0; (i) < (n); (i)++)

// ============== Competitive programming shortcuts

unsigned int TextCaseNumber_, TestCaseCounter_;
#define TC for (cin >> TextCaseNumber_, TestCaseCounter_ = 0; TestCaseCounter_ < TextCaseNumber_; TestCaseCounter_++)
const double PI = 2.0 * acos(0.0);
#define lf << '\n'
#define spc << ' '
#define casen << "Case #" << TestCaseCounter_ + 1 << ": "

// __________________________________________________________________
// ==================== END OF LIBRARY CODE =========================


// Constants & types
const ull MOD = ull(1e9) + 7ull;

// Global vars
int k, n;
map<ull, char> setcol;
char incol[10], convcol;
ull invert;
ull subtr[70];

// Auxiliary functions & macros
vector<ull> proc(ull v) {
    auto it = setcol.find(v);
    if (it == setcol.end()) return vector<ull>(6, subtr[countms0(v)]);

    vector<ull> result(6, 0ull);
    if ((1 << (k - 1)) & v) {
        result[it->second] = 1;
        return result;
    }

    auto procl = proc(v << 1);
    auto procr = proc((v << 1) | 1);

    forn(i, 6) {
        if (it->second != -1 && i != it->second) continue;

        ull resl = 0, resr = 0;

        forn(j, 6)
            if ((i & ~1) != (j & ~1)) {
                resl = (resl + procl[j]) % MOD;
                resr = (resr + procr[j]) % MOD;
            }

        result[i] = (resl * resr) % MOD;
    }

    return result;
}

int main() {
    cp_init();
    cin >> k >> n;
    BitmaskEffectiveLength_ = k;
    forn(i, n) {
        cin >> invert >> incol;
        switch(incol[0]) {
            case 'w': convcol = 0; break;
            case 'y': convcol = 1; break;
            case 'g': convcol = 2; break;
            case 'b': convcol = 3; break;
            case 'r': convcol = 4; break;
            case 'o': convcol = 5; break;
        }
        setcol[invert] = convcol;

        for (invert >>= 1; invert; invert >>= 1)
            if (!setcol.insert({invert, -1}).second) break;
    }

    subtr[0] = 1;
    forab(i, 1, k - 1)
        subtr[i] = (16ull * subtr[i - 1] * subtr[i - 1]) % MOD;

    auto result = proc(1);
    cout << accumulate(result.begin(), result.end(), 0ull) % MOD lf;
}
