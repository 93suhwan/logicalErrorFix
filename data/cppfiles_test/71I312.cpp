#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int           long long int
#define umapii        unordered_map<int,int>
#define ps(x,y)       fixed<<setprecision(y)<<x // sets precision upto required digits
#define arr(a,n)      vector<int>a(n);for(int i=0;i<n;i++){cin>>a[i];}
#define outarr(a,n)   for(int i=0;i<n;i++){cout<<a[i]<<' ';}
#define mod           1000000007
#define ff            first
#define MaxLimit      1e17
#define MinLimit      -1e17 
#define all(v)        v.begin(),v.end()
#define ss            second
#define add           push_back
#define remove        pop_back
#define mapii         map<int,int>
#define large         *max_element
#define small         *min_element
#define pqi           priority_queue<int>
#define mpqi          priority_queue<int,vector<int>,greater<int>>
#define in(n)         int n;cin>>n;
#define w(t)          int t;cin>>t;while(t--)
#define vi            vector<int>
#define vivi          vector<vector<int>>
#define bpc           __builtin_popcount
#define bpcll         __builtin_popcountll
#define pii           pair<int,int>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;

int recpow(int a, int b) {if (b == 0)return 1; int x = recpow(a, b / 2); if (b & 1)return a * x * x; return x * x;}
int binpow(int a, int b, int m) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
int gcd(int a, int b) {return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b) {return a * b / gcd(a, b);}
int inv(int b, int m) {return binpow(b, m - 2, m);}
int madd(int a, int b, int m) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
int msub(int a, int b, int m) {a %= m; b %= m; return (((a - b) % m) + m) % m;}
int mmul(int a, int b, int m) {a %= m; b %= m; return (((a * b) % m) + m) % m;}
int mdiv(int a, int b, int m) {a %= m; b %= m; return (mmul(a, inv(b, m), m) + m) % m;}
int ncr(int n, int r, int fac[], int m) {if (r > n) return 0; if (r == n) return 1; return (fac[n] % m * ((binpow(fac[n - r], m - 2, m) % m * binpow(fac[r], m - 2, m) % m) % m) % m) % m;}


string fun(string s){
    int val = s[0]-'0'; 
    string temp(s.size(),val+48);
    val++;
    string temp2(s.size(),val+48);
    if(temp>=s){
        return temp; 
    }else{
        return temp2;
    }
}

void solve() {
    in(n);in(k);
    string s = to_string(n);
    if(s.size()==1){
        cout<<n<<endl;
        return;
    }
    unordered_map<char,int> mp;
    for(auto c:s) mp[c]++;
    if(k==1){
        cout<<fun(s)<<endl;
    }else{
        if(mp.size()==1){
            cout<<n+1<<endl;
        }else if(mp.size()==2){
            cout<<n<<endl;
        }else{
            int x = s[0]-'0';
            int index;
            for(int i=1;i<s.size();i++){
                if(s[i]-'0'!=x){
                    index = i;
                    break;
                }
            }
            if(s[index]-'0'<x){
                string s12 = s;
                string s21 = s;
                for(int i=index;i<s.size();i++){
                    s12[i] = s[index];
                }
                if(s12>=s){
                    
                    cout<<s12<<endl;
                    return;
                }
                s21[index] = x+48;
                for(int i=index+1;i<s.size();i++){
                    s21[i] = '0';
                }
                cout<<s21<<endl;
                return;
            }
            int tempInd = index;
            string t = fun(s.substr(index));
            int ind = -1;
            for(int i=0;i<t.size();i++){
                if(t[i]>s[index]){
                    ind = i;
                    break;
                }
                index++;
            }
            if(ind!=-1 and x<t[0]){
                for(int i=ind+1;i<t.size();i++){
                    t[i] = x+48;
                }
            }
            cout<<s.substr(0,tempInd)<<t<<"\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

w(t){
    solve();
}

    return 0;
}
