#include <iostream>

int somar(int a, int b)
{
    if( a == 0 )
    {
        return b;
    }
    else
    {
        return 1 + somar(a-1, b);
    }
}

int multiplicar(int a, int b)
{
    if( a == 0 )
    {
        return 0;
    }
    else 
    {
        return b + multiplicar(a-1, b);
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Digite dois números naturais para realizar as operações, ou um número negativo para encerrar o programa.\n\n";
    
    int n, m;  
    while( std::cin >> n >> m && (n >= 0 && m >= 0) )
    {
        std::cout << "Somar( " << n << ", " << m << " ) = " << somar(n, m) << std::endl;
        std::cout << "Multiplicar( " << n << ", " << m << " ) = " << multiplicar(n, m) << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "Programa encerrado.\n";

    return 0;
}