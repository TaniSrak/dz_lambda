#include <iostream>
#include <functional>

//���� �������
double calculator(double arg1, double arg2, const std::function<double(double, double)>& operation)
{
    return operation(arg1, arg2);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;

    double arg1, arg2;
    char operation;

    std::cout << "������� 1 ��������: ";
    std::cin >> arg1;

    std::cout << "������� 2 ��������: ";
    std::cin >> arg2;

    std::cout << "�������� �������������� �������� (+, -, *, /): ";
    std::cin >> operation;

    std::function<double(double, double)> func;

    //������ ������ � ����������� �� ��������
    switch (operation)
    {
    case '+':
        func = [](double a, double b) { return a + b; }; break;
    case '-':
        func = [](double a, double b) { return a - b; }; break;
    case '*':
        func = [](double a, double b) { return a * b; }; break;
    case '/':
        func = [](double a, double b) { return (b != 0) ? a / b : 0; }; break;// �� ���� ������� �� ����
    default:
        std::cerr << "������ ������ �� ���� ������ " << std::endl;
        return 1;
    }

    // ���������
    double result = calculator(arg1, arg2, func);

    std::cout << "���������: " << result << std::endl;

    return 0;
}