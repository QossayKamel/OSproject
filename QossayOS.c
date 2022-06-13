
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
   cc
}
//kill command : to kill the process you want

void ikill(pid_t pid, int sig) {
    if (kill(pid, sig) == -1) {
        char *temp = calloc(sizeof(char), 64);
        sprintf(temp, "ikill (pid: %d , sig: %d)", pid, sig);
 perror(temp);
 free(temp);
    }
}
void killc(char*(Qossay)) {
  //declearing the process id  and sig variable
    pid_t pid;
    int sig;
  
// giving the variable pid the id of the process
  pid =atoi(Qossay);   

 sig = SIGTERM;
  ikill(pid, sig);
  
  }
//ps_A command : to know the list of process that aren't killed
void ps_A(){

    printf("PID    TTY     TIME     CMD\n");
 // opening the file by the dirctory name 
    DIR *f1;
    struct dirent *dir;
    f1 = opendir("/proc");
 
    if (f1) {
        while ((dir = readdir(f1)) != NULL){

   char ma[500];

   snprintf(ma,500, "/proc/%s/stat", dir->d_name);

      if (dir->d_name[0]<48 || dir->d_name[0]>57 )  
               continue;

 //to know the methods that aren't killed 
int kil = atoi(dir->d_name);

 if (kill(kil, 0) != 0)

 continue;

  int i;
  char name[30];
  int utime,stime;
// opening new file to read from the variable ma 
  FILE *fq = fopen(ma, "r");

   fscanf(fq,"%d %s", &i,name);
   char gf[30];
   int j = 1;

 

 
// calculiting time 
  int time = stime+utime;
//converting from time of computer to seconeds
  int t = time/sysconf(_SC_CLK_TCK);
  char a[40];

  snprintf(a, 40, "/proc/%s/fd/0", dir->d_name);

 int ff;
 //storing the value of a and O_RDONLY variables in the file ff
 ff = open(a, O_RDONLY);

 char *ttyP;
 ttyP = ttyname(ff);

 if (ttyP) {
             printf("%d %5s\t%2d %7s\n", i, ttyP, t, name);
 }else{
printf("%d\t?\t%2d %7s\n", i, t, name);
 }

  }

}

}

//ps command : to know the list of all process 
void ps(){

    printf("PID    TTY     TIME     CMD\n");
   // opening the file by the dirctory name 
    DIR *f2;
    struct dirent *dir;
    f2 = opendir("/proc");

    if (f2)

    {
        while ((dir = readdir(f2)) != NULL)

        {

   char ma[500];

   snprintf(ma,500, "/proc/%s/stat", dir->d_name);

      if (dir->d_name[0]<48 || dir->d_name[0]>57 )

 continue;


  int i;
  char name[30];
  char stat;
  int utime,stime;

   FILE *fq = fopen(ma, "r");

   fscanf(fq,"%d %s", &i,name);
            char gf[30];
            int j = 1;

  

            
// calculiting time 

  int time = stime+utime;
//converting from time of computer to seconeds
 int t = time/sysconf(_SC_CLK_TCK);
  char a[40];
  snprintf(a, 40, "/proc/%s/fd/0", dir->d_name);
 //storing the value of a and O_RDONLY variables in the file ff
 int ff;
 ff = open(a, O_RDONLY);
  char *ttyP;

  ttyP = ttyname(ff);

 if (ttyP) {
             printf("%d %5s\t%2d %7s\n", i, ttyP + 5, t, name);
 }else{
             printf("%d\t?\t%2d %7s\n", i, t, name);

 }

  }

}

}
// a menu method to list the shell commends 
int value(char*(qp)){
  int amountOfCommands = 7, i, switchO = 0;
	char *commandsList[amountOfCommands];


	commandsList[0] = "pwd";  // Case 1
	commandsList[1] = "cd";	  // Case 2
	commandsList[2] = "ps";	  // Case 3
	commandsList[3] = "ps-A"; // Case 4
	commandsList[4] = "kill"; // Case 5
  commandsList[5] = "exit"; // Case 6
  commandsList[6] = "help"; // Case 7
	for (int i = 0; i < amountOfCommands; i++)
	{
		if (strcmp(qp, commandsList[i]) == 0)
		{
			switchO = i + 1;
			break;
		}
	}

  // to let the user calling the shell commands
  
	switch (switchO)
	{
	case 1:
		pwd(); // zero 
	return 1;
	case 2:
    qp=strtok(NULL," ");
	cd(qp);
    return 1;
	case 3:
		ps();

  return 1;
    case 4:
  ps_A();
	return 1;
	case 5:
  killc(qp);
	return 1;
	
	case 6:
		printf("\nExiting out of Shell Program Now!\n\n");
		exit(0);

    case 7:
  helpc(qp);
	return 1;
return 1;
	default:
		break;
	}
}
//Main method 
 int main(){
    printf("Chose your command number\n");
    printf("1)cd\n2)pwd\n3)ps\n4)ps_A\n5)kill\n6) exit\n7)help\n");
 while(1){
    printf("Enter:\n");
 char Qossay [100];
 gets(Qossay);
   char * q=strtok(Qossay," ");
    while( q != NULL ) {
      value(q); //printing each token
      q = strtok(NULL, " ");
   
}
   }
	return 0; 
}



