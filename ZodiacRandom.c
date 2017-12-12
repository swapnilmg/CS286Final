#include "includes.h"

static int cipher_text[408] = {6,15,11,4,15,10,8,13,10,4,11,8,8,11,8,14,11,18,20,8,0,18,2,19,8,20,14,1,4,4,4,18,12,2,4,19,12,8,5,13,14,17,19,20,5,20,7,18,8,13,7,11,12,6,11,3,8,22,8,11,6,13,10,0,13,8,0,4,19,0,17,4,1,7,4,18,5,4,13,19,8,17,14,2,20,14,0,7,13,18,0,4,12,8,19,4,12,18,19,18,3,13,11,11,8,20,14,14,12,0,18,5,4,17,6,13,0,0,11,7,6,12,11,8,8,4,19,11,13,14,10,19,14,18,6,8,19,8,12,4,19,12,14,18,19,7,4,18,21,4,7,17,11,2,8,17,4,4,6,4,13,23,8,8,13,11,4,15,19,18,7,4,4,1,0,13,17,19,4,13,21,4,4,19,19,6,19,10,5,17,24,18,6,14,2,14,14,8,13,19,17,20,5,22,1,15,19,6,4,0,7,4,8,18,19,7,8,11,17,19,0,19,13,19,8,22,5,7,0,19,7,19,14,17,18,8,4,8,4,13,1,22,1,8,4,17,8,14,8,4,3,11,11,17,8,3,19,4,0,0,17,0,13,3,11,15,0,13,2,8,11,7,3,11,11,21,22,0,11,4,4,8,8,7,4,8,10,11,1,4,8,11,4,18,12,0,21,12,8,2,14,4,18,24,22,11,12,12,24,6,24,19,14,20,8,13,13,14,11,4,21,0,4,8,17,14,20,11,0,20,22,18,11,4,2,1,24,4,19,24,17,15,22,14,18,11,13,14,22,19,14,18,19,14,3,14,12,14,0,8,11,5,11,13,6,4,18,2,14,24,19,2,11,21,17,4,5,17,11,14,19,4,12,8,18,5,4,0,24,5,4,7,19,12,8,7,17,4,19,4,15,4,14,1,4,19,8,8};
//static int cipher_text[408] = {8,4,10,8,11,8,13,15,4,14,15,8,11,11,6,10,11,4,0,20,18,8,19,8,18,14,12,20,4,2,4,18,2,1,20,8,19,8,12,14,17,5,20,13,19,7,7,18,4,13,5,10,11,11,8,6,22,8,3,6,0,12,0,4,13,11,8,13,19,4,5,14,17,4,18,1,4,2,0,8,20,17,19,7,13,12,13,8,18,7,4,12,18,19,3,0,18,13,19,14,0,4,17,20,18,0,8,12,0,14,5,0,11,6,11,13,11,14,4,10,11,11,18,12,4,19,8,13,6,6,19,8,14,7,8,14,18,4,19,7,12,14,18,19,7,17,8,21,11,4,19,12,4,13,4,23,15,17,4,13,4,8,19,8,11,18,4,2,6,8,4,1,4,19,4,17,19,0,13,6,4,4,19,19,7,13,21,13,24,14,20,17,14,2,18,14,5,5,19,22,17,10,6,8,7,6,8,17,19,7,4,4,18,19,15,8,0,11,1,0,19,14,8,19,8,19,7,0,22,7,4,13,17,8,18,19,5,19,4,22,8,11,1,4,17,1,14,17,13,3,8,11,4,8,8,0,0,3,8,4,0,13,0,11,11,19,13,7,2,3,17,15,7,21,4,10,11,11,4,22,8,11,11,4,1,8,3,0,8,14,4,12,24,11,0,21,18,8,22,8,4,11,18,4,12,2,14,6,8,21,24,14,20,24,13,0,12,11,4,4,12,19,13,2,20,18,4,14,20,22,11,11,19,17,1,24,24,8,0,4,18,14,22,3,22,13,14,18,19,14,15,19,12,14,17,11,14,14,11,4,2,8,13,6,5,18,11,0,24,21,19,14,11,2,5,17,12,24,5,19,4,11,8,5,4,4,4,0,17,14,18,14,8,4,19,12,4,19,7,15,8,19,1,8,4,7,17,4};
//static int cipher_text[408] = {11,6,4,8,13,4,11,8,11,8,14,11,10,10,15,8,15,8,18,0,19,8,14,1,4,4,18,12,2,20,2,18,4,20,12,4,8,14,17,20,5,20,18,8,13,7,19,13,5,7,19,6,11,11,22,8,6,13,10,13,8,0,4,11,8,3,0,12,17,19,4,4,18,4,13,19,17,14,2,20,5,7,1,8,0,7,14,13,4,12,19,4,12,19,18,3,13,8,0,18,18,0,8,11,20,12,0,5,4,17,13,0,0,11,18,14,14,6,11,12,7,11,4,19,13,14,10,14,18,6,8,11,8,8,19,6,12,19,4,14,18,7,4,18,4,7,17,11,19,12,19,21,8,17,2,4,4,13,8,8,13,4,15,19,18,23,6,4,11,8,4,7,1,17,19,13,21,4,19,19,6,19,4,13,0,4,4,17,10,24,14,2,14,8,13,17,20,5,22,14,6,18,19,5,19,1,6,7,4,18,19,7,11,17,19,0,8,0,4,8,15,19,19,8,7,0,7,19,14,18,8,4,8,19,5,22,17,13,1,4,22,4,17,14,8,4,11,11,17,8,8,8,1,3,13,4,3,0,0,13,11,15,0,2,8,11,7,3,17,0,13,19,11,3,21,11,4,8,8,7,8,10,11,1,4,0,22,4,11,11,4,4,0,21,8,2,14,18,24,22,11,12,12,18,4,8,24,12,6,14,20,13,13,14,4,21,0,4,8,19,24,11,12,14,8,20,20,22,11,4,2,24,4,19,24,18,0,11,1,17,22,17,14,13,14,19,14,18,14,3,14,12,22,11,18,19,15,8,14,11,13,6,18,2,14,19,2,11,21,4,11,5,24,0,5,17,17,19,4,8,18,5,0,24,5,4,12,14,11,4,4,12,7,8,4,19,15,4,14,4,19,8,8,4,17,7,1,19};
//static int plain_text[408] = {8,11,8,10,4,10,8,11,11,8,13,6,15,4,14,15,11,4,1,4,2,0,20,18,4,8,19,8,18,18,14,12,20,2,7,5,20,13,8,19,8,18,12,14,17,4,5,20,13,19,7,0,13,10,8,11,11,8,13,6,22,8,11,3,6,0,12,4,8,13,19,7,4,5,14,17,17,4,18,19,1,4,2,0,20,18,4,12,0,13,8,18,19,7,4,12,14,18,19,3,0,13,6,4,17,14,20,18,0,13,8,12,0,11,14,5,0,11,11,19,14,10,8,11,11,18,14,12,4,19,7,8,13,6,6,8,21,4,18,12,4,19,7,4,12,14,18,19,19,7,17,8,11,11,8,13,6,4,23,15,4,17,4,13,2,4,8,19,8,18,4,21,4,13,1,4,19,19,4,17,19,7,0,13,6,4,19,19,8,13,6,24,14,20,17,17,14,2,10,18,14,5,5,22,8,19,7,0,6,8,17,11,19,7,4,1,4,18,19,15,0,17,19,14,5,8,19,8,18,19,7,0,19,22,7,4,13,8,3,8,4,8,22,8,11,11,1,4,17,4,1,14,17,13,8,13,15,0,17,0,3,8,2,4,0,13,3,0,11,11,19,7,4,8,7,0,21,4,10,8,11,11,4,3,22,8,11,11,1,4,2,14,12,4,12,24,18,11,0,21,4,18,8,22,8,11,11,13,14,19,6,8,21,4,24,14,20,12,24,13,0,12,4,1,4,2,0,20,18,4,24,14,20,22,8,11,11,19,17,24,19,14,18,11,14,22,3,14,22,13,14,17,18,19,14,15,12,24,2,14,11,11,4,2,19,8,13,6,14,5,18,11,0,21,4,18,5,14,17,12,24,0,5,19,4,17,11,8,5,4,4,1,4,14,17,8,4,19,4,12,4,19,7,7,15,8,19,8};

