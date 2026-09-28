#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include "tztable.h"

/*it's not case sensitive
returns the offset
returns -1 if it doesn't find it*/
int findintable(char *what){
    for(size_t i = 0; i < TZTABLE_LENGHT; i++){
        if((strcasecmp(what, tz_table[i].zn)) == 0){
        return tz_table[i].offset; 
        }
    }
return -1; 
}

davidtime strtimetoint(char *whattimeisit) {
    davidtime timehoursandminutes = {0, 0};

    if (whattimeisit == NULL)return timehoursandminutes;

    char buf[16];
    strncpy(buf, whattimeisit, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *token = strtok(buf, ":");
    if (token == NULL) return timehoursandminutes;
    timehoursandminutes.hour = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL) return timehoursandminutes;
    timehoursandminutes.minutes = atoi(token);

    return timehoursandminutes;
}

int convert(char *timey, char *zone){
    time_t rawtime = time(NULL);
    struct tm *ptm = gmtime(&rawtime);
    
    ptm->tm_isdst = -1;                
    time_t gmt = mktime(ptm);
    int offset = difftime(rawtime, gmt) / 60;
    //this sould take even daylight savings too, i stole it from stack overflow i've been trying to not use llms to code shit like this

    //tmzn hour --> utc00 --> local time 
    if(findintable(zone)== -1){
        return -1;
    }
    int zntime = findintable(zone);

    davidtime eugh = strtimetoint(timey); 
    int zonetimeminutes = (eugh.hour*60)+eugh.minutes;
    int normalizedminutes = zonetimeminutes+(zntime*-1); //utc00

    int localminutes = (normalizedminutes+offset) % 1440;  

    davidtime finally; 
    finally.hour = localminutes/60;
    finally.minutes = localminutes - finally.hour*60;
    printf("%02d:%02d\n",finally.hour,finally.minutes);
    return 0; 
} 

int main (int argc, char **argv){

    if((argc <= 2) || (argc > 3)){
        printf("%s: usage: %s [TIME (24hs)] [ZONE]\ne.g: %s 7:15 est\n", argv[0], argv[0], argv[0]);
        exit(0);
    }

   if(convert(argv [1], argv[2]) == -1){
        printf("%s: time zone not found, did you write it correctly?\n", argv[0]);
        return 1;
   }else return 0;
}
