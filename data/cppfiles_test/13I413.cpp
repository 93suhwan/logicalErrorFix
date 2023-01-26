#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll; 
#define int ll 
#define uni(a) a.resize(distance(a.begin(),unique(a.begin(),a.end())));
#define sz(a) ((int)a.size())
#define all(x) x.begin(),x.end()
#define rank(s,val) s.order_of_key(val)
#define ksmall(s,k) *s.find_by_order(k)
#define PI 3.14159265358979323846264338327950288

typedef pair<int,int> pi;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_setPair;         
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;

template<typename T> void max_self(T &a, T b) { a = max(a,b); return; }
template<typename T> void min_self(T &a, T b) { a = min(a,b); return; }

// a + b = a ^ b + 2 * (a & b); 

const int nax = 200200;
const int smod = 1e9 + 9;
const int linf = 2e18 + 1e9 + 500;
const int MOD = 998244353;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < sz(v); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first; return cin >> p.second;
}
template<typename A, typename B> ostream& operator<<(ostream& cout, pair<A, B> &p) {
    cout << "[" << p.first << " " << p.second; return cout << "]";
}

// for ordered_mutliset delete operation(x), use s.erase(s.lower_bound(x - 1));
// This is because lower_bound acts as upper bound due to less_equal<int>

char ans[105][105];
int n,m;
char getCharacter(int flag,int i,int j){
    vector<char> coll = {'a','b','c','d','e','f','g','h','i','j'};
    set<char> st;
    if(flag == 0){
        if(i > 0){
            st.insert(ans[i - 1][j]);
            st.insert(ans[i - 1][j + 1]);
        }
        if(i + 1 < n){
            st.insert(ans[i + 1][j]);
            st.insert(ans[i + 1][j + 1]);                                
        }
        if(j > 0){
            st.insert(ans[i][j - 1]);
        }
        if(j + 1 < m){
            st.insert(ans[i][j + 1]);
        }                            
        char fin = 'a';
        for(char &c: coll){
            if(st.find(c) != st.end()){
                fin = c;
                break;
            }
        }
        return fin;
    }
    else{
        vector<char> coll = {'a','b','c','d','e','f','g','h','i','j'};
        set<char> st;
        if(i > 0){
            st.insert(ans[i - 1][j]);
        }
        if(i + 1 < n){
            st.insert(ans[i + 1][j]);
        }
        if(j > 0){
            st.insert(ans[i][j - 1]);
            st.insert(ans[i + 1][j - 1]);
        }
        if(j + 1 < m){
            st.insert(ans[i][j + 1]);
            st.insert(ans[i + 1][j + 1]);                                    
        }                            
        char fin = 'a';
        for(char &c: coll){
            if(st.find(c) != st.end()){
                fin = c;
                break;
            }
        }        
        return fin;
    }
}

