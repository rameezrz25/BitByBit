#include<iostream>
#include<string>
#include<vector>
using namespace std;

void computeLPS(string pattern, vector<int>& lps) {
    int m = pattern.size(); // Length of the pattern
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++; // Increment the length of the previous longest prefix suffix
            lps[i] = len; // Assign the incremented length to the current index
            i++; // Move to the next index
        }
        else if(len != 0){
            len = lps[len - 1]; // If the characters do not match, then check for the previous longest prefix suffix
        }
        else {
            lps[i] = 0; // If the characters do not match and the length is 0, then assign 0 to the current index
            i++; // Move to the next index
    }
}
}
        
vector <int> search(string pat, string txt) {
    int N = txt.length(); // Length of the text
    int M = pat.length(); // Length of the pattern
    vector<int> result; // Vector to store the result indices
    
    // Create an LPS array to store the longest proper prefix which is also a suffix
    // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
    vector<int> lps(M, 0);
    computeLPS(pat, lps); // Compute the LPS array

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++; // Increment the text index
            j++; // Increment the pattern index
        }

        if (j == M) {
            result.push_back(i-j+1); // Pattern found at index i-j+1 (1-based indexing)
            j = lps[j - 1]; // Update the pattern index using the LPS array
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Update the pattern index using the LPS array
            } else {
                i++; // Increment the text index
            }
        }
    }
    
    return result; // Return the result vector
}
     
int main(){

    string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> result = search(pat, txt);
    if(result.size() == 0){
        cout << "Pattern not found in the text\n";
    } else {
        cout << "Pattern found at index: ";
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;   
}

