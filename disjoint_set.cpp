#include <bits/stdc++.h>

#define SIZE 10

using namespace std;
int parent[SIZE], len[SIZE];

void make_set(int v) {
    parent[v] = v; 
    len[v] = 1;
} 

int find_set(int v) {
    if (v == parent[v])
        return v;     
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (len[a] < len[b])
            swap(a, b);
        parent[b] = a;
        len[a] += len[b];    
    }
}


int main(){
    for (int i = 0; i < SIZE; i++){
         make_set(i);
    }
    
    union_sets(1, 2);
    union_sets(2, 5);
    union_sets(5, 3);
    union_sets(7, 4);

    cout << "\nPrinting...\n";
    for (auto x: parent)
        cout << x << " ";
    cout << endl;
}
