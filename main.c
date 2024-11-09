#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);

	printf("%s \n", get_next_line(fd1));

	close(fd1);
	close(fd2);
	return 0;
}







static char *ft_charjoin(char *str, char c) {
    char *buffer = malloc(ft_strlen(str) + 2);
    if (!buffer) return NULL; // Check for malloc failure
    int i = 0;
    
    while (str[i] != '\0') {
        buffer[i] = str[i];
        i++;
    }
    
    buffer[i++] = c;
    buffer[i] = '\0';
    free(str);
    
    return buffer;
}

static int ft_new_line_check(const char *str) {
    if (!str) return 0;
    
    while (*str) {
        if (*str == '\n') return 1;
        str++;
    }
    
    return 0;
}

static char *ft_split(char *str, int *has_newline) {
    char *buffer = malloc(1);
    if (!buffer) return NULL; // Check for malloc failure
    buffer[0] = '\0';
    
    while (*str && *str != '\n') {
        buffer = ft_charjoin(buffer, *str);
        str++;
    }
    
    if (*str == '\n') {
        buffer = ft_charjoin(buffer, '\n');
        *has_newline = 1; // Indicate that we found a newline
        str++; // Move past the newline
    } else {
        *has_newline = 0; // No newline found
    }
    
    return str; // Return remaining string
}

static char *ft_strjoin(char *s1, const char *s2) {
    if (!s1) return (char *)s2; // If s1 is NULL, return s2 directly
    
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    
    char *buffer = malloc(len1 + len2 + 1);
    if (!buffer) return NULL; // Check for malloc failure
    
    for (size_t i = 0; i < len1; i++) {
        buffer[i] = s1[i];
    }
    
    for (size_t j = 0; j < len2; j++) {
        buffer[len1 + j] = s2[j];
    }
    
    buffer[len1 + len2] = '\0';
    
    free(s1); // Free s1 since it's no longer needed
    
    return buffer;
}

char *get_line(int fd) {
    static char *later = NULL;
    char tmp[BUFFER_SIZE + 1];
    char *buffer = malloc(1);
    
    if (!buffer) return NULL; // Check for malloc failure
    buffer[0] = '\0';

    int has_newline;
    
    if (later && ft_new_line_check(later)) {
        later = ft_split(later, &has_newline);
        buffer = ft_strjoin(buffer, later);
        if (has_newline) {
            return buffer; // Return line if we found a newline
        }
        free(buffer); // Free if no newline was found
        return NULL; // No more lines available
    }

   while (read(fd, tmp, BUFFER_SIZE) > 0) {
       tmp[BUFFER_SIZE] = '\0'; // Ensure null termination
       later = ft_strjoin(later, tmp);
       if (ft_new_line_check(later)) {
           later = ft_split(later, &has_newline);
           buffer = ft_strjoin(buffer, later);
           if (has_newline) {
               return buffer; // Return line if we found a newline
           }
       }
   }

   free(later); // Free remaining data in later
   later = NULL;

   return buffer[0] ? buffer : NULL; // Return NULL if no data was read
}

char *get_next_line(int fd) {
   return get_line(fd);
}