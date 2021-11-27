#include <fstream>
#include "Save.h"

bool Save::save(const std::string& path) {
    std::ofstream file(path);
    if (file.fail()) return false;
    file << convertJSON();
    file.close();
    return true;
}
