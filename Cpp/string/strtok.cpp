#include <cstring>
#include <iostream>

using namespace std;

// int main(){
//     char str[80] = "a b c d e f g h.";

//     char *token;

//     //获取第一个子字符串
//     token = strtok(str, " ");
//     while (token != NULL){
//         cout << token << endl;
//         token = strtok(NULL, " ");
//     }

//     for (int i = 0; i < 16; i++){
//         if (str[i] == '\0')
//             printf("\\0");
//         printf("%c", str[i]);               //切分字符" "被更改成了"\0"
//     }

//     return 0;
// }

int main(){
    char *a = "aaa";
    char *A = "AAa";
    cout << strcmp(a, A) << endl;

    const char *b = "baa";
    const char *bb = "aaa";
    cout << strcmp(b, bb) << endl;

    return 0;
}

