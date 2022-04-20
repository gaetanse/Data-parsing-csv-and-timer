#include "header.h"

Data data[1000];

char* strsep(char** stringp, const char* delim) {
    char* begin, * end;
    begin = *stringp;
    if (begin == NULL) return NULL;
    end = begin + strcspn(begin, delim);
    if (*end) {
        *++end = '\0';
        *stringp = end;
    }
    else *stringp = NULL;
    return begin;
}

/*int setMyData(Data* st, int a, char p, int s)
{
    if (!st)
        return EXIT_FAILURE;
    st->age = a;
    st->prof = p;
    st->super = s;
    return EXIT_SUCCESS;
}*/

int timerFromStart(clock_t begin) {
    time_t end = time(NULL);
    return (end - begin);
}

FILE* file = NULL;
const nb_line = 3;

int main() {
    if (openCsv()) {
        time_t begin = time(NULL);
        readDataFromCsv(nb_line);
        printf("The elapsed time is %d seconds\n", timerFromStart(begin));
    }
    else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

openCsv() {
    errno_t err = fopen_s(&file, "FD_INDREGZD_2018.csv", "r");
    if (err == 0 && file) {
        time_t begin = time(NULL);
        readDataFromCsv(nb_line);
        printf("The elapsed time is %d seconds\n", timerFromStart(begin));
        fclose(file);
    }
    else {
        printf("Unable to open file!");
        return EXIT_FAILURE;
    }
}

readDataFromCsv(int nb_line) {
    //todo: malloc and free line
    Data* d = NULL;
    d = malloc(nb_line * sizeof(Data));
    char line[1000];
    int i = 0;
    while (!feof(file)) {
        if (nb_line == i)
        {
            break;
        }
        fgets(line, sizeof(line), file);
        char* p = line;
        char* tok;
        int j = 0;
        while(tok = strsep(&p, ";"))
        {
            if (j == 5 || j == 75 || j == 84)
            {
                printf("tok = '%s'\n", tok);
            }
            ++j;
        }
        ++i;
    }
}

void writeData(Data data, int age, char profession[], int superficie) {

}