//static int cipher_text[408] = {9,18,14,7,18,13,11,16,13,7,14,11,11,14,11,17,14,21,23,11,3,21,5,22,11,23,17,4,7,7,7,21,15,5,7,22,15,11,8,16,17,20,22,23,8,23,10,21,11,16,10,14,15,9,14,6,11,25,11,14,9,16,13,3,16,11,3,7,22,3,20,7,4,10,7,21,8,7,16,22,11,20,17,5,23,17,3,10,16,21,3,7,15,11,22,7,15,21,22,21,6,16,14,14,11,23,17,17,15,3,21,8,7,20,9,16,3,3,14,10,9,15,14,11,11,7,22,14,16,17,13,22,17,21,9,11,22,11,15,7,22,15,17,21,22,10,7,21,24,7,10,20,14,5,11,20,7,7,9,7,16,0,11,11,16,14,7,18,22,21,10,7,7,4,3,16,20,22,7,16,24,7,7,22,22,9,22,13,8,20,1,21,9,17,5,17,17,11,16,22,20,23,8,25,4,18,22,9,7,3,10,7,11,21,22,10,11,14,20,22,3,22,16,22,11,25,8,10,3,22,10,22,17,20,21,11,7,11,7,16,4,25,4,11,7,20,11,17,11,7,6,14,14,20,11,6,22,7,3,3,20,3,16,6,14,18,3,16,5,11,14,10,6,14,14,24,25,3,14,7,7,11,11,10,7,11,13,14,4,7,11,14,7,21,15,3,24,15,11,5,17,7,21,1,25,14,15,15,1,9,1,22,17,23,11,16,16,17,14,7,24,3,7,11,20,17,23,14,3,23,25,21,14,7,5,4,1,7,22,1,20,18,25,17,21,14,16,17,25,22,17,21,22,17,6,17,15,17,3,11,14,8,14,16,9,7,21,5,17,1,22,5,14,24,20,7,8,20,14,17,22,7,15,11,21,8,7,3,1,8,7,10,22,15,11,10,20,7,22,7,18,7,17,4,7,22,11,11};
//static int plain_text[408] = {11,14,11,13,7,13,11,14,14,11,16,9,18,7,17,18,14,7,4,7,5,3,23,21,7,11,22,11,21,21,17,15,23,5,10,8,23,16,11,22,11,21,15,17,20,7,8,23,16,22,10,3,16,13,11,14,14,11,16,9,25,11,14,6,9,3,15,7,11,16,22,10,7,8,17,20,20,7,21,22,4,7,5,3,23,21,7,15,3,16,11,21,22,10,7,15,17,21,22,6,3,16,9,7,20,17,23,21,3,16,11,15,3,14,17,8,3,14,14,22,17,13,11,14,14,21,17,15,7,22,10,11,16,9,9,11,24,7,21,15,7,22,10,7,15,17,21,22,22,10,20,11,14,14,11,16,9,7,0,18,7,20,7,16,5,7,11,22,11,21,7,24,7,16,4,7,22,22,7,20,22,10,3,16,9,7,22,22,11,16,9,1,17,23,20,20,17,5,13,21,17,8,8,25,11,22,10,3,9,11,20,14,22,10,7,4,7,21,22,18,3,20,22,17,8,11,22,11,21,22,10,3,22,25,10,7,16,11,6,11,7,11,25,11,14,14,4,7,20,7,4,17,20,16,11,16,18,3,20,3,6,11,5,7,3,16,6,3,14,14,22,10,7,11,10,3,24,7,13,11,14,14,7,6,25,11,14,14,4,7,5,17,15,7,15,1,21,14,3,24,7,21,11,25,11,14,14,16,17,22,9,11,24,7,1,17,23,15,1,16,3,15,7,4,7,5,3,23,21,7,1,17,23,25,11,14,14,22,20,1,22,17,21,14,17,25,6,17,25,16,17,20,21,22,17,18,15,1,5,17,14,14,7,5,22,11,16,9,17,8,21,14,3,24,7,21,8,17,20,15,1,3,8,22,7,20,14,11,8,7,7,4,7,17,20,11,7,22,7,15,7,22,10,10,18,11,22,11};

