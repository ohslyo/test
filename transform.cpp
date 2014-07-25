#include <fstream>
#include <iostream>
#include <string>

//変換済みの単語かチェック
bool finished_word(char* str, char word[2048][5], int word_count){
	for (int i = 0; i < word_count; i++){
		if (strcmp(str, word[i]) == 0){
			return false;
		}
	}
	return true;
}

int main()
{
	char str[5];	//ファイル読み込み用バッファ

	char count = 0;	//変換回数

	char word[2048][5] = { 0 };	//変換済み単語保存
	int word_count = 1;	//変換済み単語数

	char ftmp_procedure[600][128][5] = { 0 };	//前ループまでの変換単語保存
	char fprocedure[600][128][5] = { 0 };	//今ループで新たに変換した単語保存
	int candidate = 0; //変換候補数
	int candidate_save = 0;	//変換候補数保存

	//開始位置の"free"を保存
	strcpy_s(ftmp_procedure[0][0],"free");
	strcpy_s(word[0], "free");

	//"work"にたどり着くまで無限ループ
	while (1){

		//ファイル読み込み
		std::ifstream ifs("C:/home/dictionary.txt");
		if (ifs.fail())
		{
			std::cerr << "失敗" << std::endl;
			return EXIT_FAILURE;
		}

		candidate_save = candidate;	//前ループの変換候補数を今ループのループ回数とする
		candidate = 0;	//変換候補数をリセット

		//読み込んだ行数分ループ
		while (ifs.getline(str, 5)){

			int i = 0;

			//前ループで変換した単語数分ループ
			do{	//while (i < candidate_save);

				
				//前ループでの変換単語と3文字同じものをピックアップ
				char match = 0;	//合致文字数
				for (int k = 0; k < 4; k++){
					if (str[k] == ftmp_procedure[i][count][k]){
						match++;
					}
				}

				//ピックアップした単語がすでに変換済みのものかチェック
				if ((match == 3) && (finished_word(str, word, word_count))){
					strcpy_s(word[word_count], str);

					//3文字同じかつ未返還のものを保存
					memcpy(fprocedure[candidate], ftmp_procedure[i], sizeof(ftmp_procedure[i]));
					strcpy_s(fprocedure[candidate][count + 1], str);

					//"work"かどうかチェック
					if (strcmp(str,"work") == 0){
						for (int l = 0; l <= count + 1; l++){
							std::cout << "[" << fprocedure[candidate][l] << "]" << std::endl;
						}
						std::cin.get();
						return 0;
					}
					word_count++;	//変換済み単語数のカウントアップ
					candidate++;	//変換候補数のカウントアップ
				}
				i++;
			} while (i <= candidate_save);
		}
		//今ループで新たに変換した単語を前ループまでの変換単語に保存
		memcpy(ftmp_procedure, fprocedure, sizeof(fprocedure));
		count++;	//変換回数のカウントアップ
	}
	
	return 1;
}