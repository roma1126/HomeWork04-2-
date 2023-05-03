#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string City;
    std::string Street;
    int HouseNumber;
    int FlatNumber;

public:

    Address()
    {
        City = "0";
        Street = "0";
        HouseNumber = 0;
        FlatNumber = 0;
    }

    Address(std::string NameOfTheCity, std::string NameOfTheStreet, int NumberOfTheHouse, int NumberOfFlat)
    {
        City = NameOfTheCity;
        Street = NameOfTheStreet;
        HouseNumber = NumberOfTheHouse;
        FlatNumber = NumberOfFlat;
    }


    std::string get_output_adress() 
    {
        std::string address_string = City + ", " + Street + ", " + std::to_string(HouseNumber) + ", " + std::to_string(FlatNumber) + "\n";
        return address_string;
    }

    std::string get_city() 
    {
        return this -> City;
    }

   static void sort(Address* adress_array, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            std::string swapping;

            for (int j = i; j > 0; j--)
            {
                if (adress_array[j].get_city() > adress_array[j + 1].get_city())
                {
                    std::swap(adress_array[j], adress_array[j + 1]);

                }
            }
        }
    }
    
};


int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream file_in("in.txt");
    std::ofstream file_out("out.txt");

    if (!file_in)
    {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
    }
    else
    {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    int size = 0;
    std::string City, Street;
    int HouseNumber, FlatNumber;
    std::string string_sort;

    file_in >> string_sort;
    file_out << string_sort << "\n";
    size = stoi(string_sort);
    Address* adress_array = new Address[size];
    for (int i = 0; i < size; i++)
    {
        file_in >> City >> Street >> HouseNumber >> FlatNumber;
        adress_array[i] = { City, Street, HouseNumber,FlatNumber };
    }
    adress_array->sort(adress_array, size);

    for (int i = 0;i < size;i++)
    {
        file_out << adress_array[i].get_output_adress();
    }
   
    file_in.close();
    file_out.close();
    delete[] adress_array;
    return 0;

}



