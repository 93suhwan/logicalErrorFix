/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    WELCOME
***************************************************************************
                  .-"      "-.
                 /            \
                |              |
                |,  .-.  .-.  ,|
                | )(__/  \__)( |
                |/     /\     \|
      (@_       (_     ^^     _)
 _     ) \_______\__|IIIIII|__/__________________________
(_)@8@8{}<________|-\IIIIII/-|___________________________>
       )_/        \          /
      (@           `--------`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    MADRIS  IIT PATNA
 
**********************************************************************
*/
 
#include<bits/stdc++.h>
using namespace std;
#define vect vector<int>
#define lli long long int
#define mp make_pair
#define mod 1000000007
#define pb push_back
#define forr(i,n) for(int i=0;i<n;i++)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

lli lcm (lli a, lli b) {return ((a*b)/__gcd(a,b));}
lli modpower (lli a,lli b)
{
    if(b==0) return 1;
    lli c=modpower(a,b/2)%mod;
    if (b%2) return (((a*c)%mod)*c)%mod;
    else return (c*c)%mod;
}
lli power (lli a,lli b)
{
    if(b==0) return 1;
    lli c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
bool prime (lli k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    lli a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
lli sieve (int n)
{
    bool qrr[n+1];
    for (int i=0;i<=n;i++)
    qrr[i]=1;qrr[0]=0;qrr[1]=0;
    for (int i=2;i<=n;i++)
    {
        if (qrr[i]==1)
        {
            for (int j=i;j<=n;j+=i)
            {qrr[j]=0;}
        }
    }
    return 0;
}

bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
 
        if (S[i] != S[S.length() - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int KMPprefsuf(string s){
    int n = s.length();
    vector<int> lps(n,0);
    // int lps[n] = {0};
    int i = 1;
    int len = 0;
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps[n-1];
    
}
 
 
 
 
//**************** main code starts below this ********************************//
 
 
 
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return (a.first - a.second) < (b.first - b.second);
    }
};

bool comp(pair<int,int>& a,pair<int,int>& b){
        
        if(a.first == b.first){
            return a.second < b.second;
        }
    
        return a.first > b.first;
        
    
    }

bool cp(pair<lli,lli>& a,pair<lli,lli>& b){
        
        if(a.first == b.first){
            return a.second < b.second;
        }
    
        return a.first > b.first;
        
    
    }

bool comp1(pair<int,int>& a,pair<int,int>& b){
        
        
    
        return a.second < b.second;
        
    
    }


lli getpar(vector<int>& parent, int edga){

    if(parent[edga] != edga ){
        return getpar(parent, parent[edga]);
    }
    else{
        return edga;
    }
}

int search(lli* find, int s, int e, lli key)
{

    int ans = -1;
 

    while (s <= e) {
        int mid = (s + e) / 2;
 
        if (find[mid] - key >= 0) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
 
    return ans;
}

bool issubstr(string a, string b){
    int j = 0;
    for(int i = 0; i < a.size()&& j < b.size(); i++){
        if(a[i] == b[j]){
            j++;
        }
    }
    
    if(j == b.size()){
        return true;
    }
    
    return false;
}


int main() {
    fio
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(n,vector<int>(2));
        forr(i,n){
            forr(j,2){
                cin >> v[i][j];
            }
        }
        
        vector<vector<int>> rg(n,vector<int>(n+1,0));
        vector<int> ans(n);
        ans[n-1] = v[n-1][0];
        for(int i = n-2; i >= 0; i--){
            for(int j=1;j <=n; j++){
                rg[i][j] = rg[i+1][j];
            }
            
            int lef = v[i+1][0];
            int ri = v[i+1][1];
            for(int j = lef; j <= ri; j++){
                rg[i][j] = 1;
            }
            
            lef = v[i][0];
            ri = v[i][1];
            for(int j = lef; j <= ri; j++){
                if(rg[i][j] == 0){
                    ans[i] = j;
                    break;
                }
            }
        }
        
        forr(i,n){
            cout << v[i][0] << " " << v[i][1] << " " << ans[i] << endl;
        }
        
        cout << endl;
        
        
    }
    
}
 
 
 
/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                  BANANA
****************************************************
                      ."`".
              .-./ _=_ \.-.
             {  (,(oYo),) }}
             {{ |   "   |} }
             { { \(---)/  }}
             {{  }'-=-'{ } }
             { { }._:_.{  }}
             {{  } -:- { } }
             {_{ }`===`{  _}
            ((((\)     (/))))
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                SIGNING OFF
********************************************************
 
*/
 
 