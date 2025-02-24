#include <iostream>
#include <fstream>
#include <string>

void replace_in_file(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std :: ifstream input_file(filename.c_str());
    if (!input_file.is_open())
    {
        std::cerr << "Error: Unable to open the input file.\n";
        return;
    }
    std :: string new_filename = filename + ".replace";
    std :: ofstream output_file(new_filename.c_str());
    if (!output_file.is_open())
    {
        std::cerr << "Error: Unable to create the output file.\n";
        return;
    }
    std :: string line;
    while (std::getline(input_file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        output_file << line << '\n';
    }
    input_file.close();
    output_file.close();
    std :: cout << "File successfully modified and saved as " << new_filename << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std :: endl;
        return (1);
    }
    std :: string filename = argv[1];
    std :: string s1 = argv[2];
    std :: string s2 = argv[3];
    replace_in_file(filename, s1, s2);
    return 0;
}
