#include <stdio.h>
#include <rpc/rpc.h>

// Interface gerada pelo RPCGen a partir da IDL (hw.x) especificada
#include "hw.h"

int main (int argc, char *argv[]) {
	// Estrutura RPC de comunicação
	CLIENT *cl;

	// Parâmetros das funçcões
	char        *par_f1 = (char *) malloc(256*sizeof(char));
	int          par_f2;
	struct param par_f3;
	int 				 parcela1 = 999;
	int 				 parcela2 = 999;
	char 				 operador = '-';

	// Retorno das funções
	char **ret_f0 = NULL;
        int   *ret_f1 = NULL;
        int   *ret_f2 = NULL;
        int   *ret_f3 = NULL;
	struct param *ret_f4 = NULL;


	// Verificação dos parâmetros oriundos da console
	if (argc != 2) {
		printf("ERRO: ./client <hostname>\n");
		exit(1);
	}

	if (!fscanf(stdin, "%d %d %c", &parcela1, &parcela2, &operador)) {
		printf ("ERRO\n");
		return 1;
	}

	// Conexão com servidor RPC
	cl = clnt_create(argv[1], PROG, VERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	struct param_operate par_f5;
	float *ret_f5 = NULL;
	par_f5.num1 = parcela1;
	par_f5.num2 = parcela2;
	par_f5.op = operador;

	ret_f5 = operate_1(&par_f5,cl);
	

	if (ret_f5 == NULL) {
	    clnt_perror(cl,argv[1]);
	    exit(1);
	}
	printf ("%.0f%c%.0f=%.0f\n", par_f5.num1, par_f5.op, par_f5.num2, *ret_f5);

  // clnt_destroy(cl);
	myexit_1(NULL, cl);
	pmap_unset(PROG, VERS);

	return 0;
}