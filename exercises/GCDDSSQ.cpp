#include <bits/stdc++.h>

const int MAX_N = 100'005;
const int LOG = 17;

int a[MAX_N];
int m[MAX_N][LOG] = {0};
int c[MAX_N] = {0};

using namespace std;
void make_sparse_table(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[i][0] = a[i];
        c[a[i]]++;
    }
    for(int k = 1; k < LOG; k++){
        for(int i = 0; i + (1<<k) - 1 < n; i++){
            m[i][k] = __gcd(m[i][k-1],m[i+(1<<(k-1))][k-1]);
            c[m[i][k]]++;
        }
    }
}

int query_sparse_table(int L, int R){
    int len = R - L + 1;
    int k = 0;
    // find the log
    k = 31 - __builtin_clz(len);
    //while((1<<(k+1)) <= len) k++;
    return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main(){
    make_sparse_table();
    int q, z;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> z;
        cout << c[z]<< endl;
    }
    return 0;
}
