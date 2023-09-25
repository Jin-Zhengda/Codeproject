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

class Token_stream {
    public:
    Token get();
    void putback(Token t);
    private:
        bool full {false};
        Token buffer;
};


double expression();
double term();
double primary();
Token get_Token();

Token_stream ts;

int main(void) {
    double val = 0;
    try {
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'q') {
                break;
            }
            if (t.kind == ':') {
                cout << '=' << '\n';
            } else {
                ts.putback(t);
            }
            val = expression();
        }
    }
    catch(exception &e) {
        cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}


double expression() {
    double left = term();
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}


double term() {
    double left = primary();
    Token t = ts.get();

    while(true) {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            double d = primary();
            if (d == 0) {
                throw runtime_error("divide by zero");
            }
            left /= primary();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}


double primary() {
    Token t = ts.get();

    switch (t.kind) {
    case '(':
        double d = expression();
        t = ts.get();
        if (t.kind != ')') {
            throw runtime_error("() do not match");
        }
        return d;
        break;
    case '8':
        return t.value;
        break;
    default:
        throw runtime_error("expected primary");
    }
}

Token get_Token() {

}

void Token_stream::putback(Token t) {
    if (full) {
        throw runtime_error("putback() into a full buffer");
    }
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch)
    {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token('8', val);
    } 
    default:
        throw runtime_error("Bad Token");
    }
}
