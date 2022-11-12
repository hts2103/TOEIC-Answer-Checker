#include<stdio.h>

int main(void)
{
	int i, n, count = 0, flag[n], ad;
	double pct;
	char ans[n + 1], cans[n + 1], sec;//文字配列にはヌル文字も入るので要素は1つ多くする
	
	printf("\nTOEIC対策模試用回答フォームです。\n");
	printf("\nListening（L）とReading（R）のどちらか、または両方（B）を受験しますか？L,R,Bのいずれかを入力してください。 ");
	scanf("%c", &sec);
	if(sec == 'L'){
		n = 100;
		ad = 0;
		printf("\nListeningが選択されました。\n");
	}else if(sec == 'B'){
		n = 200;
		ad = 0;
		printf("\nListening&Readingが選択されました。\n");
	}else if(sec == 'R'){
		n = 100;
		ad = 100;
		printf("\nReadingが選択されました。\n");
	}else{
		printf("\nERROR!\n");
		return 1;
	}
	printf("\n[TOEIC回答欄]\n回答を入力してください。\n");
	for(int i = 0; i < n; i++){
		printf("No%d ", i + 1 + ad);//変
		scanf("%s", &ans[i]);//文字配列でも整数配列のように1要素ずつ入力する場合は&を付ける。&がないときは全要素を一気に入力できる。
		while(ans[i] < 97 || 100 < ans[i]){
			printf("ａ～ｄのいずれかを入力してください。\n");
			printf("No%d ", i + 1 + ad);//変
			scanf("%s", &ans[i]);//文字配列は文字列だから入力には%sを使う
		}
	}
	printf("\n[TOEIC正解欄]\n正解を入力してください。\n");
	for(int i = 0; i < n; i++){
		printf("No%d ", i + 1 + ad);//変
		scanf("%s", &cans[i]);
		while(cans[i] < 97 || 100 < cans[i]){
			printf("ａ～ｄのいずれかを入力してください。\n");
			printf("No%d ", i + 1 + ad);//変
			scanf("%s", &cans[i]);
		}
	}
	printf("\n[TOEIC正誤欄]\nあなたの回答の正誤状況です。\n");
	for(int i = 0; i < n; i++){
		printf("No%d ", i + 1 + ad);//変
		if(cans[i] == ans[i]){
			printf("○\n");
			flag[i] = 1;
		}else{
			printf("x\n");
			flag[i] = 0;
		}
		count = count + flag[i];
	}
	pct = (double) count / n * 100;
	printf("\nあなたの正解数は「%d問中%d問」、正解率「%.2f%」です。\n", n, count, pct);
	
	return 0;
}