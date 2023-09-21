#include <iostream>
using namespace std;

/*  
grammar:

Expression:
    Term
    Expression "+" Term
    Expression "-" Term
Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Priamry
Primary:
    Number
    "(" Expression ")"
Number:
    floating-point-literal
*/


class Token {
public:
    int kind;
    int value;
};

double expression();
double term();
double primary();
Token get_Token();


int main(void) {


    return 0;
}


double expression() {
    double left = term();
    Token t = get_Token();
    while(true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = get_Token();
                break;
            case '-':
                left -= term();
                t = get_Token();
                break;
            default:
                return left;
        }
    }
}


double term() {
    double left = primary();
    Token t = get_Token();
    while(true) {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = get_Token();
            break;
        case '/':
            double d = primary();
            if (d == 0) {
                throw runtime_error("divide by zero");
            }
            left /= primary();
            t = get_Token();
            break;
        default:
            return left;
        }
    }
}


double primary() {

}

Token get_Token() {

}
