#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   for(int i = 1;i <= c; i++)
      if (q[c] == q[i-1] || q[c]-i == q[c-i] || q[c]+i == q[c-i])
         return false;
   return true;
}

// This function should return the number of solutions for the given board size. (you don't need to print the solutions).
int nqueens(int n) {
    int *x;
    x= new int[n];
    for(int i = 0;i < n; i++) x[i]=0;
   
    int c = 0,r = 0;
    int solutions=0;
    while (c >= 0) {
        ++c;
        if(c >= n){
        ++solutions;
        --c;
        r=x[c];
    }
        else r = -1;
        while (c >= 0) {
            ++r;
		    x[c] = r;
         
            if(r >= n){
            --c;
            r = x[c];
            }
            
            else if(ok(x,c)) break;      
	    }
    }
   
   delete []x;
   return solutions;
}

int main() {
    int n = 12;
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}