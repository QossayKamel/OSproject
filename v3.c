
//Qossay Kamel
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include<stdbool.h>
//help menu : to let the user know the shell commands
void helpc(char *(Qossay)){
Qossay="The Shell Use these Command\n"
"pwd   Prints the current working Directory\n"
"cd    Change the working Directory\n"
"kill  Kills running processes selected form user\n"
"ps    List the currently running processes\n"
"exit  Exit from the Shell\n"
"help  Prints the user manual\n"
;
printf("%s",Qossay);
}
//Exit command 
void exitc(char*(Qossay)){
exit(0);
}
//pwd command : to let user know curent directory
void pwd(){
char cwd[100];
//current working
getcwd(cwd, sizeof(cwd));
printf("Current Directory: %s", cwd);
printf("\n");
}
//cd command : change the directory of the user

   void cd(char *(Qossay)){
     //first case of cd
 if(strcmp(Qossay,"..")==0){
   chdir("..");
    pwd();
   
    }
   //2nd case of cd
 else if(strcmp(Qossay,"../")==0){
     chdir("../");
      pwd();
       }
   //3rd case of cd
 else{ 
       chdir(Qossay);
        pwd();

}
}
