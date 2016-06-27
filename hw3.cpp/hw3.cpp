/** Name: Trang Vu
 Date: October 16, 2015
 @File: hw3.cpp
 @Brief: This program codes for class Rational and added some more functions for the Polynomial Class.  Member functions are created to use the Rational class in the int main.  Definitions are provided after int main
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout; // this line lets you to write cout without std:: in front
using std::endl; // this line lets you to write endl; without std:: in front

/** @class Polynomial
 @brief functions for the Polynomial Class
 
 This function defines the polynomial a0 + a1x + a2x^2 ... where a is the inputted coefficients
 */
class Polynomial {
    //This is a comparison operator
    friend bool operator==(const Polynomial&, const Polynomial&);
public:
    
    //Constructors
    Polynomial();
    Polynomial(const std::vector<int>& coeffs);
    
    // Accessors
    int Degree() const;
    int Coefficient(size_t k) const;
    void print() const;
    int at(size_t) const;
    
    // Mutators
    void constantMultiply(int x);
    void Transform();

    // performs poly = poly + poly2.  Called as poly.AddBy(poly2)
    void AddBy(const Polynomial& poly2);
    // poly = poly - poly2
    void SubtractBy(const Polynomial& poly2);
    // poly = poly * poly2
    void MultiplyBy(const Polynomial& poly2);
    
    double operator()(double) const;
    
    //Arithmetic operations, these will perform the usual polynomial arithmetic as the AddBy, SubtractBy, MultiplyBy functions
    Polynomial& operator+=(const Polynomial& poly2);
    Polynomial& operator-=(const Polynomial& poly2);
    Polynomial& operator*=(const Polynomial& poly2);
    Polynomial operator-() const;
    Polynomial operator+() const;
    
    //Increment operators
    //Prefix operator
    Polynomial& operator++();
    //Postfix operator
    Polynomial operator++(int);
    //Prefix operator
    Polynomial& operator--();
    //Postfix operator
    Polynomial operator--(int);
    
    
private:
    std::vector<int> coefficient;
};


//Ask for the input of coefficient for the polynomial
void initializeValueFromTerminal(Polynomial& function);

//Arithmetic operations
Polynomial operator+(Polynomial lhs, const Polynomial& rhs);
Polynomial operator-(Polynomial lhs, const Polynomial& rhs);
Polynomial operator*(Polynomial lhs, const Polynomial& rhs);

//Comparison operator
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

/** @Class Rational
    @brief functions for Rational Class
 
    This function defines two variables: a numerator and a denominator that consist of polynomials.  For example, (a0 + a1x + a2x^2 ...)/(a0 + a1x + a2x^2 ...), where a is the inputted coefficients
 */
class Rational {
    //Comparison operator
    friend bool operator==(const Rational&, const Rational&);
public:
    //Constructors
    Rational ();
    Rational (const Polynomial&);
    Rational (const Polynomial&, const Polynomial&);
    
    //Accessor
    void print() const;
    
    //Mutator
    double operator()(double) const;
    
    //Arithmetic operations
    Rational& operator+=(const Rational&);
    Rational& operator-=(const Rational&);
    Rational& operator*=(const Rational&);
    Rational& operator/=(const Rational&);
    
    Rational& operator+=(const Polynomial&);
    Rational& operator-=(const Polynomial&);
    Rational& operator*=(const Polynomial&);
    
    //Increment operators
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator --(int);
    
private:
    Polynomial numerator;
    Polynomial denominator;
};

//Arithmetic operations
Rational operator+(Rational, const Rational&);
Rational operator-(Rational, const Rational&);
Rational operator*(Rational, const Rational&);
Rational operator/(Rational, const Rational&);

Rational operator+(Rational, const Polynomial&);
Rational operator-(Rational, const Polynomial&);
Rational operator*(Rational, const Polynomial&);

//Comparison operator
bool operator!=(const Rational&, const Rational&);

//Prompt user to input coefficients
void initializeValueFromTerminal(Rational& function);

