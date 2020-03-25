
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>



void LoadGraph(char* filename, int* width, int* height)
{
    FILE* filepoint;

    errno_t err = fopen_s(&filepoint, filename, "r");

    if (filepoint == NULL) {
        printf("Error: file does not exist. \n");
        exit(1);
    }


    int temp;
    int tempC;

    //while (fscanf(filepoint, "%*s %*s %s", &temp) == 1)
    //{
    //    printf("%s \n", &temp);
    //}
        

    int read_n, value;
    int value2;
    int value3;
    int value4;
    char line[60];
    char* val;
    char delims[] = "\n";

    while (fgets(line, 60, filepoint) != NULL)
    {
        val = strtok(line, delims);
        read_n = sscanf(val, "%d %d %d %d %d %d", &value, &value2, &value3,&value4);

        while (read_n > 0)
        {
            printf("Read [%d %d %d %d]\n", value, value2, value3, value4);
            val = strtok(NULL, delims);
            read_n = (val == NULL) ? 0 : sscanf(val, "%d", &value);
        }
    }



    fclose(filepoint);	//Close file
}

