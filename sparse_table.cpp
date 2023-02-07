#include <bits/stdc++.h>

const int MAX_N = 100'005;
const int LOG = 17;

int a[MAX_N];
int m[MAX_N][LOG] = {0};

using namespace std;
void make_sparse_table(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    for(int k = 1; k < LOG; k++){
        for(int i = 0; i + (1<<k) - 1 < n; i++){
            m[i][k] = min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
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
    int q, L, R;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> L >> R;
        cout << query_sparse_table(L, R) << endl;
    }
    return 0;
}
