/*
** EPITECH PROJECT, 2021
** char 
** File description:
** number
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int count(char *str, int j, char c)
{
    int i = 0;
    while ((str[j] != c) && (str[j] != '\0')) { j++;
        i++;}
    return (i);
}

int word_count(char *str, char c)
{
    int i = 0;
    int j = 0;
    char cc = c;
    while (str[i] != '\0'){if ((cc == c)&&(str[i] != c)){
        j++;}
        cc = str[i];
        i++;
    }return (j);
}

char *my_strncpy(char *str, char *dest, int j, char c)
{
    int i = 0;
    while ((str[j] != c) && (str[j] != '\0')) { dest[i] = str[j];
        j++;
        i++;
    }dest[i] = '\0';
    return (dest);
}

char **my_str_to_wordtab(char *str, char c)
{
    int i = 0;
    int j = 0;
    char cc = c;
    char **tab = malloc((word_count(str, c) + 1) * sizeof(tab));
    while (str[i] != '\0') { if ((cc == c) && (str[i] != c)) {
            tab[j] = malloc(count(str, i, c) + 1);
            my_strncpy(str, tab[j], i, c);
            tab[j][count(str, i, c)] = '\0';
            j++;
        }cc = str[i];
        i++;
    }tab[j] = NULL;
    return (tab);
}

char *load_file(char const *filepath)
{
    struct stat al;
    int a = 0;
    int r = 0;
    char *buff;
    stat(filepath, &al);
    a = open(filepath, O_RDONLY);
    r = al.st_size;
    buff = malloc(sizeof(char) * (r + 1));
    read(a, buff, r);
    buff[r] = '\0';
    close(a);
    return (buff);
}

int sd(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int main(int ac, char **av)
{
    if (ac == 1){printf("Error try with your internshipreport\n");
        exit (84); }
    if (ac == 2) {
        char *string = load_file(av[1]);
        int i = sd(string);
        char **tab = my_str_to_wordtab(load_file(av[1]), ' ');
        for (int k = 0; tab[k] != NULL; k++) printf("%s", tab[k]);
            printf("char number = %d", i);
    }else
        exit(84);
    return 0;
}
