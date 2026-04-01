class Solution {
public:
    long resolves( int a , int b , char Operator){
        if ( Operator == '+') return a + b ;
        else if ( Operator == '-') return a- b;
        else if ( Operator == '*') return ( long) a * b ;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long>s;
        int n = tokens.size();
        for ( int i = 0 ; i < n ; i++){
            if (tokens[i].size() == 1 && tokens[i][0] <48){
                long integer2 = s.top();
                s.pop();
                              long integer1 = s.top();
                s.pop();
                string Operator = tokens[i];
                long resolvedAns = resolves ( integer1 , integer2 , Operator[0]);
                s.push( resolvedAns);

            }else 
             s.push(stol(tokens[i]));
        }
        return s.top();
        
    }
};