#include "bb_input_script.h"
#include <stdio.h>
int main(void){int rc=bb_input_script_selftest();printf("{\"input_script_selftest\":%s,\"gate\":%d}\n",rc?"false":"true",rc);return rc;}
