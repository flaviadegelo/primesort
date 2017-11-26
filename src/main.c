#include <stdio.h>
#include <stdlib.h>

int primo(int numero){
	if(numero == 1){
		return 0;
	} else if (numero == 2){
		return 1;	
	} else {
		for(int div = 2 ; div <= numero/2 ; div += 1 ){
			if(numero % div == 0){
				return 0;
			}			
		}
		return 1;	
	}
}

int main() {
	
	int numero;
	FILE *pipe_fp;
	
	if((pipe_fp = popen("sort -n -r", "w")) == NULL){
		perror("popen");
		exit(1);
	}

	while(scanf("%d\n", &numero) != -1){
		if(!primo(numero)){
			fprintf(pipe_fp, "%d\n", numero);
		}
	}
	   
	pclose(pipe_fp);
	return(0);
}

