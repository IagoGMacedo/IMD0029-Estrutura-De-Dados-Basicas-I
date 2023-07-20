#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

bool opens(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

bool closes(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}

bool closesIncorrectly(char ch, char top)
{
    return ( ch == ')' && top != '(' )
        or ( ch == ']' && top != '[')
        or ( ch == '}' && top != '{');
}

bool isWellFormed(string str)
{
    stack<char> pilha;
    for( auto ch : str )
    {
        if( opens(ch) )
        {
            pilha.push(ch);
        }
        else if ( (closes(ch) and pilha.empty() ) or
                 closesIncorrectly( ch, pilha.top() ) )
        {
            return false;
        }
        else 
        {
            pilha.pop();
        }
    }
    
    return pilha.empty();
}

int main(int argc, const char * argv[]) 
{
    vector<string> valids = {
        "()",
        "[]",
        "{}",
        "()[]{}",
        "{}[]()",
        "[]{}()",
        "{[()]}",
        "({[]})",
        "[({})]",
        "(()){{}}[[]]",
        "(({{[[]]}}))",
        "((){{}[[]]})",
        "({})([])([])({})([])({})",
        "({}[])(([]))(({}[]))",
        "({[]()}{{[]()}}([]{}))",
    };

    int cont = 0;
    int incorreto = 0;

    cout << "Testando entradas válidas: " << endl;
    for(string valid : valids)
    {
        cout << "\tEntrada " << ++cont << ":\t" << valid << "\n\t\tResultado:\t";
        if( isWellFormed(valid) == true )
        {
            cout << "Correto" << endl;
        }
        else
        {
            cout << "Incorreto" << endl;
            ++incorreto;
        }
    }

    vector<string> invalids = {
        "(",
        "[",
        "{",
        "()(",
        "[]{",
        "{}[",
        ")",
        "]",
        "}",
        "()}",
        "[]]",
        "{})",
        "{]",
        "[)",
        "(}",
        "()[]{}{)",
        "((){()}]",
        "{[(()[}[]{})]}",
        "((((((((((())))))",
        "(((()))))))))))))",
    };

    cont = 0;
    cout << "\nTestando entradas inválidas: " << endl;
    for(string invalid : invalids)
    {
        cout << "\tEntrada " << ++cont << ":\t" << invalid << "\n\t\tResultado:\t";
        if( isWellFormed(invalid) == false )
        {
            cout << "Correto" << endl;
        }
        else
        {
            cout << "Incorreto" << endl;
            ++incorreto;
        }
    }

    if(incorreto)
    {
        cout << "\nQ4 - Um total de " << incorreto << " teste(s) falhou/falharam. Verificar acima quais testes falharam." << endl;    
    }
    else
    {
        cout << "\nQ4 - Passou em todos os testes!" << endl;
    }

    return 0;
}