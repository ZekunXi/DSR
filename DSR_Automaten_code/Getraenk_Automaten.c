#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void state_transfor_function(int current_state, int input_signal, int* p_E_arr,int** rec_p_E_move);
int get_current_state(int** rec_p_start, int** rec_p_move);
int random_input_function();

enum input_signal {
	M1,
	M2,
	G,
	D
};

enum state {
	E0,
	E1,
	E2,
	E3
};

int main() {
	srand((unsigned)time(NULL));
	int E_arr[4] = { 1,0,0,0 };
	int* p_E_start = &E_arr[0];
	int* p_E_move = &E_arr[0];
	int i = 0;
	for (i = 0; i < 10; i++) {
		state_transfor_function(get_current_state(&p_E_start, &p_E_move), random_input_function(), E_arr, &p_E_move);
		printf("\n");
	}
	return 0;
}


int get_current_state(int **rec_p_start,int **rec_p_move) {
	int current_state = (int)((*rec_p_move) - (*rec_p_start));
	if (current_state == E0) {
		printf("current state is E0\n");
	}
	else if (current_state == E1) {
		printf("current state is E1\n");
	}
	else if (current_state == E2) {
		printf("current state is E2\n");
	}
	else if (current_state == E3) {
		printf("current state is E3\n");
	}
	else {
		/**/
	}
	return current_state;
}

int random_input_function() {
	int u_input_signal = rand() % 4;
	if (u_input_signal == 0) {
		printf("intput signal is M1\n");
	}
	else if (u_input_signal == 1) {
		printf("intput signal is M2\n");
	}
	else if (u_input_signal == 2) {
		printf("intput signal is G\n");
	}
	else if (u_input_signal == 3) {
		printf("intput signal is D\n");
	}
	return u_input_signal;
}

void state_transfor_function(int current_state, int input_signal,int *p_E_arr,int **rec_p_E_move) {
	if (current_state == E0) {
		if (input_signal == M1) {
			p_E_arr[0] = 0;
			p_E_arr[1] = 1;
			*rec_p_E_move = &p_E_arr[1];
			printf("go to state E1!\n");
		}
		else if (input_signal == M2) {
			p_E_arr[0] = 0;
			p_E_arr[2] = 1;
			*rec_p_E_move = &p_E_arr[2];
			printf("go to state E2!\n");
		}
		else {
			printf("ineffective state and input combination!\n");
		}
	}
	
	else if (current_state == E1) {
		if (input_signal == G) {
			p_E_arr[1] = 0;
			p_E_arr[0] = 1;
			*rec_p_E_move = &p_E_arr[0];
			printf("go to state E0!\n");
		}
		else if (input_signal == M1) {
			p_E_arr[1] = 0;
			p_E_arr[2] = 1;
			*rec_p_E_move = &p_E_arr[2];
			printf("go to state E2!\n");
		}
		else if (input_signal == M2) {
			p_E_arr[1] = 0;
			p_E_arr[3] = 1;
			*rec_p_E_move = &p_E_arr[3];
			printf("go to state E3!\n");
		}
		else {
			printf("ineffective state and input combination!\n");
		}
	}
	
	else if (current_state == E2) {
		if (input_signal == G) {
			p_E_arr[2] = 0;
			p_E_arr[0] = 1;
			*rec_p_E_move = &p_E_arr[0];
			printf("go to state E0!\n");
		}
		else if ((input_signal == M1) || (input_signal == M2)) {
			p_E_arr[2] = 0;
			p_E_arr[3] = 1;
			*rec_p_E_move = &p_E_arr[3];
			printf("go to state E3!\n");
		}
		else {
			printf("ineffective state and input combination!\n");
		}
	}

	else if (current_state == E3) {
		if ((input_signal == M1) || (input_signal == M2)) {
			p_E_arr[3] = 1;
			*rec_p_E_move = &p_E_arr[3];
			printf("go to state E3!\n");
		}
		else if ((input_signal == G) || (input_signal == D)) {
			p_E_arr[3] = 0;
			p_E_arr[0] = 1;
			*rec_p_E_move = &p_E_arr[0];
			printf("go to state E0!\n");
		}
		else
		{
			printf("ineffective state and input combination!\n");
		}
	}
	else {
		/**/
	}
}