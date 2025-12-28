#include <iostream>
#include <locale.h>
#include <unordered_map>
using namespace std;
void toMorse (const char* arr)
{
    unordered_map < char, string > alphabet = {{'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
   {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},
   {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}};
   for (int i = 0; arr[i] != '\0'; i++)
    cout << alphabet[arr[i]] << " ";
}
void toText (const char* arr)
{
    unordered_map < string, char > alphabet = {{".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'},
   {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},
   {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'}};
   string current = "";
   for (int i = 0; arr[i] != '\0'; i++)
   {
       if (arr[i] != ' ')
       {
           current += arr[i];
       }
       else
       {
           cout << alphabet[current] << " ";
           current = "";
       }
   }
}
int main()
{
   setlocale(LC_ALL, "Russian");
   char* str = new char[100];
   int i = 0;
   str[0] = getchar();
   for (i = 1; i < 100; i++)
   {
       if (str[i - 1] == '\n')
        break;
       str[i] = getchar();
   }
   toText(str);
   delete[] str;
}