//static int cipher_text[408] = {10,11,2,5,11,4,8,9,4,12,2,3,1,7,6,13,7,23,19,1,18,24,17,22,3,19,25,15,16,14,21,20,26,17,34,37,26,6,35,29,32,33,30,19,28,19,27,31,8,36,38,2,26,10,2,42,1,41,6,7,10,40,4,39,9,3,43,44,22,18,48,5,15,27,12,20,28,14,29,45,8,47,46,17,19,13,39,38,36,49,18,21,26,1,37,16,26,23,30,24,50,40,7,2,1,19,32,32,26,18,20,35,34,33,10,9,43,39,7,27,10,26,2,6,3,44,22,7,29,46,4,45,13,23,10,8,37,1,26,12,45,26,25,49,30,27,5,24,51,14,38,47,52,17,8,48,16,44,10,34,40,54,6,3,36,7,21,11,22,20,38,21,16,15,43,9,33,45,14,29,51,12,5,37,30,10,22,4,35,48,53,23,10,46,17,32,13,1,36,30,47,19,28,41,15,11,45,10,44,18,38,34,6,24,37,27,3,2,33,22,18,22,40,45,8,41,28,27,43,37,38,30,25,47,49,1,5,3,16,9,15,41,15,8,14,48,1,32,6,12,50,7,52,33,3,50,37,21,43,18,47,39,36,42,2,11,39,29,17,6,2,27,42,7,2,51,41,39,2,5,44,3,8,38,34,1,4,52,15,16,1,52,14,23,26,18,51,26,1,17,13,12,20,53,41,7,26,26,53,10,53,37,46,19,6,29,9,32,2,16,51,39,14,1,33,32,19,2,18,19,41,24,52,5,17,15,53,44,45,53,48,11,41,13,31,7,36,46,41,45,25,20,22,13,50,25,26,13,18,3,52,35,52,9,10,21,20,17,46,53,37,17,2,51,47,14,28,33,7,32,30,16,26,3,23,28,5,39,53,35,21,27,30,26,1,38,47,44,22,14,11,44,13,15,21,30,6,8};
//static int plain_text[408] = {1,2,3,4,5,4,6,7,2,8,9,10,11,12,13,11,7,14,15,16,17,18,19,20,21,1,22,3,23,24,25,26,19,17,27,28,19,29,6,30,8,31,26,32,33,34,35,19,36,37,38,39,40,4,1,2,7,3,9,10,41,6,2,42,10,43,26,44,8,29,45,27,5,28,46,47,48,12,20,22,15,14,17,18,19,23,16,26,18,36,1,24,30,38,21,26,13,49,37,50,39,40,10,34,33,32,19,20,43,9,1,26,18,7,32,35,39,2,7,45,46,4,3,2,7,23,13,26,44,22,27,6,29,10,10,8,51,5,24,26,12,30,38,14,26,25,49,37,45,27,47,1,52,7,3,36,10,16,54,11,21,48,34,40,17,44,6,22,8,20,5,51,12,9,15,14,30,37,16,33,45,38,43,29,10,21,22,30,1,36,10,53,32,19,47,48,46,17,4,23,13,28,35,41,3,37,27,18,10,6,33,2,45,38,34,15,44,24,22,11,18,47,30,25,28,8,37,1,49,45,27,43,22,41,38,5,40,3,50,6,12,8,41,1,52,7,15,14,48,16,15,32,33,9,3,29,11,39,47,43,42,6,17,21,39,36,50,18,2,2,37,27,34,8,38,39,51,44,4,1,2,2,5,42,41,3,52,7,15,12,17,13,26,14,26,53,20,52,18,51,16,23,1,41,1,7,2,9,32,37,10,6,51,16,53,46,19,26,53,29,39,26,14,15,5,17,18,19,24,44,53,32,19,41,1,2,52,45,33,53,22,25,20,7,13,41,50,13,41,36,46,48,31,45,25,11,26,53,17,46,52,52,21,17,37,3,9,10,13,35,20,2,18,51,5,23,28,32,33,26,53,39,28,30,16,47,7,3,35,14,21,15,44,13,47,1,14,30,21,26,44,22,27,38,11,6,30,8};