int main ()
{
    
    Rational p; // Default constructor , p = 0 initially // Input coefficients for Rational , separated by −12345.
    initializeValueFromTerminal ( p ) ;
    // For example, input of 1 −2 0 4 −12345 1 1 1 −12345 creates ← rational
    // p(x) = 1−2x+4xˆ3 / 1+x+xˆ2
    
    cout<<"Your first rational is "; p.print(); cout<<endl;
    
    Rational q ;
    initializeValueFromTerminal ( q ) ;
    // For example, input of 0 −1 5 0 0 0 −3 −12345 6 0 1 −2 −12345 creates rational
    // q(x) = −x+5xˆ2−3xˆ6 / 6+xˆ2−2xˆ3
    
    cout<<"Your second rational is "; q.print(); cout<<endl;
    
    Rational r = p+q;
    cout<<"r(x) := p(x)+q(x) = "; r.print(); cout<<endl;
    
    r += p;
    cout<<"r(x)+p(x) = "; r.print(); cout<<endl;
    
    r *= q;
    cout<<"(r(x)+p(x))*q(x) = "; r.print() ; cout<<endl;
    
    Rational s = ++r;
    cout<<"s(x) := (r(x)+p(x))*q(x)+1 = "; s.print() ; cout<<endl;
    
    Rational t = s ;
    cout<<"t(x) := s(x)"; cout<<endl;
    
    cout<<"t(x) == s(x)? ";
    if( t==s ) cout<<"yes!\n"; else cout<<"no!\n";
    
    s++;
    cout<<"s(x) <−− s(x)+1 = "; s.print() ; cout<<endl;
    
    cout<<"t(x) != s(x)? ";
    if( t != s ) cout<<"yes!\n"; else cout<<"no!\n";
   
    Rational a = p*q ;
    cout<<"a(x) := p(x)*q(x) = "; a.print(); cout<<endl;
    
    Rational b = p-q ;
    cout<<"b(x) := p(x)-q(x) = "; b.print(); cout<<endl;
    
    b -= a ;
    cout<<"p(x)−q(x)−p(x)*q(x) = "; b.print() ; cout<<endl;
    
    b--;
    cout<<"p(x)−q(x)−p(x)*q(x)−1 = "; b.print() ; cout<<endl;
    
    --b;
    cout<<"p(x)−q(x)−p(x)*q(x)−2 = "; b.print() ; cout<<endl;
    return 0;
}

/** Default constructor initializes the rational function to 0/1 by default.  In other words, the numerator equals 0 and the denominator equals 1
 */
Rational::Rational () {
    Polynomial top = std::vector<int>(1,0);
    Polynomial bottom = std::vector<int>(1,1);
    numerator = top;
    denominator = bottom;
}

/** This constructor allows user to only have one set of input for the numerator only.  In other words, the numerator will be the inputted values and the denominator equals 1
    @param top set the inputted coefficients equal to the private variable numerator
 */
Rational::Rational (const Polynomial& top) {
    numerator = top;
    denominator = std::vector<int>(1,1);
}

/** Sets the private variable for numerator equal to the first argument and private variable for the denominator equal to the second argument
    @param top set the input coefficients equal to the private variable numerator
    @param bottom set the input coefficients equal to the private variable denominator
 */
Rational::Rational (const Polynomial& top, const Polynomial& bottom){
    numerator = top;
    denominator = bottom;
}

