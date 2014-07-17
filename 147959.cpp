#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	int kari_goukei = 0;	//合計値段の一時保存用
	int price = 0;			//最大合計値
	
	char set[5];			//最大合計値のセット

	char figure[11];
	figure[0] = 0;			//フィギュアの数が0の時の値段
	figure[1] = 1;
	figure[2] = 6;
	figure[3] = 8;
	figure[4] = 10;
	figure[5] = 17;
	figure[6] = 18;
	figure[7] = 20;
	figure[8] = 24;
	figure[9] = 26;
	figure[10] = 30;

	//1セット目
	for ( int first = 1; first <= 10; first++ ){
	
		//2セット目
		for ( int second = 0; second <= 5; second++ ){
			//2セットの合計が10を超えた場合break
			if ( (first + second) > 10 ){
				break;
			}

			//3セット目
			for ( int third = 0; third <= 3; third++ ){
				//3セットの合計が10を超えた場合break
				if ( (first + second + third) > 10 ){
					break;
				}
				
				//4セット目
				for ( int fourth = 0; fourth <= 2; fourth++ ){
					//4セットの合計が10を超えた場合break
					if ( (first + second + third + fourth) > 10 ){
						break;
					}
					
					//5セット目
					for ( int fifth = 0; fifth <= 2; fifth++ ){
						//5セットの合計が10を超えた場合break
						if ( (first + second + third + fourth + fifth) > 10 ){
							break;
						}

						//5セットの合計が10未満の場合10体になるまで1つずつ売却
						int i = 10 - (first + second + third + fourth + fifth);
						kari_goukei = figure[first] + figure[second] + figure[third] + figure[fourth] + figure[fifth] + (i * figure[1]);
						
						//最大値の保存
						if  ( kari_goukei > price ){
							set[0] = first;
							set[1] = second;
							set[2] = third;
							set[3] = fourth;
							set[4] = fifth;
							price = kari_goukei;
						}
					}
				}
			}
		}
	}
	
	printf("set=");
	for ( int i = 0; i < 5; i++ ){
		printf("%d ",set[i]);
	}
	
	printf("\nprice=%d\n", price);
	return 0;
}