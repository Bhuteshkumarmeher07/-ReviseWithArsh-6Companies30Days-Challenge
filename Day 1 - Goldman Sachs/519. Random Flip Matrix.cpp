// Approach
// As we have to return the [i,j] where, matrix[i][j] = 0 but there's no need to actually forming of matrix as we also have to reset it which will can lead to
// time or memory limit warnings. And also we need to maintain the equally likely condition, So we can approach this question in a very simple manner
// (now go to code)

// Complexity
// Time complexity: O(1)
// Space complexity: O(1)

class Solution {
public:
    int n, m;
    int i = 0, j =0; // start with first row and first col
    Solution(int m, int n) { // Initializes the object with the size of the binary matrix m and n
        this->n = n;
        this->m = m;
    }
    
    vector<int> flip() { // Returns a random index [i, j] of the matrix where matrix[i][j] == 0 and flips it to 1.
        int I = i, J = j; // for returning purpose
        if(j+1 < n) { // will iterate over columns till we can
            j++;
        }  
        else if(i+1 < m){
            i++;
            j = 0;
        }   
        else{
            i=0, j=0; // will point back to first row and col work as reset and continue to cycle again
        }
        return {I, J};
    }
    
    void reset() { // Resets all the values of the matrix to be 0
        // no need of it, we have taken care of it in the flip() part
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
