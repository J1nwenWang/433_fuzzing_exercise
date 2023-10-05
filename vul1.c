#include <stdio.h>
#include <string.h>
char* GetPasswd(){

    return "1337";
}

/**
 * YesWeHack - Vulnerable Code Snippet
*/

// Run: gcc vul1.c -fno-stack-protector -o vul1
// Then run the program: ./vul1

int LoadDashboard(){
    printf("> To dashboard loading\n");
    return 0;
}

int main(void)
{
    char *passwd = GetPasswd();
    int root = 0;
    char tryPasswd[4];

    for ( int tries = 0; tries < 3; tries++ ) {
        printf("Enter Passwd (Four digits): ");
        gets(tryPasswd);
    
        //Check if the user has root privileges or OPT:
        if ( root || strcmp(tryPasswd, passwd) == 0 ) {
            printf("> Success, loading dashboard\n");
            LoadDashboard();
            return 1;
        } else {
            printf ("> Incorrect Passwd\n");
        }
     
        if ( tries >= 3 ) {
            return 0;
        }
    }
}
