#include <rpc/rpc.h>
#include <string.h>
#include <math.h>
// Interface gerada pelo RPCGen a partir da IDL (hw.x) especificada
#include "hw.h"

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
char **func0_1_svc(void *a, struct svc_req *req) {
	static char msg[256];
	static char *p;

	printf("FUNC0 (sem parâmetros)\n");
	strcpy(msg, "Hello Func0!");
	p = msg;

	return(&p);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func1_1_svc(char **a, struct svc_req *req) {
    static int ret = 1;

    printf ("FUNC1 (%s)\n", *a);

    return (&ret);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func2_1_svc(int *a, struct svc_req *req) {
     static int ret = 10;

     printf ("FUNC2 (%d)\n", *a);
     return (&ret);

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func3_1_svc(struct param *a, struct svc_req *req) {
     static int ret=0;

     printf ("FUNC3 (%d/%d)\n", a->arg1, a->arg2);
     ret = a->arg1 * a->arg2;
     return (&ret);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
struct param *func4_1_svc(void *b, struct svc_req *req) {
     static struct param a;

     a.arg1 = 10;
     a.arg2 = 9;

     printf ("FUNC4 (%d/%d)\n", a.arg1, a.arg2);
     return (&a);
}

float *operate_1_svc(struct param_operate *a, struct svc_req *req){
     static float value;

     if(a->op == '+')
          value = a->num1 + a->num2;
     else if(a->op == '-')
          value = a->num1 - a->num2;
     else if(a->op == '*')
          value = a->num1 * a->num2;
     else if(a->op == '/')
          value = a->num1 / a->num2;
     else{
          printf("Operacao invalida");
          value = 0.0/0.0;
     }

     return (&value);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void *myexit_1_svc(void *a, struct svc_req *req) {
    exit(0);
}
