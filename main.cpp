#include <iostream>
#include <cassert>
#include "hash_table.h"

int main() {
    UnorderedMap<std::string> hash_table;
    UnorderedMap<std::string> hash_table_f;
    Winners<std::string> w;

    std::cout <<"Insert res: " << hash_table.insert("1", 5) << std::endl;
    // success insert
    assert(hash_table["1"] == 5);

    // three max;
    hash_table.insert("12", 12);
    hash_table.insert("21", 21);
    hash_table.insert("31", 31);

    std::cout << "size of hash-table= " << hash_table.size() << std::endl;

    assert(hash_table.find("21") == 1);
    assert(hash_table.find("-100") != 1);

    // copy constructor
    UnorderedMap<std::string> hash_table_c = UnorderedMap(hash_table);
    assert(hash_table_c.find("21") == 1);

    // winners test
    w = hash_table.get_winners();
    std::cout<< "the winners: ";
    std::cout << w.first << " " << w.second << " " << w.other <<std::endl;

    hash_table.erase("12");
    assert(hash_table.find("12") != 1);

    std::cout << "Save result: ";
    std::cout << hash_table.save("C:/Users/Nick/Documents/HSE/2_Course/Obj_programming/lab_2/save.txt")
              << std::endl;

    std::cout << "Load result: ";
    std::cout << hash_table_f.load("C:/Users/Nick/Documents/HSE/2_Course/Obj_programming/lab_2/save.txt")
              << std::endl;

    assert(hash_table_f.find("21") == 1);
    assert(hash_table_f.find("12") != 1);
    assert(hash_table_f.find("31") == 1);
    assert(hash_table_f.find("1") == 1);
    return 0;
}
