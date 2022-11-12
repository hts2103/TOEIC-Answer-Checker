#include<stdio.h>

//�֐��̃v���g�^�C�v�錾
int modeSelecter(int *, int *, char *);
int answerRegister(int *, int *, char *);
int answerChecker(int *, int *, char *, char *);
int freeMode();

int main(void){
    int i, n, ad = 0;
    double pct;
    char ans[n + 1], cans[n + 1], sec;//�����z��ɂ̓k������������̂ŗv�f��1��������

    printf("\nTOEIC�΍��͎��p�񓚃t�H�[���ł��B\n");
    printf("\nListening(L)�AReading(R)�A����(M)�A���R(F)�̂����ꂩ�̎󌱃��[�h��I�����AL,R,M,F�̓�1����͂��Ă��������B\nMode�F");
    modeSelecter(&n, &ad, &sec);
    //printf("%d %d %c", n, ad, sec);
	printf("\n[TOEIC�񓚗�]\n�񓚂���͂��Ă��������B\n");
	answerRegister(&n, &ad, ans);////�z���[]�𖳂����Ɣz��̃A�h���X�������B
	printf("\n[TOEIC����]\n��������͂��Ă��������B\n");
	answerRegister(&n, &ad, cans);
	printf("\n[TOEIC�����]\n");
	answerChecker(&n, &ad, ans, cans);

    return 0;
}

//�֐��̏ڍׂ��`
int modeSelecter(int *np, int *adp, char *secp){//int�^�|�C���^�ϐ�np�́A&n�ŏ����������B�Ȃ��A�|�C���^�ϐ����ǂ̕ϐ��̃A�h���X�������̂���O�����Ė��m�ɂ���i�������j�̂��]�܂����B
    scanf("%c", secp);//scanf�̈����͂ǂ���|�C���^�łȂ��Ă͂Ȃ�Ȃ�
    if(*secp == 'L'){
        *np = 100;
        printf("\nListening���I������܂����B\n");
    }else if(*secp == 'M'){
        *np = 200;
        printf("\nLisetning&Reading���I������܂����B\n");
    }else if(*secp == 'R'){
        *np = 100;
        *adp = 100;
        printf("\nReading���I������܂����B\n");
    }else if(*secp == 'F'){
		printf("\n�J�n������ԍ�����͂��Ă��������B\nNo.");
		scanf("%d", adp);
		*adp = *adp - 1;
        *np = 200 - *adp;
	}else{
		printf("\n�s���ȕ����ł��B������xL,R,M,F�̂����ꂩ����͂��Ă��������B %c", *secp);
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
			printf("a�`b�̂����ꂩ����͂��Ă��������B\n");
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
			printf("��\n");
			count++;
		}else{
			printf("�~\n");
		}
	}
	pct = (double) count / (*np) * 100;
	printf("\n���Ȃ��̐��𐔂́u%d�⒆%d��v�A���𗦁u%.2f%�v�ł��B\n", *np, count, pct);

	return 0;
}