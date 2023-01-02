#ifndef NOEUDFIBONACCI_H_INCLUDED
#define NOEUDFIBONACCI_H_INCLUDED

#include <bits/stdc++.h>


class Fibonacci_Node {
public :
    long double n{};
    long double Un{};
    explicit Fibonacci_Node(long double ,long double );
    Fibonacci_Node();
    friend std::ostream &operator<<(std::ostream &,Fibonacci_Node  );
    bool operator==(Fibonacci_Node ) const;
    bool operator!=(Fibonacci_Node ) const;
    bool  operator>(Fibonacci_Node ) const;
    bool  operator<(Fibonacci_Node ) const;
    Fibonacci_Node& operator=(const Fibonacci_Node& f);

};

#endif // NOEUDFIBONACCI_H_INCLUDED
