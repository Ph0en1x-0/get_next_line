#include "get_next_line.h"
#include <stdio.h>


int main()
{
	int fd1 = open("file1.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));

	return 0;
}




// int main()
// {
// 	char	*pi = "hello world \n";

// 	char *tense ;

// 	tense = ft_init(tense);

// 	tense = ft_strjoin(tense, pi);

// 	printf("now = %s", ft_split(tense, 'b'));
// 	printf("later = %s", ft_split(tense, 'l'));


// 	return (0);
// }




// int main()
// {
// 	int fd1 = open("file1.txt", O_RDONLY);
// 	int fd2 = open("file2.txt", O_RDONLY);

// 	printf("\n --------------------\n\n");

// 	printf("call1 : %s", get_next_line(fd1));		//call 1

// 	printf("\n --------------------\n\n");

// 	printf("call2 : %s", get_next_line(fd1));		//call 2

// 	printf("\n --------------------\n\n");

// 	printf("call3 : %s", get_next_line(fd1));		//call 3

// 	printf("\n --------------------\n\n");

// 	printf("call4 : %s", get_next_line(fd1));		//call 4

// 	printf("\n --------------------\n\n");

// 	printf("call5 : %s", get_next_line(fd1));		//call 5


// 	printf("\n\n");
// 	close(fd1);
// 	close(fd2);
// 	return 0;
// }
	

	