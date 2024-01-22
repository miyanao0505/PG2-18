#include <Novice.h>
#include "Script/Player.h"
#include "Script/Enemy.h"

const char kWindowTitle[] = "LC1A_ミヤザワ_ナオキ_PG2_18_静的メンバ変数_確認課題";

bool Enemy::_isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// プレイヤー
	Player* playerObj = new Player(Vec2{ 640, 500 }, 15, 6);

	// 敵
	Enemy* enemyObjA = new Enemy(Vec2{ 640, 200 }, 15, 3);
	Enemy* enemyObjB = new Enemy(Vec2{ 440, 300 }, 15, 3);
	Enemy* enemyObjC = new Enemy(Vec2{ 240, 400 }, 15, 3);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// キー入力
		if (keys[DIK_R] && !preKeys[DIK_R])
		{
			Enemy::_isAlive = true;
		}

		// プレイヤーの動作
		playerObj->Update(keys, preKeys);

		// 敵の動作
		enemyObjA->Update();
		enemyObjB->Update();
		enemyObjC->Update();

		// 当たり判定
		for (int i = 0; i < playerObj->_bulletNum; i++)
		{
			if (MyTools::Hit(playerObj->_bulletObj[i]->_pos, enemyObjA->_pos, playerObj->_bulletObj[i]->_radius, enemyObjA->_radius))
			{
				enemyObjA->_isAlive = false;
				break;
			}
			if (MyTools::Hit(playerObj->_bulletObj[i]->_pos, enemyObjB->_pos, playerObj->_bulletObj[i]->_radius, enemyObjB->_radius))
			{
				enemyObjB->_isAlive = false;
				break;
			}
			if (MyTools::Hit(playerObj->_bulletObj[i]->_pos, enemyObjC->_pos, playerObj->_bulletObj[i]->_radius, enemyObjC->_radius))
			{
				enemyObjC->_isAlive = false;
				break;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 敵
		enemyObjA->Draw();
		enemyObjB->Draw();
		enemyObjC->Draw();

		// プレイヤー
		playerObj->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
