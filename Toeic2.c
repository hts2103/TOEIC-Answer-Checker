#include<stdio.h>

//関数のプロトタイプ宣言
int modeSelecter(int *, int *, char *);
int answerRegister(int *, int *, char *);
int answerChecker(int *, int *, char *, char *);
int freeMode();

int main(void){
    int i, n, ad = 0;
    double pct;
    char ans[n + 1], cans[n + 1], sec;//文字配列にはヌル文字も入るので要素は1つ多くする

    printf("\nTOEIC対策模試用回答フォームです。\n");
    printf("\nListening(L)、Reading(R)、両方(M)、自由(F)のいずれかの受験モードを選択し、L,R,M,Fの内1つを入力してください。\nMode：");
    modeSelecter(&n, &ad, &sec);
    //printf("%d %d %c", n, ad, sec);
	printf("\n[TOEIC回答欄]\n回答を入力してください。\n");
	answerRegister(&n, &ad, ans);////配列の[]を無くすと配列のアドレスを示す。
	printf("\n[TOEIC正解欄]\n正解を入力してください。\n");
	answerRegister(&n, &ad, cans);
	printf("\n[TOEIC正誤状況]\n");
	answerChecker(&n, &ad, ans, cans);

    return 0;
}

//関数の詳細を定義
int modeSelecter(int *np, int *adp, char *secp){//int型ポインタ変数npは、&nで初期化される。なお、ポインタ変数がどの変数のアドレスを示すのかを前もって明確にする（初期化）のが望ましい。
    scanf("%c", secp);//scanfの引数はどれもポインタでなくてはならない
    if(*secp == 'L'){
        *np = 5;
        printf("\nListeningが選択されました。\n");
    }else if(*secp == 'M'){
        *np = 10;
        printf("\nLisetning&Readingが選択されました。\n");
    }else if(*secp == 'R'){
        *np = 5;
        *adp = 5;
        printf("\nReadingが選択されました。\n");
    }else if(*secp == 'F'){
		printf("\n開始する問題番号を入力してください。\nNo.");
		scanf("%d", adp);
		*adp = *adp - 1;
        *np = 10 - *adp;
	}else{
		printf("\n不正な文字です。もう一度L,R,M,Fのいずれかを入力してください。 %c", *secp);
        modeSelecter(np, adp, secp);
		return 1;
    }
    return 0;
}

int freeMode(){
	return 0;
}

int answerRegister(int *np, int *adp, char *ansp){
	int i;

	for(int i = 0; i < *np; i++){
		printf("No.%d ", i + 1 + *adp);
		scanf("%s", &ansp[i]);
		while(ansp[i] < 97 || 100 < ansp[i]){
			printf("a～bのいずれかを入力してください。\n");
			printf("No.%d ", i + 1 + *adp);
			scanf("%s", &ansp[i]);
		}
	}
	return 0;
}

int answerChecker(int *np, int *adp, char *ansp1, char *ansp2){
	int i, count = 0;
	double pct;

	for(int i = 0; i < *np; i++){
		printf("No.%d ", i + 1 + *adp);
		if(ansp1[i] == ansp2[2]){
			printf("○\n");
			count++;
		}else{
			printf("×\n");
		}
	}
	pct = (double) count / (*np) * 100;
	printf("\nあなたの正解数は「%d問中%d問」、正解率「%.2f%」です。\n", *np, count, pct);

	return 0;
}