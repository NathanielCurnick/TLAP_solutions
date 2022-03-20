#include <string>;
using std::string;

class Car
{
public:
    int get_model_year();
    void set_model_year(int model_year);

    string get_model_name();
    void set_model_name(string model_name);

    string get_manufacturer();
    void set_manufacturer(string manufacturer);

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