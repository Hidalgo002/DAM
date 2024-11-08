#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	char str1[5] = "hola";
//	printf("%s\n", str1);
//	printf("%c\n", str1[3]);
// 	printf("%d\n", str1[4]);
//	str1[4]	 = '$';
// 	printf("%s\n", str1);


	int main(){
		char str1[100];
		char str2[100];
		printf("Introduce una número: ");
		scanf("%s", str1);
		printf("Introduce una número: ");
		scanf("%s", str2);
		
		printf("%s+%s\n", str1, str2);
return 0;
}
