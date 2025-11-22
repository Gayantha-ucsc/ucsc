#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randFloor(char validity){
	if (validity == 'i'){
		int random;
		for (random = 0; random >= 0 && random <= 2; random = rand() % 25 - rand() % 25);
		return random; 
	}
	else if (validity == 'a'){
		return (rand() % 5 - rand() % 5);
	}
	else{
		return (rand() % 3);
	}
}

int randWidth(char validity){
	if (validity == 'i'){
		int random;
		for (random = 0; random >= 0 && random <= 9; random = rand() % 25 - rand() % 25);
		return random; 
	}
	else if (validity == 'a'){
		return (rand() % 11 - rand() % 11);
	}
	else{
		return (rand() % 10);
	}
}

int randLength(char validity){
	if (validity == 'i'){
		int random;
		for (random = 0; random >= 0 && random <= 24; random = rand() % 99 - rand() % 99);
		return random; 
	}
	else if (validity == 'a'){
		return (rand() % 26 - rand() % 26);
	}
	else{
		return (rand() % 25);
	}
}

int main(int argc, char* argv[]){
	printf("\e[31m NOTE THAT IF ANY FILE WITH THE SAME NAME AS 'seed.txt, flag.txt, walls.txt, poles.txt, stairs.txt' WILL BE OVERWRITTEN.\e[0m\n");
	printf("DO YOU WANT TO CONTINUE? (y/N)\n");

	char overwrite = 'y';
	//scanf("%c", &overwrite);

	if (overwrite != 'Y' && overwrite != 'y'){
		printf("Process aborted, Files are untanpered\n");
		return 0;
	}

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <generation-type> <number-of-walls> <number-of-poles> <number-of-stairs>\n", argv[0]);
        return 1;
    }

	FILE* seed_File = fopen("./seed.txt", "w");

	if (seed_File == NULL){
		printf("Error Creating/Opening the seed file. Seed file is not set.\n");
	}
	else{
		long unsigned int seed = clock() * 345;
		fprintf(seed_File, "%lu", seed);
		srand(seed);
	}

	fclose(seed_File);


	FILE* walls_File = fopen("./walls.txt", "w");

	if (walls_File == NULL){
		printf("Error Creating/Opening the walls file. Walls file is not set.\n");
	}
	else{
		for (int i = 0; i < strtol(argv[2], NULL, 10); i++){
			int floor = randFloor(argv[1][0]); 
			int start_Width = randWidth(argv[1][0]);
			int start_Length= randLength(argv[1][0]);
			int end_Width = randWidth(argv[1][0]);
			int end_Length= randLength(argv[1][0]);

			if (argv[1][0] != 'i'){
				if (start_Width != end_Width && start_Length != end_Length){
					if (rand() % 2 == 0){
						start_Width = end_Width;
					}
					else{
						start_Length = end_Length;
					}
				}
			}
			else if (argv[1][0] != 'a'){
				if (start_Width != end_Width && start_Length != end_Length){
					if (rand() % 10 == 0){
						start_Width = end_Width;
					}
					else if (rand() % 10 == 0){
						start_Length = end_Length;
					}
				}
			}

			fprintf(walls_File, "[%d,%d,%d,%d,%d]\n", 
					floor,
					start_Width,
					start_Length,
					end_Width,
					end_Length
				);
		}
	}

	fclose(walls_File);


	FILE* poles_File = fopen("./poles.txt", "w");

	if (poles_File == NULL){
		printf("Error Creating/Opening the poles file. Poles file is not set.\n");
	}
	else{
		for (int i = 0; i < strtol(argv[3], NULL, 10); i++){
			int start_Floor = randFloor(argv[1][0]); 
			int end_Floor = randFloor(argv[1][0]); 

			if (argv[1][0] != 'i' && argv[1][0] != 'a'){
				if (start_Floor > end_Floor){
					start_Floor ^= end_Floor;
					end_Floor ^= start_Floor;
					start_Floor ^= end_Floor;
				}
			}

			fprintf(poles_File, "[%d,%d,%d,%d]\n", 
					start_Floor,
					end_Floor,
					randWidth(argv[1][0]), 
					randLength(argv[1][0]) 
				);
		}
	}

	fclose(poles_File);

	FILE* stairs_File = fopen("./stairs.txt", "w");

	if (stairs_File == NULL){
		printf("Error Creating/Opening the stairs file. Stairs file is not set.\n");
	}
	else{
		for (int i = 0; i < strtol(argv[4], NULL, 10); i++){
			fprintf(stairs_File, "[%d,%d,%d,%d,%d,%d]\n", 
					randFloor(argv[1][0]), 
					randWidth(argv[1][0]), 
					randLength(argv[1][0]), 
					randFloor(argv[1][0]), 
					randWidth(argv[1][0]), 
					randLength(argv[1][0])
				);
		}
	}

	fclose(stairs_File);


	FILE* flag_File = fopen("./flag.txt", "w");

	if (stairs_File == NULL){
		printf("Error Creating/Opening the flag file. Flag file is not set.\n");
	}
	else{
		fprintf(flag_File, "[%d,%d,%d]\n", 
				randFloor(argv[1][0]), 
				randWidth(argv[1][0]), 
				randLength(argv[1][0])
			);
	}

	fclose(stairs_File);


	/*
	*/

}