/** Add two rationals together
    @param rhs is the right hand side rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator+=(const Rational& rhs){
    // a/b + c/d = (a*d+b*c)/(b*d)
    numerator = numerator*rhs.denominator + rhs.numerator*denominator;
    denominator = denominator*rhs.denominator;
    return *this;
}

/** Subtracts two rationals
    @param rhs is the right hand side rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator-=(const Rational& rhs){
    // a/b + c/d = (a*d - b*c)/(b*d)
    numerator = numerator*rhs.denominator - rhs.numerator*denominator;
    denominator = denominator*rhs.denominator;
    return *this;
}

/** Multiplies two rationals
    @param rhs is the right hand side rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator*=(const Rational& rhs){
    // a/b * c/d = (a*c)/(b*d)
    numerator = numerator*rhs.numerator;
    denominator = denominator*rhs.denominator;
    return *this;
}

/** Divides two rationals
    @param rhs is the right hand side rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator/=(const Rational& rhs){
    // (a/b)/(c/d) = (a*d)/(b*c)
    numerator = numerator*rhs.denominator;
    denominator = denominator*rhs.numerator;
    return *this;
}

/** Adds a rational and a polynomial
    @param rhs is the polynomial
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator+=(const Polynomial& rhs){
    // a/b + c = (a+c*b)/b
    numerator = numerator + rhs*denominator;
    return *this;
}

/** Subtracts a polynomial from a rational
    @param rhs is the polynomial
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator-=(const Polynomial& rhs){
    // a/b - c = (a-c*b)/b
    numerator = numerator - rhs*denominator;
    return *this;
}

/** Multiplies a rational and a polynomial
    @param rhs is the polynomial
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator*=(const Polynomial& rhs){
    // a/b * c = (a*c)/b
    numerator = numerator * rhs;
    return *this;
}

/** Compares the left side rational and the right side rational
    @param lhs is the left side rational
    @param rhs is the right side rational
    @return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator) true
 */
bool operator == (const Rational& lhs, const Rational& rhs){
    return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}

/** Compares the left side rational and the right side rational
    @param lhs is the left side rational
    @param rhs is the right side rational
    @return !(lhs == rhs) false
 */
