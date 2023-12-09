#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
    std::string city, street, house, apartment;
};

bool compareAddresses(const Address& a, const Address& b) {
    return a.city < b.city;
}

int main() {
    std::ifstream input("in.txt");
    std::ofstream output("out.txt");

    int N;
    input >> N;

    Address* addresses = new Address[N];

   // Address addresses[N];

    for (int i = 0; i < N; i++) {
        input >> addresses[i].city >> addresses[i].street >> addresses[i].house >> addresses[i].apartment;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (addresses[j].city > addresses[j + 1].city) {
                std::swap(addresses[j].city, addresses[j + 1].city);
                std::swap(addresses[j].street, addresses[j + 1].street);
                std::swap(addresses[j].house, addresses[j + 1].house);
                std::swap(addresses[j].apartment, addresses[j + 1].apartment);
            }
        }
    }

    // Запись отсортированных адресов в файл out.txt
    output << N << std::endl;
    for (int i = 0; i < N; i++) {
        output << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].house << ", " << addresses[i].apartment << std::endl;
    }

    input.close();
    output.close();
    delete[] addresses;

    return 0;
}