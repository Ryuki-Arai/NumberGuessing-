//�w�b�_�[�t�@�C���ǂݍ���
#include "Dxlib.h"
#include <math.h>
#include "font.h"
#include "keymacro.h"
#include "color.h"

void game(void);
int mozi(void);

//�R���p�C�����̌x���\���}��
#pragma warning( disable:4305 4244 4305 )

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	SetGraphMode(400, 630, 32);		//��ʃT�C�Y�ݒ�(�ǂꂩ�ЂƂ�I��)
	ChangeWindowMode(TRUE);				//�E�B���h�E���[�h�ŋN���A�R�����g�A�E�g�Ńt���X�N���[��
	if (DxLib_Init() == -1) return -1;	//DX���C�u����������
	SetDrawScreen(DX_SCREEN_BACK);		//����ʂɕ`��

	//�t�H���g�n���h���쐬
	int font[10];
	font[0] = FONT(FDATA, a, FTYPE);
	font[1] = FONT(FDATA, b, FTYPE);
	font[2] = FONT(FDATA, c, FTYPE);
	font[3] = FONT(FDATA, d, FTYPE);
	font[4] = FONT(FDATA, e, FTYPE);
	font[5] = FONT(FDATA, f, FTYPE);
	font[6] = FONT(FDATA, g, FTYPE);
	font[7] = FONT(FDATA, h, FTYPE);
	font[8] = FONT(FDATA, i, FTYPE);
	font[9] = FONT(FDATA, j, FTYPE);

	while (ProcessMessage() == 0 && ESC == 0)	//OS����I���w�������邩�AESC�L�[���������܂ŌJ��Ԃ�
	{
		ClearDrawScreen();	//�`���ʁi����ʁj�����ŃN���A

		DRAW(100, 100, EX1, RED, font[3], "Dez\nNum");
		DRAW(100, 320, EX1, BLUE, font[6], "enter\n�@to \nstart");
		if (ENTER == 1)game();

		ScreenFlip();	//�\�Ɨ��i�`���ʁj�̓��ꊷ��
	}
	//DX���C�u�����I������
	DxLib_End();

	return 0;

}

void game(void) {
	//�ϐ��錾
	int qwes = GetRand(100);
	int ans = NULL;
	int cf = FALSE;

	//�t�H���g�n���h���쐬
	int font[10];
	font[0] = FONT(FDATA, a, FTYPE);
	font[1] = FONT(FDATA, b, FTYPE);
	font[2] = FONT(FDATA, c, FTYPE);
	font[3] = FONT(FDATA, d, FTYPE);
	font[4] = FONT(FDATA, e, FTYPE);
	font[5] = FONT(FDATA, f, FTYPE);
	font[6] = FONT(FDATA, g, FTYPE);
	font[7] = FONT(FDATA, h, FTYPE);
	font[8] = FONT(FDATA, i, FTYPE);
	font[9] = FONT(FDATA, j, FTYPE);

	while (ProcessMessage() == 0 && ESC == 0)	//OS����I���w�������邩�AESC�L�[���������܂ŌJ��Ԃ�
	{
		ClearDrawScreen();	//�`���ʁi����ʁj�����ŃN���A

		if (cf == FALSE) {
			DRAW(10, 10, 1.0, 1.0, RAND, font[0], "??");
			if (SPACE == 1) ans = mozi();
		}
		else if (cf == TRUE) {
			DRAW(10, 10, 1.0, 1.0, RAND, font[0], "%d", qwes);
			DRAW(10, 600, EX1, YELLOW, font[8], "push spase");
			if (SPACE == 1)return ;
		}
		DRAW(10, 300, EX1, WHITE, font[8], "push spase to answer");
		if (ans != NULL) {
			if (ans == qwes) {
				DRAW(10, 550, EX1, BLUE, font[7], "Excelent!");
				cf = TRUE;
			}
			else if (ans > qwes)DRAW(10, 550, EX1, BLUE, font[7], "Under than");
			else if (ans < qwes)DRAW(10, 550, EX1, BLUE, font[7], "orver than");
		}

		ScreenFlip();	//�\�Ɨ��i�`���ʁj�̓��ꊷ��

	}

	//DX���C�u�����I������
	DxLib_End();

	return ;
}

int mozi(void) {
	//�ϐ��錾
	int ans = NULL;

	//�t�H���g�n���h���쐬
	int font[10];
	font[0] = FONT(FDATA, 200, 5, FTYPE);
	font[1] = FONT(FDATA, 150, 5, FTYPE);
	font[2] = FONT(FDATA, 120, 4, FTYPE);
	font[3] = FONT(FDATA, 100, 4, FTYPE);
	font[4] = FONT(FDATA, 90, 3, FTYPE);
	font[5] = FONT(FDATA, 72, 3, FTYPE);
	font[6] = FONT(FDATA, 64, 2, FTYPE);
	font[7] = FONT(FDATA, 32, 2, FTYPE);
	font[8] = FONT(FDATA, 24, 2, FTYPE);
	font[9] = FONT(FDATA, 16, 2, FTYPE);

	while (ans == NULL) {
		ClearDrawScreen();	//�`���ʁi����ʁj�����ŃN���A

		DRAW(10, 400, EX1, GREEN, font[3], "??=");
		SetFontSize(100);
		ChangeFont(FDATA);
		ans = KeyInputNumber(230, 400, 100, 0, FALSE);

		ScreenFlip();	//�\�Ɨ��i�`���ʁj�̓��ꊷ��
	}

	return ans;
}