bool operator != (const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

/** Prefix increment, add one to the rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator++(){
    // (a/b) + 1 = (a+b)/b
    numerator = numerator + denominator;
    return *this;
}

/** Postfix increment, add one to the rational
    @return clone is the copy of the changed value
 */
Rational Rational::operator++(int unused){
    Rational clone = *this;
    ++(*this);
    return clone;
}

/** Prefix increment, subtract one from the rational
    @return *this is a pointer at the changed value
 */
Rational& Rational::operator--(){
    // (a/b) - 1 = (a-b)/b
    numerator = numerator - denominator;
    return *this;
}

/** Prefix increment, subtract one from the rational
    @return clone is a copy of the changed value
 */
Rational Rational::operator --(int){
    Rational clone = *this;
    --(*this);
    return clone;
}

/** Evaluates the rational function at a given input by taking the quotient of the values of the polynomials stored as numerator and denominator 
    @param a is the inputted value
    @return numerator(a)/denominator(a) uses the operator() to evaluate the polynomial at a given input
 */
double Rational::operator()(double a) const{
    return numerator(a)/denominator(a);
}

/** Prints the rational, which is (numerator)/(denominator)
 */
void Rational::print()const{
    cout << "(";
    numerator.print();
    cout << ")" << " / " << "(";
    denominator.print();
    cout << ")";
}

/** Overloads + to make a new rational from adding two rationals
    @param lhs is the left hand rational
    @param rhs is the right hand rational
    @return lhs+=rhs is the sum of the rationals
 */
Rational operator+(Rational lhs, const Rational& rhs){
    return lhs+=rhs;
}

/** Overloads - to make a new rational from subtracting two rationals
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs-=rhs is the difference of the rationals
 */
Rational operator-(Rational lhs, const Rational& rhs){
    return lhs-=rhs;
}

/** Overloads * to make a new rational from multiplying two rationals
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs*=rhs is the products of the rationals
 */
Rational operator*(Rational lhs, const Rational& rhs){
    return lhs*=rhs;
}

/** Overloads / to make a new rational from dividing two rationals
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs/=rhs is the quotient of the rationals
 */
Rational operator/(Rational lhs, const Rational& rhs){
    return lhs/=rhs;
}

/** Overloads + to make a new rational from adding a rational and a polynomial
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs+=rhs is the sum of a rational and a polynomial
 */
Rational operator+(Rational lhs, const Polynomial& rhs){
    return lhs+=rhs;
}

/** Overloads - to make a new rational from subtracting a rational and a polynomial
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs-=rhs is the difference of a rational and a polynomial
 */
Rational operator-(Rational lhs, const Polynomial& rhs){
    return lhs-=rhs;
}

/** Overloads * to make a new rational from multiplying a rational and a polynomial
 @param lhs is the left hand rational
 @param rhs is the right hand rational
 @return lhs*=rhs is the product of a rational and a polynomial
 */
Rational operator*(Rational lhs, const Polynomial& rhs){
    return lhs*=rhs;
}

/** Prompts the user to input two sets of coefficients for the rational.  The first set will be the coefficients for the numerator and the second set will be the coefficients for the denominator.
    @param function is the rational created from the two sets of inputted coefficients
 */
void initializeValueFromTerminal(Rational& function){
    std::cout << "Please input two sets of coefficients for the rational." << std::endl << "When you are finished with each set, enter -12345." << std::endl;
    //Vector stores inputted coeffcients of the numerator
    std::vector<int>num;
    int coeff = 0;
    std::cin >> coeff;
    // -12345 ends the loop
    while (coeff != -12345){
        num.push_back(coeff);
        std::cin >> coeff;
    }
    //Vector stores inputted coefficients of the denominator
    std::vector<int>den;
    std::cin >> coeff;
    while (coeff != -12345){
        den.push_back(coeff);
        std::cin >> coeff;
    }
    Rational func(num,den);
    function = func;
}

/** This is the default constructor, which initializes the Polynomial to 0
 */
Polynomial::Polynomial() : coefficient(1,0){
}

/** Allow polynomial to save coefficients into a vector.
 The polynomial is initialized to 0 if there are no input for the vector
 */
Polynomial::Polynomial(const std::vector<int>& coeffs){
    coefficient = coeffs;
    //polynomial is initialized to 0 if there are no input for the vector
    if (coefficient.size () == 0){
        coefficient = std::vector<int> (1,0);
    }
}

/** Give the highest degree of the polynomial
 */
int Polynomial::Degree() const{
    return coefficient.size() - 1;
}

/** Returns the coefficient of the requested degree of x.
 @param k is the degree of x
 */
int Polynomial::Coefficient(size_t k) const {
    //if the size is less than the requested degree then return 0
    if ((coefficient.size()-1) < k) {
        return 0;
    }
    //else return the coefficient of the degree
    else {
        return coefficient[k];
    }
}

/** Prints the polynomial in the form of "a0 + a1x + a2x^2 ..."
 If the inputed coefficient is 0, then it is not printed out in the polynomial
 If the inputed coefficient is either 1 or -1, then only x or -x is printed
 */
void Polynomial::print() const {
    //If the vector has a size of 0 then output 0
    if (coefficient.size() == 0){
        std::cout << "0";
    }
    //If the vector only have one input then it is stored in [0]
    else if (coefficient.size() == 1) {
        std::cout << coefficient [0];
    }
    //This statement is used to replace 1 and -1 with x and -x, respectively
    else {
        //if [0] is not equal to 0 then cout [0]
        if (coefficient[0] != 0){
            std::cout << coefficient[0];
        }
        //if [1] equal -1 then cout -x
        if (coefficient[1] == -1) {
            std::cout << "-x";
        }
        //if [1] equal 1 then cout x
        else if (coefficient[1] == 1) {
            std::cout << "+x";
        }
        //if [1] does not equal 0 then cout [1]x
        else if (coefficient[1] != 0) {
            std::cout << "+" << coefficient[1] << "x";
        }
    }
    //This loop goes through all of the coefficient in the vector and add a "+" sign in front of it and add its degree
    for (int a = 2; a < coefficient.size(); a++){
        //if any element in the vector equals -1 then cout +-x (prospective degree)
        if (coefficient[a] == -1){
            std::cout << "+" << "-x^" << a;
        }
        //if any element in the vector equals 1 then cout +x^ (prospective degree)
        else if (coefficient[a] == 1) {
            std::cout << "+" << "x^" << a;
        }
        //if none of the element equals 0 then cout the value of the element ^ (prospective degree)
        else if (coefficient[a] != 0) {
            std::cout << "+" << coefficient[a] << "x^" << a;
        }
    }
}

/** Multiplies the polynomial by a constant
 @param x is the constant that the polynomial is multiplied to
 */
void Polynomial::constantMultiply(int x) {
    //Goes through each element and multiply the value of each element by the constant
    for (int a = 0; a < coefficient.size(); a++) {
        coefficient[a] = coefficient[a] * x;
    }
}

/** Transforms the polynomial to its derivative using the power rule
 */
void Polynomial::Transform() {
    //If there was only one input then set the value of the element 0 equal to 0
    if (coefficient.size() == 1) {
        coefficient [0] = 0;
    }
    //Takes the derivative of each element, then delete one element for the new vector
    else {
        for (int a = 0; a < (coefficient.size()-1); a++){
            coefficient[a] = coefficient[a+1] * (a+1);
        }
        coefficient.pop_back();
    }
}

/**  Adds the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 
 void Polynomial::AddBy(const Polynomial& poly2){
 std::vector<int> sum;
 int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
 for (int a = 0; a<loop_length; a++)
 {
 if (a > this->Degree())
 sum.push_back(poly2.coefficient[a]);
 else if (a > poly2.Degree())
 sum.push_back(this->coefficient[a]);
 else
 sum.push_back(this->coefficient[a]+poly2.coefficient[a]);
 }
 while ((sum.back() == 0) && (sum.size() > 1)){
 sum.pop_back();
 }
 coefficient = sum;
 }
 
 Subtracts the second polynomial from the first polynomial
 @param poly2 is the vector of coeffcients for the second polynomial
 
 void Polynomial::SubtractBy(const Polynomial& poly2){
 std::vector<int> diff;
 int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
 for (int a = 0; a<loop_length; a++)
 {
 if (a > this->Degree())
 diff.push_back(-poly2.coefficient[a]);
 else if (a > poly2.Degree())
 diff.push_back(this->coefficient[a]);
 else
 diff.push_back(this->coefficient[a]-poly2.coefficient[a]);
 }
 while ((diff.back() == 0) && (diff.size() > 1)){
 diff.pop_back();
 }
 coefficient = diff;
 
 }
 
 Multiplies the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 
 void Polynomial::MultiplyBy(const Polynomial& poly2){
 int degree_prod = this->Degree() + poly2.Degree() + 1;
 std::vector<int> prod(degree_prod,0);
 for (size_t a=0; a<(this->Degree() +1);a++){
 for (size_t b=0; b < (poly2.Degree() +1); b++){
 prod[a+b] += this->Coefficient(a)*poly2.Coefficient(b);
 }
 }
 coefficient = prod;
 }
 */

/**Ask for the input of coefficient for the polynomial
 @param function is the inputted polynomial
 */
void initializeValueFromTerminal(Polynomial& function){
    std::cout << "Please input the coefficients of the polynomial." << std::endl << "When you are finished, enter -12345." << std::endl;
    //Vector stores inputted coeffcients of polynomial 1
    std::vector<int>p;
    int coeff = 0;
    std::cin >> coeff;
    // -12345 ends the loop
    while (coeff != -12345){
        p.push_back(coeff);
        std::cin >> coeff;
    }
    function = p;
    
}

/**  Adds the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 @return *this refers to the object pointint to the function
 */
Polynomial& Polynomial::operator+=(const Polynomial& poly2){
    std::vector<int> sum;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    //This loop goes through each element from each vector, and add the first element of the first vector and the first element of the second vector and so on
    for (int a = 0; a<loop_length; a++)
    {
        //add an element if a is greater than degree
        if (a > this->Degree())
            sum.push_back(poly2.coefficient[a]);
        //add an element if a is greater than the degree of polynomial 2
        else if (a > poly2.Degree())
            sum.push_back(this->coefficient[a]);
        //add an element
        else
            sum.push_back(this->coefficient[a]+poly2.coefficient[a]);
    }
    //delete an element from the vector sum
    while ((sum.back() == 0) && (sum.size() > 1)){
        sum.pop_back();
    }
    coefficient = sum;
    return *this;
}

/**  Subtracts the first polynomial from the second polynomial
 @param poly2 is the vector of coeffcients for the second polynomial
 @return *this refers to the object pointing to the function
 */
Polynomial& Polynomial::operator-=(const Polynomial& poly2){
    std::vector<int> diff;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    //This loop goes through each element from each vector, and subtract the first element of the first vector and the first element of the second vector and so on
    for (int a = 0; a<loop_length; a++)
    {
        //add an element
        if (a > this->Degree())
            diff.push_back(-poly2.coefficient[a]);
        //add an element
        else if (a > poly2.Degree())
            diff.push_back(this->coefficient[a]);
        //add an element
        else
            diff.push_back(this->coefficient[a]-poly2.coefficient[a]);
    }
    //delete an element
    while ((diff.back() == 0) && (diff.size() > 1)){
        diff.pop_back();
    }
    coefficient = diff;
    return *this;
}

/**  Multiplies the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 @return *this is a copy
 */
Polynomial& Polynomial::operator*=(const Polynomial& poly2){
    int degree_prod = this->Degree() + poly2.Degree() + 1;
    std::vector<int> prod(degree_prod,0);
    // this loop is used to multiply each element from each vector together
    for (size_t a=0; a<(this->Degree() +1);a++){
        for (size_t b=0; b < (poly2.Degree() +1); b++){
            prod[a+b] += this->Coefficient(a)*poly2.Coefficient(b);
        }
    }
    coefficient = prod;
    return *this;
}
/**Add the right polynomial to the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator+(Polynomial lhs, const Polynomial& rhs){
    return lhs+=rhs;
}

/**Subtract the right polynomial from the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator-(Polynomial lhs, const Polynomial& rhs){
    return lhs-=rhs;
}

/**Multiply the right polynomial to the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator*(Polynomial lhs, const Polynomial& rhs){
    return lhs*=rhs;
}

/**Comparison operator that make sure both side of the equal sign is the same
 @param lhs does not need a copy and does not need modification
 @param rhs does not need a copy and does not need modification
 @return lhs.coefficient == rhs.coefficient compares two ints
 */
bool operator == (const Polynomial& lhs, const Polynomial& rhs){
    return (lhs.coefficient == rhs.coefficient);
}

/**Comparison operator
 @param lhs does not need a copy and does not need modification
 @param rhs does not need a copy and does not need modification
 @return !(lhs == rhs) is a nonmember because we don't need to access to private variable
 */
bool operator != (const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}

/**Prefix, increment operator
 @return *this is a copy
 */xPolynomial& Polynomial::operator++(){
    coefficient[0]=coefficient[0]+1;
    return *this;
}

/**Postfix, increment operator
 @param unused is the int created
 @return clone
 */
Polynomial Polynomial::operator++(int unused) {
    Polynomial clone = *this;
    ++(*this);
    return clone;
}

/**Prefix, increment operator
 @return *this is a copy
 */
Polynomial& Polynomial::operator--(){
    coefficient[0]=coefficient[0]-1;
    return *this;
}

/**Postfix, increment operator
 @param unused is the int created
 @return clone
 */
Polynomial Polynomial::operator--(int unused) {
    Polynomial clone = *this;
    --(*this);
    return clone;
}

/**  Evaluates the function at a given input
    @param input is the value that user input
    @return sum is the sum of each element of the vector added together
 */
double Polynomial::operator()(double input) const {
    double sum = 0;
    for(int i = 0, n = coefficient.size(); i < n; ++i)
        sum += coefficient[i] * pow(input,i);
    return sum;
}

/**  Returns the value of the coefficient corresponding to the input
    @param input is the value of the degree that the user want to see its corresponding coefficient
    @return coefficient[input] gives the coefficient of the corresponding input
 */
int Polynomial::at(size_t input) const{
    //if the input value is greater than the biggest degree of the vector, then return 0
    if ((coefficient.size()-1) < input)
        return 0;
    //else return the coefficient of the degree
    else
        return coefficient[input];
}

/** Overloads - to multiply all the constants by -1
    @return clone is a copy of the new polynomial
 */
Polynomial Polynomial::operator-() const{
    Polynomial clone = *this;
    clone.constantMultiply(-1);
    return clone;
}

/** Overloads + to return a copy of the polynomial
    @return clone is a copy of the polynomial
 */
Polynomial Polynomial::operator+() const{
    Polynomial clone = *this;
    return clone;
    
}

