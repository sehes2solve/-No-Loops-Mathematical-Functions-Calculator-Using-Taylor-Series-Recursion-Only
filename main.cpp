#include <iostream>

using namespace std;

double exp_seq(double x , double n)
{
    if(n == 0)
        return 1 ;
    return (x/n)*exp_seq(x,n-1) ;
}
double exp_series(double x, double n , double & res)
{
    if(n == 0)
    {
        res++ ;
        return 0 ;
    }
    res += exp_seq(x,n) ;
    return 1 + exp_series(x,n-1,res) ;
}
double sin_seq(double x , double n)
{
    if(n == 0)
        return x ;

    return ((-x*x)/((2*n+1)*(2*n)))*sin_seq(x,n-1) ;
}
double sin_series(double x, double n , double & res)
{
    if(n == 0)
    {
        res += x ;
        return 0 ;
    }
    res += sin_seq(x,n) ;
    return 1 + sin_series(x,n-1,res) ;
}
double cos_seq(double x , double n)
{
    if(n == 0)
        return 1 ;

    return ((-x*x)/((2*n-1)*(2*n)))*cos_seq(x,n-1) ;
}
double cos_series(double x, double n , double & res)
{
    if(n == 0)
    {
        res += 1 ;
        return 0 ;
    }
    res += cos_seq(x,n) ;
    return 1 + cos_series(x,n-1,res) ;
}
double linplus_seq(double x , double n)
{
    if(n == 1)
        return x ;

    return (x/n - x)*linplus_seq(x,n-1) ;
}
double linplus_series(double x, double n , double & res)
{
    if(n == 1)
    {
        res += x ;
        return 1 ;
    }
    res += linplus_seq(x,n) ;
    return 1 + linplus_series(x,n-1,res) ;
}
double taninverse_seq(double x , double n)
{
    if(n == 0)
        return x ;

    return ((-x*x)*(2*n-1)/(2*n+1))*taninverse_seq(x,n-1) ;
}
double taninverse_series(double x, double n , double & res)
{
    if(n == 0)
    {
        res += x ;
        return 0 ;
    }
    res += taninverse_seq(x,n) ;
    return 1 + taninverse_series(x,n-1,res) ;
}

int main()
{
    double x , sum = 0 ;
    char y ;
    cout << "F(X) : " << "\n\n" ;
    cout << "1- e^x" << "\n\n";
    cout << "2- sin(X)" << "\n\n" ;
    cout << "3- cos(X)" << "\n\n" ;
    cout << "4- ln(1 + X)" << "\n\n" ;
    cout << "5- arctan(X)" << "\n\n" ;
    cout << "Enter Order of Function : " ;
    cin >> y ; cout << "\n\n" ;
    switch (y)
    {
        case '1' :
            cout << "Enter Value of X : " ;
            cin >> x ; cout << "\n\n" ;
            exp_series(x,1000,sum);
            cout << "Result : " << sum ;
            break ;
        case '2' :
            cout << "Enter Value of X : " ;
            cin >> x ; cout << "\n\n" ;
            sin_series(x,1000,sum) ;
            cout << "Result : " << sum ;
            break ;
        case '3' :
            cout << "Enter Value of X : " ;
            cin >> x ; cout << "\n\n" ;
            cos_series(x,1000,sum) ;
            cout << "Result : " << sum ;
            break ;
        case '4' :
            cout << "Enter Value of X (Note : -1 < X <= 1) : " ;
            cin >> x ; cout << "\n\n" ;
            if(x > -1 && x <= 1)
            {
                linplus_series(x,1000,sum) ;
                cout << "Result : " << sum ;
            }
            else
                cout << "Invalid Input ." << "\n\n" ;
            break ;
        case '5' :
            cout << "Enter Value of X (Note : -1 <= X <= 1) : " ;
            cin >> x ; cout << "\n\n" ;
            if(x >= -1 && x <= 1)
            {
                taninverse_series(x,1000,sum) ;
                cout << "Result : " << sum ;
            }
            else
                cout << "Invalid Input ." << "\n\n" ;
            break;
        default :
            cout << "Invalid Input ." << "\n\n" ;

    }

    return 0;
}