static double best_model_score = -99999;

void obtainObservations(sg_obs_t *obs);
void obtainDiagraphFrequency(double **A, char *folder_name);
double getAccuracy(double **B);
void swapColumns(long data[], int rows, int rowLen, int i, int j);
void printColumns(long data[], int rowLen, int dataLen);
int hillClimb(sg_obs_t *obs, double **A);
int random_permuatation(sg_obs_t *obs, double **A);
void columnCopy(long sourceObs[], long destObst[], int sourceCol, int destCol, int rowLen, int colLen);
void randomShuffle(sg_obs_t *obs, int numCols, int numRows);


int main(int argc, char *argv[]) {
    /* code */

    char *folder_name;
	  long seed;
    int count = 1;
    int reestimate;

    /* Check arguments */
	if (argc < 4) {
		printf("Format:\n");
		printf("Q15 <folder_name> <hmm count> <reestimate A= 1/0>\n");
		exit(1);
	} else {
		folder_name = argv[1];
		count = atoi(argv[2]);
        reestimate = atoi(argv[3]);
	}

    /* Obtain observation sequence */
	sg_obs_t *obs = sg_obs_Create();
    obs->N = 26;
    obs->T = 408;
    sg_obs_Allocate(obs);

    //sg_obs_t *obs2 = sg_obs_Create();
    //obs2->N = 26;
    //obs2->T = 408;
    //sg_obs_Allocate(obs2);

    for (int i = 0; i < 408; ++i)
    {
        obs->seq[i] = cipher_text[i];
        //obs2->seq[i] = plain_text[i]-1;
    }

    double **A, **B, best_model_score = -99999;
      /* Initialize A */
  	A = (double **) malloc(obs->N * sizeof(double *));
  	A[0] = (double *) malloc(obs->N * obs->N * sizeof(double));
  	for(int i = 0; i < obs->N; i++)
          A[i] = (*A + obs->N * i);

    obtainDiagraphFrequency(A, folder_name);

    int climb = 1;
    sg_hmm_t *mod = sg_hmm_Create();
    mod->N = 26;
    mod->M = 26;

    sg_hmm_InitRandomWithoutA(mod);
    mod->A = A;
    sg_trainWithoutA(mod, obs, 100);
    best_model_score = _computeLogScore(obs);
    printf("Initial Score: %f\n", best_model_score);

    srand(time(NULL));
    //printColumns(obs->seq, 17, 24*17);

    while(count-- > 0) {
        randomShuffle(obs, 17, 24);
        while(climb) {
            climb = hillClimb(obs, A);
        }
    }

    //printf("\nThreshold reached");
    //printColumns(obs->seq, 17, 24*17);
    return 0;
}

