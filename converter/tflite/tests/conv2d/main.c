#include <stdlib.h>
#include <stdio.h>
#include "ikann.h"
#include "utils.h"
#include "model.h"

// Data with 3 channels
static float data[] = {

	1., 2., 3., 4., 5.,
	6., 7., 8., 9., 10.,
	11., 12., 13., 14., 15.,
	16., 17., 18., 19., 20.,
	21., 22., 23., 24., 25.,

	26., 27., 28., 29., 30.,
	31., 32., 33., 34., 35.,
	36., 37., 38., 39., 40.,
	41., 42., 43., 44., 45.,
	46., 47., 48., 49., 50.,

	51., 52., 53., 54., 55.,
	56., 57., 58., 59., 60.,
	61., 62., 63., 64., 65.,
	66., 67., 68., 69., 70.,
	71., 72., 73., 74., 75.
};

int main(int argc, char *argv[]) {


	FILE *fp;
	kann_t *nn = init_nn();

	int i;
	float *y = kann_apply1(nn, data);

	for (i=0; i<10; i++) printf("%.5f, ", y[i]);
	printf("\n");
	
	fp = fopen("model_output.txt", "w");
	for (int i=0; i<10; i++) fprintf(fp, "%.8f,", y[i]);
	fclose(fp);

	return 0;
}