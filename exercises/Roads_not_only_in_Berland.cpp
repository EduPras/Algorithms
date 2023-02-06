#include <bits/stdc++.h>
// https://codeforces.com/contest/25/problem/D

using namespace std;

int parent[1000], len[1000];
int counter = 0;
queue<pair<pair<int, int>, int>> deleted;

void make_set(int v) {
    parent[v] = v; 
    len[v] = 1;
} 

int find_set(int v) {
    if (v == parent[v])
        return v;     
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
    if (a == b ){
        counter ++;
        deleted.push({{x, y}, a});
    }
    if (a != b) {
        if (len[a] < len[b])
            swap(a, b);
        parent[b] = a;
        len[a] += len[b];    
    }
}



int main(){
    int n, a, b, sz;
    cin >> n;
    for (int i = 1; i <= n; i++)
        make_set(i);

    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        union_sets(a, b);
    }
    
    sz = deleted.size();
    cout << sz << endl;
    if (sz){
        for(int i = 2; i <= n; i++){
            int x = find_set(i);
            int y = find_set(i-1);
            if(x != y){
                union_sets(x, y);
                pair<pair<int, int>, int> rmv = deleted.front();
                deleted.pop();
                cout << rmv.first.first << " " << rmv.first.second << " " << x << " " << y << endl;
            }
        }
    }

    return 0;
}
