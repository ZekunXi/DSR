#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
const int initial_token_arr[7] = { 1,0,0,3,1,0,1 };

enum {
	t1,
	t2,
	t3,
	t4
};

typedef struct Place_base {
	int current_token;
	const int max_allow_token;
}Stelle;

Stelle S1 = { .current_token = 1,.max_allow_token = 1};
Stelle S2 = { .current_token = 0,.max_allow_token = 1 };
Stelle S3 = { .current_token = 0,.max_allow_token = 2 };
Stelle S4 = { .current_token = 3,.max_allow_token = INFINITE};
Stelle S5 = { .current_token = 1,.max_allow_token = 2 };
Stelle S6 = { .current_token = 0,.max_allow_token = 1 };
Stelle S7 = { .current_token = 1,.max_allow_token = 2 };

void T_transition(Stelle* point_Stelle_arr, int transition_active_signal);
void S_Menge_printer(Stelle* point_Stelle_arr, int Stelle_zahl);
void Zeilen_umbruch(Stelle* point_Stelle_arr, int Stelle_zahl);
int random_Eingang_signal() {
	return rand() % 4;
}


int main() {
	int i = 0;
	srand((unsigned)time(NULL));
	Stelle S_Menge[7] = { S1,S2,S3,S4,S5,S6,S7 };
	S_Menge_printer(S_Menge, 7);

	for (i = 0; i <= 1000; i++) {
		T_transition(S_Menge, random_Eingang_signal());
		Zeilen_umbruch(S_Menge, 7);
	}
	
	return 0;
}

void T_transition(Stelle* point_Stelle_arr, int transition_active_signal) {
	/*t1 active*/
	if (transition_active_signal == t1) {
		if ((point_Stelle_arr[0].current_token >= 1) && (point_Stelle_arr[1].current_token < point_Stelle_arr[1].max_allow_token) && (point_Stelle_arr[2].current_token < point_Stelle_arr[2].max_allow_token)) {
			point_Stelle_arr[0].current_token = point_Stelle_arr[0].current_token - 1;
			point_Stelle_arr[1].current_token = point_Stelle_arr[1].current_token + 1;
			point_Stelle_arr[2].current_token = point_Stelle_arr[2].current_token + 1;
			printf("==t1==>");
			S_Menge_printer(point_Stelle_arr, 7);
		}
		else {

		}
	}

	/*t2 active*/
	else if (transition_active_signal == t2) {
		if ((point_Stelle_arr[2].current_token >= 1) && (point_Stelle_arr[4].current_token < point_Stelle_arr[4].max_allow_token)) {
			point_Stelle_arr[2].current_token = point_Stelle_arr[2].current_token - 1;
			point_Stelle_arr[3].current_token = point_Stelle_arr[3].current_token + 1;
			point_Stelle_arr[4].current_token = point_Stelle_arr[4].current_token + 1;
			printf("==t2==>");
			S_Menge_printer(point_Stelle_arr, 7);
		}
		else {

		}
	}
	/*t3 active*/
	else if (transition_active_signal == t3) {
		if ((point_Stelle_arr[4].current_token >= 1) && (point_Stelle_arr[5].current_token < point_Stelle_arr[5].max_allow_token) && (point_Stelle_arr[6].current_token < point_Stelle_arr[6].max_allow_token)) {
			point_Stelle_arr[4].current_token = point_Stelle_arr[4].current_token - 1;
			point_Stelle_arr[5].current_token = point_Stelle_arr[5].current_token + 1;
			point_Stelle_arr[6].current_token = point_Stelle_arr[6].current_token + 1;
			printf("==t3==>");
			S_Menge_printer(point_Stelle_arr, 7);
		}
		else {

		}
	}
	/*t4 active*/
	else if (transition_active_signal == t4) {
		if ((point_Stelle_arr[1].current_token >= 1) && (point_Stelle_arr[3].current_token >= 1) && (point_Stelle_arr[5].current_token >= 1) && (point_Stelle_arr[6].current_token >= 1) && (point_Stelle_arr[0].current_token < point_Stelle_arr[0].max_allow_token)) {
			point_Stelle_arr[1].current_token = point_Stelle_arr[1].current_token - 1;
			point_Stelle_arr[3].current_token = point_Stelle_arr[3].current_token - 1;
			point_Stelle_arr[5].current_token = point_Stelle_arr[5].current_token - 1;
			point_Stelle_arr[6].current_token = point_Stelle_arr[6].current_token - 1;
			point_Stelle_arr[0].current_token = point_Stelle_arr[0].current_token + 1;
			printf("==t4==>");
			S_Menge_printer(point_Stelle_arr, 7);
		}
		else {

		}
	}

	/**/
	else {
		/**/
	}
}

void S_Menge_printer(Stelle* point_Stelle_arr, int Stelle_zahl) {
	int i = 0;
	printf("[");
	for (i = 0; i < Stelle_zahl; i++) {
		printf("%d ", point_Stelle_arr[i].current_token);
		if (i < Stelle_zahl - 1) {
			printf("|");
		}
	}
	printf("] ");
}

void Zeilen_umbruch(Stelle* point_Stelle_arr, int Stelle_zahl) {
	if ((point_Stelle_arr[0].current_token == initial_token_arr[0]) && (point_Stelle_arr[1].current_token == initial_token_arr[1]) && (point_Stelle_arr[2].current_token == initial_token_arr[2]) && (point_Stelle_arr[3].current_token == initial_token_arr[3]) && (point_Stelle_arr[4].current_token == initial_token_arr[4]) && (point_Stelle_arr[5].current_token == initial_token_arr[5]) && (point_Stelle_arr[6].current_token == initial_token_arr[6])) {
		printf("\n");
		printf("\n");
		printf("[1 |0 |0| 3| 1|0 |1 ]");
	}
}