#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

bool isOperator( string s )
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int applyOperator(string first, string second, string operatorr)
{
    int iFirst = stoi(first);
    int iSecond = stoi(second);

    if( operatorr == "+")
    {
        return iFirst + iSecond;
    }
    else if( operatorr == "-")
    {
        return iFirst - iSecond;
    }
    else if( operatorr == "*")
    {
        return iFirst * iSecond;
    }
    else //if( operatorr == "/")
    {
        return iFirst / iSecond;
    }
}

int getPriority(string element)
{
    if (element == "-" || element == "+") 
        return 1; 
    else if (element == "*"|| element == "/") 
        return 2; 
    return 0; 
}

int evaluate(vector<string> expression)
{
    stack<string> operators;
    stack<string> operands;

    bool isSecond = false;

    for( string element : expression )
    {
        if( !isOperator(element) )
        {
            operands.push(element);
        }
        else
        {
            while (!operators.empty() &&  
                   getPriority(element) <=  
                     getPriority(operators.top())) { 
  
                string op2 = operands.top(); 
                operands.pop(); 
  
                string op1 = operands.top(); 
                operands.pop(); 
  
                string op = operators.top(); 
                operators.pop(); 
  
                int result = applyOperator( op1, op2, op);

                operands.push( to_string(result) );
            }

            operators.push(element); 
        }
    }

    return stoi( operands.top() );
}

int main(int argc, const char * argv[]) 
{
    vector<pair<vector<string>, int>> inputs = {
        make_pair( vector<string>({"+", "3", "5"}),  8  ),
        make_pair( vector<string>({"-", "7", "9"}), -2  ),
        make_pair( vector<string>({"*", "3", "4"}), 12  ),
        make_pair( vector<string>({"/", "10", "2"}), 2  ),
        make_pair( vector<string>({"+", "3", "*", "5", "4"}), 23  ),
    };

    cout << "Q3\n";

    for( auto i : inputs )
    {
        for( auto s : i.first )
        {
            cout << s << " ";
        }
        cout << " = " << evaluate(i.first) << endl;
    }
        
        
    

    return 0;
}
