// through backtracking
// O(3^n)
class Solution {
public:
    vector<string> result;
    char keypad [12][10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void keypadString(string input, string &output, int i,int j,int n)
    {
        if(input[i]=='\0')
        {
            result.push_back(output);
            return;
        }
        int digit = input[i] - '0';
        for(int k=0; keypad[digit][k]!='\0'; ++k)
        {
            output += keypad[digit][k];
            keypadString(input,output,i+1,j+1,n);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return result;
        string output;
        int n = digits.size();
        keypadString(digits,output, 0,0,n);
        return result;
    }
};
