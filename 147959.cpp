#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	int kari_goukei = 0;	//���v�l�i�̈ꎞ�ۑ��p
	int price = 0;			//�ő升�v�l
	
	char set[5];			//�ő升�v�l�̃Z�b�g

	char figure[11];
	figure[0] = 0;			//�t�B�M���A�̐���0�̎��̒l�i
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

	//1�Z�b�g��
	for ( int first = 1; first <= 10; first++ ){
	
		//2�Z�b�g��
		for ( int second = 0; second <= 5; second++ ){
			//2�Z�b�g�̍��v��10�𒴂����ꍇbreak
			if ( (first + second) > 10 ){
				break;
			}

			//3�Z�b�g��
			for ( int third = 0; third <= 3; third++ ){
				//3�Z�b�g�̍��v��10�𒴂����ꍇbreak
				if ( (first + second + third) > 10 ){
					break;
				}
				
				//4�Z�b�g��
				for ( int fourth = 0; fourth <= 2; fourth++ ){
					//4�Z�b�g�̍��v��10�𒴂����ꍇbreak
					if ( (first + second + third + fourth) > 10 ){
						break;
					}
					
					//5�Z�b�g��
					for ( int fifth = 0; fifth <= 2; fifth++ ){
						//5�Z�b�g�̍��v��10�𒴂����ꍇbreak
						if ( (first + second + third + fourth + fifth) > 10 ){
							break;
						}

						//5�Z�b�g�̍��v��10�����̏ꍇ10�̂ɂȂ�܂�1�����p
						int i = 10 - (first + second + third + fourth + fifth);
						kari_goukei = figure[first] + figure[second] + figure[third] + figure[fourth] + figure[fifth] + (i * figure[1]);
						
						//�ő�l�̕ۑ�
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