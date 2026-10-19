#include <iostream>
#include <string>

class PhoneNumber {
    public:
        std::string area_code;
        std::string number;
        PhoneNumber() = default;

        PhoneNumber(int area, int num) {
            area_code = std::to_string(area);
            number = std::to_string(num);
        }

        std::string get_area_code() const {
            return area_code;
        }
        std::string get_number() const {
            return number;
        }
        std::string to_string() const {
            return "(" + area_code + ") " + number.substr(0,3) + "-" + number.substr(3,7);
        }
};

class Phone {
    private:
        std::string description;
        PhoneNumber number;
        bool has_number = true;
    public:
        Phone(std::string description) {
            this->description = description;
            this->number = PhoneNumber(204, 5551234);
            number.area_code = "000";
            number.number = "0000000";
            has_number = false;
        }
        Phone(std::string description, PhoneNumber number) {
            this->description = description;
            this->number = number;
        }

        std::string get_description() const {
            return description;
        }

        PhoneNumber get_number() const {
            return number;
        }

        void change_number(PhoneNumber number) {
            this->number = number;
        }

        std::string to_string() const {
            std::string type = "description: " + description + " ";
            std::string ac = "number: (" + number.area_code + ") ";
            std::string first = number.number.substr(0,3);
            std::string last = "-" + number.number.substr(3,7);
            return type + ac + first + last;
            // if (has_number) {
            //     std::string ac = "(" + std::to_string(number.area_code) + ") ";
            //     std::string first = std::to_string(number.number).substr(0,3);
            //     std::string last = "-" + std::to_string(number.number).substr(3,7);
            //     return type + ac + first + last;
            // }
            // else {
            //     return type;
            // }
        }
};

int main()
{
  // immutable phone number: area code, number (no error checking required)
  const PhoneNumber u_of_m_number(800, 4321960);
  // mutable phone: description, optional number (stored as an object *not* a pointer)
  Phone u_of_m("landline", u_of_m_number);
  Phone phone1("iphone");
  const Phone phone2("samsung galaxy", PhoneNumber(204, 5551234));
  Phone phone3 = phone2;
  
  std::cout << "u_of_m_number area code: " << u_of_m_number.get_area_code() << "\n";
  std::cout << "u_of_m_number number: " << u_of_m_number.get_number() << "\n";
  std::cout << "u_of_m_number: " << u_of_m_number.to_string() << "\n";

  std::cout << "u_of_m: " << u_of_m.to_string() << "\n";
  std::cout << "phone1: " << phone1.to_string() << "\n";
  std::cout << "phone2: " << phone2.to_string() << "\n";
  std::cout << "phone3: " << phone3.to_string() << "\n";
  
  std::cout << "phone1 get_description: " << phone1.get_description() << "\n";
  std::cout << "phone2 get_description: " << phone2.get_description() << "\n";

  const PhoneNumber &number1 = phone1.get_number();
  const PhoneNumber &number2 = phone2.get_number();

  std::cout << "phone1's number: " << number1.to_string() << "\n";
  std::cout << "phone2's number: " << number2.to_string() << "\n";
  
  phone1.change_number(number2);
  // not allowed: phone2.change_number(number2);
  phone3.change_number(u_of_m_number);
  
  std::cout << "phone1: " << phone1.to_string() << "\n";
  std::cout << "phone2: " << phone2.to_string() << "\n";
  std::cout << "phone3: " << phone3.to_string() << "\n";
}