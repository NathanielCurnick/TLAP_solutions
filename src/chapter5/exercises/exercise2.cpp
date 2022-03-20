#include <string>
#include <ctime>
#include <iostream>
using std::cout;
using std::string;
using std::to_string;
class Car
{
public:
    int get_model_year();
    void set_model_year(int model_year);

    string get_model_name();
    void set_model_name(string model_name);

    string get_manufacturer();
    void set_manufacturer(string manufacturer);

    string format_car();
    int get_age();

private:
    int _model_year;
    string _model_name;
    string _manufacturer;
};

int Car::get_model_year()
{
    return _model_year;
}

void Car::set_model_year(int model_year)
{
    _model_year = model_year;
}

string Car::get_model_name()
{
    return _model_name;
}

void Car::set_model_name(string model_name)
{
    _model_name = model_name;
}

string Car::get_manufacturer()
{
    return _manufacturer;
}

void Car::set_manufacturer(string manufacturer)
{
    _manufacturer = manufacturer;
}

string Car::format_car()
{
    string format = "";
    format.append(to_string(get_model_year()));
    format.append(" ");
    format.append(get_manufacturer());
    format.append(" ");
    format.append(get_model_name());

    return format;
}

int Car::get_age()
{
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    int year = 1900 + pTInfo->tm_year;
    return year - get_model_year();
}

void test_format()
{
    Car car = Car();
    car.set_model_year(1957);
    car.set_manufacturer("Chevrolet");
    car.set_model_name("Impala");

    cout << car.format_car() << "\n";
}

void test_age()
{
    Car car = Car();
    car.set_model_year(1957);
    car.set_manufacturer("Chevrolet");
    car.set_model_name("Impala");

    cout << "Car is " << car.get_age() << " years old\n";
}

int main()
{
    test_format();
    test_age();
}