#ifndef ARBREFIBONACCI_H_INCLUDED
#define ARBREFIBONACCI_H_INCLUDED
#include "Arbre.h"
#include"NoeudFibonacci.h"

class FibonacciTree {
public:

    Arbre<Fibonacci_Node> *arbre{} ;

    FibonacciTree(){arbre=new Arbre<Fibonacci_Node>();}
    long double add_fibo_node(Fibonacci_Node f) const{
    arbre->inserer(f);
    return f.Un;
    }
    long double fibonacci_of(long double n){
    if(n==1) return 1;
    if(n==0) return 0;
    if(arbre->Search(Fibonacci_Node(n,0)))
        return arbre->recherche(Fibonacci_Node(n,0))->donnees.Un;
    return add_fibo_node(Fibonacci_Node(n,(fibonacci_of(n-2)+fibonacci_of(n-1)) )) ;
}
    long double calc_fibonacci(long double n) {
    if(arbre->Search(Fibonacci_Node(n,0)))
        return arbre->recherche(Fibonacci_Node(n,0))->donnees.Un;
    return add_fibo_node(Fibonacci_Node(n, fibonacci_of(n)));
}
    };


#endif // ARBREFIBONACCI_H_INCLUDED
