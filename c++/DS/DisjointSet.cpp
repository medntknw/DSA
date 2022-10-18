#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int parent[100005];
int ranks[100005];

void initialize(int n){
    for(int i=0;i<=n;i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}
int findParent(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}
void unioN(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if(ranks[px]<ranks[py]){
        parent[px] = py;
    }
    else if(ranks[px]>ranks[py]){
        parent[py] = px;
    }
    else{
        parent[py] = px;
        ranks[px]++;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    initialize(n);
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back({w,{a,b}});
    }
    sort(v.begin(), v.end());
    int cost = 0;
    for(auto x: v){
        int a = x.second.first;
        int b = x.second.second;
        if(findParent(a) != findParent(b)){
            cost += x.first;
            unioN(a,b);
        }
    }
    cout<<cost<<endl;
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fast_cin();
    solve();
    return 0;
}