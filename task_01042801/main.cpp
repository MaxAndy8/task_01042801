/*
  Змініть наступну програму, замінивши звичайний вказівник на розумний вказівник std::unique_ptr
На додаткову оцінку допишіть метод для скорочення раціональних дробів
*/
#include <iostream>
#include <memory>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }

    // Метод для знаходження найбільшого спільного дільника (НСД)
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Метод для скорочення раціонального дробу
    void reduce()
    {
        int commonFactor = gcd(m_numerator, m_denominator);
        m_numerator /= commonFactor;
        m_denominator /= commonFactor;
    }
};

void printFraction(const std::unique_ptr<Fraction>& ptr)
{
    if (ptr)
        std::cout << *ptr;
}

int main()
{
    system("chcp 1251>nul");

    // Використовуємо std::unique_ptr замість звичайного вказівника
    std::unique_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

    // Друк раціонального дробу
    std::cout << "До скорочення: ";
    printFraction(ptr);

    // Скорочення раціонального дробу
    ptr->reduce();

    std::cout << std::endl;

    // Друк знову після скорочення
    std::cout << "Після скорочення: ";
    printFraction(ptr);

    // Немає потреби вручну видаляти об'єкт, оскільки використовується std::unique_ptr

    return 0;
}
