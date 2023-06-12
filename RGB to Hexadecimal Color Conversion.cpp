#include <iostream>
using namespace std;
#include <string>
string reverseString(string str) {
    string result;
    for (int i = str.length() - 1;i >= 0;i--) {
        result += str[i];
    }
    return result;
}

string leadZero(string str) {
    if (str.length()<2) {
        return '0' + str;
    }
    else {
        return str;
    }
}
string convertIntToHex(int number) {
    char letters[6] = { 'A','B','C','D','E','F' };
    string result;
    do {
        int remainder = number % 16;
        number /= 16;
        if (remainder < 10) {
            result += to_string(remainder);
        }
        else {
            result += letters[remainder - 10];
        }
    } while (number > 0);

    result = reverseString(result);
    return result;
}

string convertRGBtoHex(int R, int G, int B) {
    string red = leadZero (convertIntToHex(R));
    string green = leadZero (convertIntToHex(G));
    string blue = leadZero (convertIntToHex(B));
    return "#" + red + green + blue;
}

int main()
{
    int r, g, b;
    string placeholder = ", ";
    cout << "Enter an RGB color int the format r, g, b: ";
    cin >> r >> placeholder >> g >> placeholder >> b;
    cout << "The hexadecimal equivalent is: " << convertRGBtoHex(r, g, b);

    
}

