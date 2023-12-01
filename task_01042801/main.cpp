/*
  ����� �������� ��������, �������� ��������� �������� �� �������� �������� std::unique_ptr
�� ��������� ������ �������� ����� ��� ���������� ������������ �����
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

    // ����� ��� ����������� ���������� �������� ������� (���)
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

    // ����� ��� ���������� ������������� �����
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

    // ������������� std::unique_ptr ������ ���������� ���������
    std::unique_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

    // ���� ������������� �����
    std::cout << "�� ����������: ";
    printFraction(ptr);

    // ���������� ������������� �����
    ptr->reduce();

    std::cout << std::endl;

    // ���� ����� ���� ����������
    std::cout << "ϳ��� ����������: ";
    printFraction(ptr);

    // ���� ������� ������ �������� ��'���, ������� ��������������� std::unique_ptr

    return 0;
}