void randomShuffle(sg_obs_t *obs, int numCols, int numRows) {
    long suffledSeq[obs->T];
    int occupied[numCols] ;

    memset(occupied, 0, numCols*sizeof(int)) ;
    memset(suffledSeq, 0, obs->T*sizeof(long));

    for(int oldPos=0; oldPos<numCols; oldPos++){
        // Each column in the original sequence in moved to a new column position
        short newPos = rand() % numCols;
        while(occupied[newPos] != 0) {
            // Identifying an unoccupied poistion
            newPos = (newPos + 1) % numCols;
        }
        columnCopy(obs->seq, suffledSeq, oldPos, newPos, numRows, numCols);
        occupied[newPos] = 1;
    }

    // Copy shuffled array to original sequence
    for (int i = 0; i < numCols * numRows; ++i)
    {
        obs->seq[i] = suffledSeq[i];
    }
    
}

int hillClimb(sg_obs_t *obs, double **A) {
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16-i; ++j)
        {
            printf("Swapping columns %d, %d: ", j, j+i+1);
            swapColumns(obs->seq, 24, 17, j, j+i+1);
            /* Create random model */
            sg_hmm_t *mod = sg_hmm_Create();
            mod->N = 26;
            mod->M = 26;

            sg_hmm_InitRandomWithoutA(mod);
            mod->A = A;
            sg_trainWithoutA(mod, obs, 200);
            double score = _computeLogScore(obs);
            printf("Best Score: %f, Score: %f", best_model_score, score);
            if(score > -1050) {
                printColumns(obs->seq, 17, 17*24);
            }
            if(best_model_score < score){
                best_model_score = score;
                printf("\n");
                return 1;
            }
            /* Create random model */
            mod = sg_hmm_Create();
            mod->N = 26;
            mod->M = 26;

            sg_hmm_InitRandomWithoutA(mod);
            mod->A = A;
            sg_trainWithoutA(mod, obs, 200);
            score = _computeLogScore(obs);
            printf(" Score: %f", score);
            if(score > -1050) {
                printColumns(obs->seq, 17, 17*24);
            }
            if(best_model_score < score){
                best_model_score = score;
                printf("\n");
                return 1;
            }
            swapColumns(obs->seq, 24, 17, j, j+i+1);
            printf(" Undoing swap!\n");
        }

    }
    return 0;
}

