#include <syslog.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 3) // not enough arguments were passed
    {
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        return 1;
    }

    char* writePath = argv[1];
    char* searchStr = argv[2];
    // Open write file
    int fd;
    fd = open(writePath, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd ==-1){
        syslog(LOG_ERR, "Error opening file from path %s", writePath);
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", searchStr, writePath);
    ssize_t nr;
    
    /* write the searchStr to writePath */
    nr = write(fd, searchStr, strlen (searchStr));
    if (nr==-1) {
        syslog(LOG_ERR, "Error occured when writing %s to %s", searchStr, writePath);
        return 1;
    }
    syslog(LOG_DEBUG, "Successfully wrote %s to %s", searchStr, writePath);
    return 0;
}