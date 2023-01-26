#include "bits/stdc++.h"
using namespace std;
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// typedef tree<
// pi,
// null_type,
// less<pi>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;


//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

#define int long long
#define endl "\n"
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sortv(x) sort(x.begin(),x.end())
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define rep(i,a,n) for(int i =a;i<n;i++)






// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// compartor to store set in reverse order
struct classcomp {

  bool operator() (const int& lhs, const int& rhs) const

  {return lhs>rhs;}

};

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}





// to store data in map 

// struct comp {

//   bool operator() (const pair<int,int> &v1, const pair<int ,int> &v2) const
//   {

//   if(v1.ss==v2.ss){
//       return v1.ff<v2.ff;
//   }
//   return v1.ss>v2.ss;

// };


// dsu
// void make(int a,vi &size,vi &parent){
//   size[a] = 1;
//   parent[a]=a;
// }


// int find(int a,vi &size,vi &parent){
//     if(parent[a]==a ){
//       return a;
//     }
   

//     return parent[a]=find(parent[a],size,parent);

// }

// void makeunion(int a,int b, vi &size,vi &parent){
//     int  u  = find(a,size,parent);
//     int  v  = find(b,size,parent);

//     if(a==b){
//         return;
//     }
//     if(size[u]<size[v]){
//     swap(u,v);

//     }
//     // if(size[u]==size[v]){
//     //    size[u]++;
//     // }
    
//     parent[v]=u;
//     size[u]+=size[v];

// }





int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int lcm(int a, int b)
{
  int g = __gcd(a, b);
  return a / g * b;
}


int sumofdigits(int num){
    return 1 + (num - 1) % 9;
}



void solve(){
           int n;
       cin>>n;
    //    int array[n];
     vector<int> arr (n);
     vector<int> vis(n,0);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       int ans =1;
        bool curr =1;
       for(int i=0;i<n-1;i++){
        if(arr[i]==0 && arr[i+1]==0 ){
            cout<<-1<<endl;
            return;
        }
        else if(arr[i]==1 && arr[i+1]==1 && curr ==1){
            curr =0;
            vis[i]=1 ;
            vis[i+1]=1 ;
            ans+=6;
            continue;
            // i++;
        }
        else if(arr[i]==1 && arr[i+1]==1 && curr ==0){
            // curr =0;
            // cout<<"b";
            vis[i]=1 ;
            vis[i+1]=1 ;
            ans+=5;
            continue;
            // i++;
        }
        else if(arr[i]==1){
            vis[i]=1 ;
            ans++;
        }
        curr  =1;
       }

       if(vis[n-1]==0 && arr[n-1]==1){
           ans++;
        //    cout<<"a";
       }

       cout<<ans<<endl;
}


int32_t main(){

     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      
        solve();

       




    }


    return 0;
}