signed main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_cases = 1;
    cin >> test_cases;  
    for(int test_case = 1; test_case <= test_cases; ++test_case){
        int k;
        cin >> n >> m >> k;

        int total = (n * m) / 2;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) ans[i][j] = '#';

        if(((n % 2) == 0) && ((m % 2) == 0)){
            if((k % 2 == 0)){
                cout << "YES\n";
                int left = total - k;
                int row = 0,col = 0;
                for(int i = 0; i < left; i += 2){
                    char fin = getCharacter(1,row,col);
                    ans[row][col] = ans[row + 1][col] = fin;
                    fin = getCharacter(1,row,m - 1 - col);
                    ans[row][m - 1 - col] = ans[row + 1][m - 1 - col] = fin;
                    row += 2;
                    if(row == n){
                        row = 0;
                        col += 1;
                    } 
                }
                for(int i = 0; i < n; ++i){
                    for(int j = 0; j < m; ++j){
                        if(ans[i][j] == '#'){
                            char fin = getCharacter(0,i,j);
                            ans[i][j] = ans[i][j + 1] = fin;                      
                        }
                    }
                }
            }
            else{
                cout << "NO\n";
                    continue;
            }
        }
        else if(n & 1){
            if(k < (m / 2)){
                cout << "NO\n";
                continue;
            }
            m /= 2;
            if(m & 1){
                if(k & 1){
                    cout << "YES\n";
                    int left = total - k;
                    int row = 0,col = 0;
                    for(int i = 0; i < left; i++){
                        char fin = getCharacter(1,row,col);
                        ans[row][col] = ans[row + 1][col] = fin;
                        col += 1;
                        if(col == m){
                            row += 2;
                            col = 0;
                        }
                    }
                    for(int i = 0; i < n; ++i){
                        for(int j = 0; j < m; ++j){
                            if(ans[i][j] == '#'){
                                char fin = getCharacter(0,i,j);
                                ans[i][j] = ans[i][j + 1] = fin;                      
                            }
                        }
                    }                    
                }
                else{
                    cout << "NO\n";
                    continue;
                }
            }
            else{
                if(k & 1){
                    cout << "NO\n";
                    continue;
                }
                else{
                    cout << "YES\n";
                    int left = total - k;
                    int row = 0,col = 0;
                    for(int i = 0; i < left; i++){
                        char fin = getCharacter(1,row,col);
                        ans[row][col] = ans[row + 1][col] = fin;
                        col += 1;
                        if(col == m){
                            row += 2;
                            col = 0;
                        }
                    }
                    for(int i = 0; i < n; ++i){
                        for(int j = 0; j < m; ++j){
                            if(ans[i][j] == '#'){
                                char fin = getCharacter(0,i,j);
                                ans[i][j] = ans[i][j + 1] = fin;                      
                            }
                        }
                    }                                        
                }
            }
        }
        else if(m & 1){
            int maxi = (n * (m - 1)) / 2;
            if(k > maxi){
                cout << "NO\n";
                continue;
            }
            n /= 2;
            if(n & 1){
                if(k & 1){
                    cout << "NO\n";
                    continue;
                }
                else{
                    cout << "YES\n";
                    int left = total - k;
                    int row = 0,col = m - 1;
                    int flag = 0;
                    for(int i = 0; i < left; i++){
                        if(flag == 0){
                            char fin = getCharacter(1,row,col);                            
                            ans[row][col] = ans[row + 1][col] = fin;                            
                            row += 2;
                            if(row == n){
                                row = n - 1;
                                col = m - 2;
                                flag = 1;
                            }
                        }
                        else{
                            char fin = getCharacter(1,row,col);
                            ans[row][col] = ans[row  - 1][col] = fin;
                            col -= 1;
                            if(col == 0){
                                row -= 1;
                                col = m - 2;
                            }
                        }
                    }
                    for(int i = 0; i < n; ++i){
                        for(int j = 0; j < m; ++j){
                            if(ans[i][j] == '#'){
                                char fin = getCharacter(0,i,j);
                                ans[i][j] = ans[i][j + 1] = fin;                      
                            }
                        }
                    }                    
                }
            }
            else{
                if(k & 1){
                    cout << "NO\n";
                    continue;
                }
                else{
                    cout << "YES\n";
                    int left = total - k;
                    int row = 0,col = m - 1;
                    int flag = 0;
                    for(int i = 0; i < left; i++){
                        if(flag == 0){
                            char fin = getCharacter(1,row,col);                            
                            ans[row][col] = ans[row + 1][col] = fin;                            
                            row += 2;
                            if(row == n){
                                row = n - 1;
                                col = m - 2;
                                flag = 1;
                            }
                        }
                        else{
                            char fin = getCharacter(1,row,col);
                            ans[row][col] = ans[row  - 1][col] = fin;
                            col -= 1;
                            if(col == 0){
                                row -= 1;
                                col = m - 2;
                            }
                        }
                    }
                    for(int i = 0; i < n; ++i){
                        for(int j = 0; j < m; ++j){
                            if(ans[i][j] == '#'){
                                char fin = getCharacter(0,i,j);
                                ans[i][j] = ans[i][j + 1] = fin;                      
                            }
                        }
                    }                    
                }                    
            }
        }
        else{
            cout << "NO\n";
            continue;
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}