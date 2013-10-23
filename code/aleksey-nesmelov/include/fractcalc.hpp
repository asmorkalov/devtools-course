class Fraction
{
 public:
   Fraction (int numenator = 0, int denominator = 1);
   ~Fraction();

    int GetNumenator();
    int GetDenominator();
    void SetNumenator(int numenator);
    void SetDenominator(int denominator);

    static Fraction Add(Fraction a, Fraction b);
    static Fraction Sub(Fraction a, Fraction b);
    static Fraction Mul(Fraction a, Fraction b);
    static Fraction Div(Fraction a, Fraction b);

 private:
   int numenator;
   int denominator;
   int NOD();
   void CutFraction();
};
