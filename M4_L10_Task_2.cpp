/*
В этом задании вы переопределите остальные операторы для класса дроби.

Необходимо переопределить операторы для класса Fraction из предыдущего задания:

сложение;
вычитание;
умножение;
деление;
унарный минус;
инкремент постфиксный и префиксный;
декремент постфиксный и префиксный.
Продемонстрируйте работу ваших операторов. Попросите пользователя ввести две дроби и покажите результат каждой операции. Операции декремента и инкремента отнимают и прибавляют к дроби 1 соответственно.

Составьте выражения, содержащие постфиксный и префиксный инкремент и декремент, чтобы продемонстрировать разницу между постфиксной и префиксной версиями.

Пример работы программы
Консоль
Введите числитель дроби 1: 3
Введите знаменатель дроби 1: 4
Введите числитель дроби 2: 4
Введите знаменатель дроби 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
Значение дроби 1 = 7/4
7/4-- * 4/5 = 7/5
Значени дроби 1 = 3/4
*/
#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Fraction operator + (const Fraction& other) const
    {
        int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator - (const Fraction& other) const
    {
        int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator * (const Fraction& other) const
    {
        int newNumerator = numerator_ * other.numerator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator / (const Fraction& other) const
    {
        int newNumerator = numerator_ * other.denominator_;
        int newDenominator = denominator_ * other.numerator_;
        return Fraction(newNumerator, newDenominator);
    }
    Fraction operator-()
    {
        return Fraction(-numerator_, denominator_);
    }
    Fraction operator++()
    {
        numerator_ += denominator_;
        return *this;
    }
    Fraction operator++(int)
    {
        Fraction temp(numerator_, denominator_);
        numerator_ += denominator_;
        return temp;
    }
    Fraction operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction temp(numerator_, denominator_);
        numerator_ -= denominator_;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const Fraction& fraction)
    {
        os << fraction.numerator_ << "/" << fraction.denominator_;
        return os;
    }


};

int main()
{
    Fraction f1(3, 4);
    Fraction f2(4, 5);

    cout << f1 << " + " << f2 << " =" << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " =" << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " =" << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " =" << (f1 / f2) << endl;
    cout << ++f1 << " * " << f2 << " =" << (f1 * f2) << endl;
    cout << f1-- << " * " << f2 << " =" << (f1 * f2) << endl;

    return 0;
}