#include <iostream>
#include <cstdlib>
#include <format>
#include <Windows.h>

using namespace std;

class MorsAlphabet {
private:
    string get;
    string parse;
    int short_time = 150;
    int long_time = 300;
    BYTE short_color = DarkBlue;
    BYTE long_color = DarkGreen;
    BYTE text_color = White;
    void Get() { cin >> get; };
    void Parse(string v) {
        parse.clear();
        for (auto& i : v) {
            switch (i) {
            case 'a': case 'A': parse += "+-";  break;
            case 'b': case 'B': parse += "-+++";break;
            case 'c': case 'C': parse += "-+-+";break;
            case 'd': case 'D': parse += "--+"; break;
            case 'e': case 'E': parse += "+";   break;
            case 'f': case 'F': parse += "++-+";break;
            case 'g': case 'G': parse += "--+"; break;
            case 'h': case 'H': parse += "++++";break;
            case 'i': case 'I': parse += "++";  break;
            case 'j': case 'J': parse += "+---";break;
            case 'k': case 'K': parse += "-+-"; break;
            case 'l': case 'L': parse += "+-++";break;
            case 'm': case 'M': parse += "--";  break;
            case 'n': case 'N': parse += "-+";  break;
            case 'o': case 'O': parse += "---"; break;
            case 'p': case 'P': parse += "+--+";break;
            case 'q': case 'Q': parse += "--+-";break;
            case 'r': case 'R': parse += "+-+"; break;
            case 's': case 'S': parse += "+++"; break;
            case 't': case 'T': parse += "-";   break;
            case 'u': case 'U': parse += "++-"; break;
            case 'v': case 'V': parse += "+++-";break;
            case 'w': case 'W': parse += "+--"; break;
            case 'x': case 'X': parse += "-++-";break;
            case 'y': case 'Y': parse += "-+--";break;
            case 'z': case 'Z': parse += "--++";break;
            }
            parse += ' ';
        }
    };
    void Read() {
        for (auto& i : parse)
            if (i == '+') {
                system(string(string("color ") + std::format("{:x}", short_color * 16 + text_color)).c_str());
                Sleep(short_time);
            }
            else if (i == '-') {
                system(string(string("color ") + std::format("{:x}", long_color * 16 + text_color)).c_str());
                Sleep(short_time);
            }
            else {
                system("color 0f");
                Sleep(long_time + 100);
            };
        system("color 0f");
    };
public:
    enum Color {
        Black = 0,
        DarkBlue = 1,
        DarkGreen = 2,
        DarkCyan = 3,
        DarkRed = 4,
        DarkMagenta = 5,
        DarkYellow = 6,
        Grey = 7,
        Dark_grey = 8,
        Blue = 9,
        Green = 10,
        Cyan = 11,
        Red = 12,
        Purple = 13,
        Yellow = 14,
        White = 15
    };
    BYTE& ShortColor() { return short_color; };
    BYTE& LongColor() { return long_color; };
    BYTE& TextColor() { return text_color; };
    int& ShortTime() { return short_time; };
    int& LongTime() { return long_time; };
    void Run() {
        repeat:
        Get();
        Parse(get);
        Read();
        system("cls");
        goto repeat;
    };
};

int main() {
    MorsAlphabet app;
    app.Run();
    return 0;
}
