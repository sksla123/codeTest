//          ,r'"7
// r`-_   ,'  ,/
//  \. ". L_r'
//    `~\/
//       |
//       |

// #include <stdio.h>

// int main() {
//     printf("         ,r'\"7\n");
//     printf("r`-_   ,'  ,/\n");
//     printf(" \\. \". L_r'\n");
//     printf("    `~\\/\n");
//     printf("       |\n");
//     printf("       |");

//     return 0;
// }

#include <stdio.h>

int main() {

    printf("         ,%c\'\"%d\n",'r',7); // (a)
    printf("%c`-_   ,\'  ,/\n",'r'); 
    printf(" \\. \". %c_%c\'\n",'L','r'); // 
    printf("   `~\\/\n");
    printf("      |\n");
    printf("      |\n");    
    return 0;    
}