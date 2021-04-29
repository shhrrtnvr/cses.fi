#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

struct matrix {
    const int row=6, col=6, sz=36;
    long long *A;
    matrix(){
        A = new long long[sz];
    }

    matrix(matrix& m) {
        A = new long long[sz];
        for (int i = 0; i < sz; i++) A[i] = m.A[i];
    }
    
    void operator*= (matrix b) {
        assert(col == b.row);
        matrix a;
        for (int i = 0; i < sz; i++) a.A[i] = A[i];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                A[i*col + j] = 0LL;
                for (int k = 0; k < col; k++) {
                    A[i*col + j]  += (1LL * a.A[i*a.col + k] * b.A[k*b.col + j])%MOD;
                    A[i*col + j] %= MOD;
                }
            }
        }
    }

    void make_eye() {
        assert(col == row);
        for (int i = 0; i < row; i++)
                A[i*row+i] = 1;
    }  
};

matrix pow(matrix a, int b) {
    matrix res;
    res.make_eye();
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    matrix m1;
    for (int i = 0; i < 6; i++) m1.A[i] = 1;
    for (int i = 1; i < 6; i++) m1.A[i*m1.col + i - 1] = 1;
    int n;
    scanf("%d", &n); 
    printf("%lld\n", pow(m1, n).A[0]);
}