#include <iostream>
#include <string>
#include <stdexcept>

class Document {
    private:
        std::string name;
        int size;
        std::string month;
        int day;
        int year;
    public:
        Document(std::string name, int size, std::string month, int day, int year) {
            this->name = name;
            if (size >= 0) {
                this->size = size;
            }
            else {
                throw std::runtime_error("invalid size " + std::to_string(size));
            }
            this->month = month;
            this->day = day;
            this->year = year;
        }
        std::string get_name() const {
            return name;
        }
        int get_size() const {
            return size;
        }
        std::string get_date() const {
            return month + " " + std::to_string(day) + " " + std::to_string(year);
        }
        std::string to_string() const {
            return "name=" + name + " size=" + std::to_string(size) + " date=" + month + " " + std::to_string(day) + " " + std::to_string(year);
        }
        void set_size(int size) {
            if (size >= 0) {
                this->size = size;
            }
            else {
                throw std::runtime_error("invalid size " + std::to_string(size));
            }
        }
        void set_date(std::string month, int day, int year) {
            this->month = month;
            this->day = day;
            this->year = year;
        }
        bool equals(Document doc) const {
            return this->name == doc.name && this->size == doc.size && this->month == doc.month && this->day == doc.day && this->year == doc.year;
        }
};

int main()
{
  // name, positive size (passed as signed int), month, day, year
  // assume the date is valid
  const Document doc1("Comp2400.java", 200, "Oct", 25, 2025);
  const Document doc2("Final Report.txt", 5000, "Sep", 19, 2025);
  const Document doc3(doc2.get_name(), doc2.get_size() + 100, "Sep", 22, 2025);

  std::cout << "doc1: " << doc1.to_string() << "\n";
  std::cout << "doc2: " << doc2.to_string() << "\n";
  std::cout << "doc3: " << doc3.to_string() << "\n";

  try {
    Document doc_bad("Bad.doc", -500, "Sep", 19, 2025);
  } catch (const std::runtime_error &re) {
    std::cout << "unable to create doc_bad: " << re.what() << "\n";
  }

  std::cout << "doc3's date: " << doc3.get_date() << "\n";

  // this will make a copy of doc2
  Document doc4(doc2);

  std::cout << "doc4: " << doc4.to_string() << "\n";
  
  doc4.set_size(doc4.get_size() + 100);
  doc4.set_date("Sep", 22, 2025);

  std::cout << "doc4: " << doc4.to_string() << "\n";

  // note that there's nothing "special" about a method called equals in C++
  std::cout << "doc2.equals(doc3) ? " << doc2.equals(doc3) << "\n";
  std::cout << "doc2.equals(doc4) ? " << doc2.equals(doc4) << "\n";
  std::cout << "doc3.equals(doc4) ? " << doc3.equals(doc4) << "\n";

  try {
    doc4.set_size(-10);
  } catch (const std::runtime_error &re) {
    std::cout << "unable to change size: " << re.what() << "\n";
  }
}