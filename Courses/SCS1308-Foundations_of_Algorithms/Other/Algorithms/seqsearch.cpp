// Sequential Search

typedef int keytype;
typedef int* index;

void seqsearch(int n, const keytype S[], keytype x, index location){
	int location = 0;
	while (location <= n && S[location] != x){
		location++;
	}
	if (location > n){
		location = -1;
	}
}

int main(void){
	//seqsearch();

	return 0;
}
