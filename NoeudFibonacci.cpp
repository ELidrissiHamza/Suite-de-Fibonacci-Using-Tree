#include"NoeudFibonacci.h"
Fibonacci_Node::Fibonacci_Node(long double nn,long double Unn):n(nn),Un(Unn) {
}

std::ostream &operator<<(std::ostream &out,Fibonacci_Node Fi)
{

    out<<"( U("<<Fi.n<<")="<<Fi.Un<<" )";
    return out;
}

bool Fibonacci_Node::operator==(Fibonacci_Node f) const{return  (this->n==f.n) ;}
bool Fibonacci_Node::operator>(Fibonacci_Node f) const {return  (this->n>f.n);}
bool Fibonacci_Node::operator<(Fibonacci_Node f) const {return  (this->n<f.n);}
bool Fibonacci_Node::operator!=(Fibonacci_Node f) const {return  (this->n!=f.n);}

Fibonacci_Node::Fibonacci_Node() = default;

Fibonacci_Node &Fibonacci_Node::operator=(const Fibonacci_Node &f) = default;
