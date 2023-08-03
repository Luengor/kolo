#include <iostream>
#include <string>

static const char helpstr[] = "Usage: kolo <color> [text]\n";

int main(int argc, char* argv[])
{
    /// Parse command line arguments
    if (argc != 2 && argc != 3)
    {
        std::cout << helpstr;
        return 1;
    }

    std::string color = argv[1];
    if (color[0] != '#')
        color = std::string("#") + color;
    
    if (color.length() != 7)
    {
        std::cout << "Invalid color: " << color << "\n";
        return 2;
    }

    std::string text = argc == 3 ? argv[2] : color;

    /// Print the text 
    // Change background color
    std::cout << "\033[48;2;"
              << (int)std::stoi(color.substr(1, 2), nullptr, 16) << ";"
              << (int)std::stoi(color.substr(3, 2), nullptr, 16) << ";"
              << (int)std::stoi(color.substr(5, 2), nullptr, 16) << "m";
    
    // Change text color
    float lum = 0.2126 * std::stoi(color.substr(1, 2), nullptr, 16) +
                0.7152 * std::stoi(color.substr(3, 2), nullptr, 16) +
                0.0722 * std::stoi(color.substr(5, 2), nullptr, 16);
    
    if (lum > 128)
        std::cout << "\033[38;2;0;0;0m";
    else
        std::cout << "\033[38;2;255;255;255m";

    // Print block
    for (int y = 0; y < 5; y++)
    {
        // If its not the middle line, print white spaces
        if (y != 2)
        {
            for (int x = 0; x < text.length() + 4; x++)
                std::cout << " ";

        }

        // If it is, print the line
        else
        {
            std::cout << "  " << text << "  ";
        }

        std::cout << "\n";
    }
}
