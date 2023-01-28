//ヘッダーファイル読み込み
#include "Dxlib.h"
#include <math.h>
#include "font.h"
#include "keymacro.h"
#include "color.h"

void game(void);
int mozi(void);

//コンパイル時の警告表示抑制
#pragma warning( disable:4305 4244 4305 )

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	SetGraphMode(400, 630, 32);		//画面サイズ設定(どれかひとつを選択)
	ChangeWindowMode(TRUE);				//ウィンドウモードで起動、コメントアウトでフルスクリーン
	if (DxLib_Init() == -1) return -1;	//DXライブラリ初期化
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面に描画

	//フォントハンドル作成
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

	while (ProcessMessage() == 0 && ESC == 0)	//OSから終了指示が来るか、ESCキーを押されるまで繰り返し
	{
		ClearDrawScreen();	//描画画面（裏画面）を黒でクリア

		DRAW(100, 100, EX1, RED, font[3], "Dez\nNum");
		DRAW(100, 320, EX1, BLUE, font[6], "enter\n　to \nstart");
		if (ENTER == 1)game();

		ScreenFlip();	//表と裏（描画画面）の入れ換え
	}
	//DXライブラリ終了処理
	DxLib_End();

	return 0;

}

void game(void) {
	//変数宣言
	int qwes = GetRand(100);
	int ans = NULL;
	int cf = FALSE;

	//フォントハンドル作成
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

	while (ProcessMessage() == 0 && ESC == 0)	//OSから終了指示が来るか、ESCキーを押されるまで繰り返し
	{
		ClearDrawScreen();	//描画画面（裏画面）を黒でクリア

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

		ScreenFlip();	//表と裏（描画画面）の入れ換え

	}

	//DXライブラリ終了処理
	DxLib_End();

	return ;
}

int mozi(void) {
	//変数宣言
	int ans = NULL;

	//フォントハンドル作成
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
		ClearDrawScreen();	//描画画面（裏画面）を黒でクリア

		DRAW(10, 400, EX1, GREEN, font[3], "??=");
		SetFontSize(100);
		ChangeFont(FDATA);
		ans = KeyInputNumber(230, 400, 100, 0, FALSE);

		ScreenFlip();	//表と裏（描画画面）の入れ換え
	}

	return ans;
}