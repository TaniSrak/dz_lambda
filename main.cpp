#include <iostream>
#include <functional>

//сама функция
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

    std::cout << "Введите 1 аргумент: ";
    std::cin >> arg1;

    std::cout << "Введите 2 аргумент: ";
    std::cin >> arg2;

    std::cout << "Выберите математическую операцию (+, -, *, /): ";
    std::cin >> operation;

    std::function<double(double, double)> func;

    //задаем лямбду в зависимости от операции
    switch (operation)
    {
    case '+':
        func = [](double a, double b) { return a + b; }; break;
    case '-':
        func = [](double a, double b) { return a - b; }; break;
    case '*':
        func = [](double a, double b) { return a * b; }; break;
    case '/':
        func = [](double a, double b) { return (b != 0) ? a / b : 0; }; break;// не даем деления на ноль
    default:
        std::cerr << "НЕльзя делить на ноль тупица " << std::endl;
        return 1;
    }

    // вычисляем
    double result = calculator(arg1, arg2, func);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}