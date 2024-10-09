#include <stdio.h>
#include <stdlib.h>

int main(){
	int condicion;
	
	char c;

	scanf("%d", &condicion);

	c = (condicion > 5) ? 'S' : 'N';
	printf("%c\n", c);

return 0;
}