int random_permuatation(sg_obs_t *obs, double **A) {

    // should only be called once
    int i=0, j = 0;
    while(i==j){
        i = rand() % 17;
        j = rand() % 17;
    }

    printf("Swapping columns %d, %d: ", i, j);
    swapColumns(obs->seq, 24, 17, i, j);
    /* Create random model */
    sg_hmm_t *mod = sg_hmm_Create();
    mod->N = 26;
    mod->M = 26;

    sg_hmm_InitRandomWithoutA(mod);
    mod->A = A;
    sg_trainWithoutA(mod, obs, 50);
    double score = _computeLogScore(obs);
    printf("Score: %f, Best Score: %f\n", score, best_model_score);
    if(score > -1050) {
        printColumns(obs->seq, 17, 17*24);
    }
    if(best_model_score < score){
        best_model_score = score;
        return 1;
    }
    /* Create random model */
    mod = sg_hmm_Create();
    mod->N = 26;
    mod->M = 26;

    sg_hmm_InitRandomWithoutA(mod);
    mod->A = A;
    sg_trainWithoutA(mod, obs, 50);
    score = _computeLogScore(obs);
    printf("Score: %f, Best Score: %f\n", score, best_model_score);
    if(score > -1050) {
        printColumns(obs->seq, 17, 17*24);
    }
    if(best_model_score < score){
        best_model_score = score;
        return 1;
    }
    swapColumns(obs->seq, 24, 17, i, j);
    printf("Undoing swapping of columns %d, %d\n", i, j);
    return 0;
}

void obtainObservations(sg_obs_t *obs) {
    for (size_t i = 0; i < 408; i++) {
        obs->seq[i] = cipher_text[i];
    }
}

void swap(long data[], int i, int j){
    long temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void swapColumns(long data[], int rows, int rowLen, int i, int j){

    if(i >= rowLen || j >= rowLen)
        return;

    for(int r=0; r<rows; r++){
        int shift = r*rowLen;
        swap(data, shift+i, shift+j);
    }
}

void printColumns(long data[], int rowLen, int dataLen){
    for (int i = 0; i < dataLen; i++)
    {
        if(i%rowLen == 0)
            printf("\n");
        printf("%ld ", data[i]);
    }
}

void columnCopy(long *sourceObs, long destObst[], int sourceCol, int destCol, int rowLen, int colLen){
  for(int i=0; i<rowLen; i++){
    int shift = i*colLen;
    destObst[shift+destCol] = sourceObs[shift+sourceCol];
  }
}

void obtainDiagraphFrequency(double **A, char *folder_name) {
	DIR* FD;
    struct dirent* in_file;
    FILE *entry_file;
    int d, ld;
    size_t n = 0;
    size_t max = 1000000;

    //printf("Initializing A:\n");
    for (int i = 0; i < 26; ++i)
    {
    	for (int j = 0; j < 26; ++j)
    	{
    		A[i][j] = 5.0;
    	}
    }

    //printf("Trying to open folder: %s\n", folder_name);
    if (NULL == (FD = opendir (folder_name))) {
    	fprintf(stderr, "Error : Failed to open input directory\n");
    	return;
    }
    //T = (char *)malloc(1000 * sizeof(unsigned char));

    while ((in_file = readdir(FD))) {
    	if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))
            continue;
        if (!strcmp (in_file->d_name, "removed"))
            continue;
        if (!strcmp (in_file->d_name, ".DS_Store"))
            continue;

        char * fullpath ;
		if((fullpath = (char *)malloc(strlen(folder_name)+strlen(in_file->d_name)+1)) != NULL){
		    fullpath[0] = '\0';   // ensures the memory is an empty string
		    strcat(fullpath,folder_name);
		    strcat(fullpath,in_file->d_name);
		} else {
		    fprintf(stderr,"malloc failed!\n");
		}
        //printf("%s\n", fullpath);

        entry_file = fopen(fullpath, "r");
        if (entry_file == NULL) {
            fprintf(stderr, "Error : Failed to open entry file\n");
            return;
        }

        bool skip = true;
        while ((d = fgetc(entry_file)) != EOF && n<max) {
        	if( d == 10) {
        		skip = true;
        		continue;
        	}
        	if(skip){
        		skip = false;
        		continue;
        	}
        	if(isalpha((unsigned char) d)){
        		if (isupper((unsigned char) d)) {
					d = tolower((unsigned char) d) - 'a';
		      	} else if(islower((unsigned char) d)) {
		      		d = ((unsigned char) d) - 'a';
		      	}
		      	if(n>0) {
        			A[ld][d] = A[ld][d]+1;
        		}
        		ld = d;
		      	n++;
	      	}
	    }
	    fclose(entry_file);
	    if(n == max) {
	    	break;
	    }
    }

    for (int i = 0; i < 26; ++i)
    {
    	double total = 0;
    	for (int j = 0; j < 26; ++j)
    	{
    		total += A[i][j];
    	}
    	for (int j = 0; j < 26; ++j)
    	{
    		A[i][j] = A[i][j] / total;
    	}
    }
}
