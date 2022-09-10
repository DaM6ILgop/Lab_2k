#include <iostream>
using namespace std;

const char* reverseChar(const char* s, int CharElement)
{
    
    int len = 0; 
     /*указатель на оставшуюся часть строки (его нужно вернуть)*/
    const char* rest_of_string = " ";

     /*проходим до конца строки пока не упремся в несуществующий элемент*/
    
    while (s[len] != '\0') {
       
        if (s[len] == CharElement)
           /*запоминаем указатель на него*/
            rest_of_string = s + len;
        len++;
    }
     /*возвращаем последний присвоенный указатель*/
     
        return rest_of_string;
}

char *strs(const char *s, const char *symbol){
    do {
        if (*s == *symbol) {

            const char* buf = symbol;
            int k=0;

            while (*s == *buf++ && *s){
                s++;
                k++;
            }
            if (k == strlen(symbol)) { //Возвращает длинну строки, оканчивающейся нулевым символом 
                return (char*)s - k;
            }
        }
    }
    while (*s++);
    return 0;
}

int main(){

    setlocale(LC_ALL, "ru");

    // тестовая строка
    char s[] = "www.some_address.and_something_else.com";

    const char* standard_result = strrchr(s, '.');
    
    const char* str = "the really hard work";
    
    char *str_2 = strs(str, "hard");

    printf("Initial string: %s\nStandard: %s\nMy version: %s\n",
        s, standard_result, str_2);
    
}