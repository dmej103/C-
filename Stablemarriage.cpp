#include<iostream>
using namespace std;

bool ok(int q[], int col) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man#i) and (Man#c's wife) both like each other more than their own spouse
	  Third condition checks if (Man#c) and (Man#i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man#i likes Woman#j. (0 = favorite; 2 = least favorite) 
	  wp[i][j] tells you how much Woman#i likes Man#j.

	  mp[i][q[i]] tells you how much Man#i likes his own wife. 
	  mp[i][q[c]] tells you how much Man#i likes Man#c's wife. 
	  wp[q[i]][i] tells you how much Man#i's wife likes Man#i. 
	  wp[q[i]][c] tells you how much Man#i's wife likes Man#c. 
	  If mp[i][q[c]] < mp[i][q[i]], it means that Man#i likes Man#c's wife more than his own wife
	*/

	//if we pass the loop, what do we return?
    for(int i=0;i<col;i++){
		if(q[i]==q[col])return false;
	}
	
	for(int i=0;i<col;i++){
		if(mp[i][q[col]]<mp[i][q[i]] && wp[q[col]][i]<wp[q[col]][col]) return false;
	}

	for(int i=0;i<col;i++){
		if(wp[q[i]][col]<wp[q[i]][i] && mp[col][q[i]]<mp[col][q[col]])return false;
	}
	return true;
}

void print(int q[], int c) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function
    for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}


int main () {

    int q[3] = {};   // Initialize the array to 0.
   // Start in the 1st row, 1st column
   q[0] = 0;
   int col = 0;
   q[col] = 0; //q[c] == row so this initializes row = 0;
   while (col >= 0) { // End the loop if you backtrack from the first column
        if (col < 0) break;
      // Move to the next column
        col++;
      
         if (col == 3) {          // If you have passed the last column,
             print(q, col);
            col--;                   // Call the print function and backtrack
            
         }
         else q[col] = -1; // Otherwise, move to one before the first row
      while (col>= 0) {
         // Move to the next row
         q[col]++;
         // If you have passed the end of the column, backtrack
         if (q[col] == 3) col--;
         // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
         else if (ok(q,col)) {
             break;
         }
      }
 }
return 0;
}