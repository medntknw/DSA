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
 

void merge(int *arr, int l, int mid, int r){
    int szl = mid-l+1;
    int szr = r-mid;
    int L[szl], R[szr];
    int j=0;
    for(int i=l;i<=mid;i++, j++){
        L[j] = arr[i];
    }
    j=0;
    for(int i=mid+1;i<=r;i++, j++){
        R[j] = arr[i];
    }
    j=0;
    int i=0,k=l;
    while(i<szl && j<szr){
        if(L[i]>=R[j]){
            arr[k++]=R[j++];
        }
        else{
            arr[k++]=L[i++];
        }
    }
    while(i<szl){
        arr[k++]=L[i++];
    }
    while(j<szr){
        arr[k++]=R[j++];
    }
}
void merge_sort(int *arr, int l, int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("/Users/morph/Desktop/DSA/c++/input.txt", "r", stdin);
        freopen("/Users/morph/Desktop/DSA/c++/output.txt", "w", stdout);
    #endif
    fast_cin();
    solve();
    return 0;
}