#include <bits/stdc++.h>
#include <windows.h>
#include "init.hpp"
#include "function.hpp"
#include "end&day.hpp"
using namespace std; 
//Note: This game is based on the Windows operating system, some features may go wrong in Unix
//Note: The committers, modifiers and makers live in China, so we don't have a lot of energy to translate the in-game tips, please understand!
//Produced by wuyuhan01              Modified: jinhongkun       Optimized with the source code more readable: guozhenkai
//At present, the source code correction is still in progress, but the game can run normally, but please wait to read and modify the source code
//Annotations are all machine-flipped
void night2(int hhh, int hhhh) {
	system("cls");
	system("color 0f"); 
	print(hhh, hhhh); 
	cout << "天~黑~请~闭~眼~" << endl; 
	if (n >= 12) shoushui(hhh, hhhh); 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "狼~人~请~睁~眼~" << endl;
	if (player[MY].name == "狼人 " && player[MY].life == 1) { 
		Sleep(3000); 
		cout << endl << "请问你们要杀谁:" << endl << "输入:"; 
		cin >> kill1; Sleep(1500); 
		system("cls"); print(hhh, hhhh); 
		cout << "今晚你们要杀的是" << kill1 << "号玩家" << endl;
	} else { 
		Sleep(4000); 
		system("cls"); 
		print(hhh, hhhh); 
		cout << "请问你们要杀谁?" << endl; 
		do { 
			srand(time(0)); 
			int x = rand() % n + 1; 
			if (player[x].name != "狼人 " && player[x].life == 1) {
				kill1 = x; 
				break; 
			} 
		} while (1); 
		Sleep(5000); 
	} 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "狼~人~请~闭~眼~" << endl; 
	Sleep(2000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "女~巫~请~睁~眼~" << endl; 
	Sleep(2000); 
	system("cls"); 
	print(hhh, hhhh); 
	if (player[MY].name == "女巫 " && player[MY].life == 1) { 
		Sleep(1000); 
		if (jieyao == 1) { 
			cout << "今晚" << kill1 << "号玩家被杀" << endl;
			Sleep(500); cout << "请问你要救吗???" << endl << "A. 救 B.不救" << endl << "输入:"; 
			cin >> a; 
			if (a == 'A') { 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "请问你要毒吗???" << endl; 
				Sleep(2000); 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "今晚" << kill1 << "号玩家被你解救" << endl; 
				jieyao = 0; 
				if (shou != kill1) kill1 = 0; 
			} else { 
				if (shou == kill1) kill1 = 0; 
				Sleep(2000); 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:"; 
				cin >> a; 
				if (a == 'A') { 
					cout << "请问你要毒谁???" << endl << "输入:"; 
					cin >> kill2; 
					while (player[kill2].life != 1) { 
						cout << "输入错误,请重新输入:" << endl; 
						cin >> kill2; 
					} 
					duyao = 0; 
				} 
			} 
		} else if (duyao == 1) { 
			if (shou == kill1) kill1 = 0; 
			Sleep(2000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:"; 
			cin >> a; 
			if (a == 'A') { 
				cout << "请问你要毒谁???" << endl << "输入:"; 
				cin >> kill2; 
				while (player[kill2].life != 1) { 
					cout << "输入错误,请重新输入:" << endl; 
					cin >> kill2; 
				} 
				duyao = 0;
			} 
		} else { 
			Sleep(2000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你要毒吗???" << endl; 
		} 
	} else { 
		bool b = 0; 
		cout << "请问你是否要用解药???" << endl; 
		int FFF = 0, kkkk; 
		for (int i = 1; i <= n; i++) { 
			if (player[i].life == 1 && player[i].name == "村民 ") FFF++; 
			if (player[i].name == "女巫 ") kkkk = i; 
		} 
		if (jieyao == 1 && player[kkkk].life == 1) { 
			if (FFF == 1) { 
				if (shou == kill1) jieyao = 1; 
				else jieyao = 0; 
				kill1 = 0; 
				b = 1; 
			} else for (int i = 1; i <= n; i++) { 
				if (player[i].name == "女巫 " && kill1 == i) { 
					kill1 = 0; 
					if (shou == kill1) jieyao = 1; 
					else jieyao = 0; 
					b = 1; 
					break; 
				} else if (player[i].name == "预言家 " && kill1 == i) { 
					kill1 = 0; 
					if (shou == kill1) jieyao = 1; 
					else jieyao = 0; 
					b = 1; 
					break; 
				} 
			} 
		} 
		Sleep(3000); 
		if (b == 0 && duyao == 1 && player[kkkk].life == 1) { 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你是否要用毒药???" << endl; 
			srand(time(0)); 
			int x = rand() % 2; 
			Sleep(1500); 
			cout << "请问你要毒谁???" << endl; 
			if (x == 1) { 
				duyao = 0; 
				int y = rand() % n + 1; 
				while ((player[y].name == "女巫 " || player[y].name == "预言家 " || y == kill1) || player[y].life == 0) y = rand() % n + 1; 
				kill2 = y; 
			} 
		} else { 
			Sleep(3000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你是否要用毒药???" << endl; 
			Sleep(3000); 
			cout << "请问你要毒谁???" << endl; 
			Sleep(3000); 
		} 
	} 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "女~巫~请~闭~眼~" << endl; 
	if (n > 6) { 
		Sleep(3000); 
		system("cls"); 
		print(hhh, hhhh); 
		cout << "预~言~家~请~睁~眼~" << endl; 
		if (player[MY].name == "预言家 " && player[MY].life == 1) { 
			Sleep(3000); 
			cout << "请问你想查验谁???" << endl << "输入:"; 
			int x; cin >> x; player[x].know = 1; 
			Sleep(2000); system("cls"); print(hhh, hhhh); cout << "他的身份是:"; if (player[x].name == "狼人 ") cout << "狼人" << endl; else cout << "好人" << endl; Sleep(3000); } else { Sleep(3000); cout << "请问你想查验谁???" << endl; Sleep(3000); system("cls"); print(hhh, hhhh); cout << "他的身份是:......"; Sleep(3000); } Sleep(3000); system("cls"); print(hhh, hhhh); cout << "预~言~家~请~闭~眼~" << endl; } Sleep(3000); if (kill1 != 0) player[kill1].life = 0; if (kill2 != 0) player[kill2].life = 0; player[kill1].how = 1; player[kill2].how = 3; system("cls"); system("color F0"); print(hhh + 1, 0); } bool lr = 0; void panduanlieren() { if (lr == 1) return; if (MY == lieren) { cout << "请射杀一名玩家" << endl; int x; cin >> x; while (player[x].life != 1) { cout << "输入错误,请重新输入" << endl; cin >> x; } Sleep(1000); cout << lieren << "号猎人发动技能,开枪带走了" << x << "号" << endl; player[x].life = 0; player[x].how = 4; } else if (n >= 9) { srand(time(0)); int x = rand() % n + 1; while (player[x].life != 1) { x = rand() % n + 1; } Sleep(1000); cout << lieren << "号猎人发动技能,开枪带走了" << x << "号" << endl; player[x].life = 0; player[x].how = 4; } lr = 1; } void print1() { cout << "天亮了,昨晚"; if (kill1 != 0 || kill2 != 0) { cout << kill1 << "号"; if (kill2 != 0) { cout << "," << kill2 << "号"; kill2 = 0; } cout << "被杀" << endl; } else cout << "是平安夜" << endl; } int main() {cout<<"-----------狼人杀----------\n\n\n\n\n\n"<<"jinhongkun修改 wuyuhan01制作 郭镇恺优化\n\n\n\n\nTips：三人无关系，只是看到对方的代码然后改了而已，原版wuyuhan01制作\n\n\n\n\n\n\n\n\n";system("pause"); system("cls");cout<<"\n\n\n\n\n\n\n----------狼人杀----------\n\n\n\n\n\n\n浙大noj第二大学生自创游戏";system("pause");system("cls"); cout << " " << "狼人杀online" << endl; cout << "请输入人数个数:" << endl; scanf("%d", &n); cout << "加载时间长，请耐心等待"; init1(); init2(n); int k = 1; do { srand(time(0)); init3(k); cout << "."; Sleep(17); k++; } while (k <= n); system("cls"); system("color F0"); cout << "游戏即将开始"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } Sleep(1500); cout << endl << endl << "请大家查看身份牌......" << endl; Sleep(45); srand(time(0)); MY = rand() % n + 1; cout << "您的身份是:" << player[MY].name << endl; Sleep(500); cout << "在" << player[MY].num << "号位上" << endl; system("pause"); system("cls"); player[MY].know = 2; print(1, 0); cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night(); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(2, 0); system("cls"); print(2, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night2(2, 1); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(3, 0); system("cls"); print(3, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night2(3, 1); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(4, 0); system("cls"); print(4, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night2(4, 1); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(5, 0); system("cls"); print(5, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night2(5, 1); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(6, 0); system("cls"); print(6, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } cout << "即将进入夜晚"; for (int i = 1; i <= 6; i++) { cout << "."; Sleep(500); } night2(6, 1); print1(); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } if (player[lieren].life == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } toupiao(7, 0); system("cls"); print(7, 0); if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } else if (player[lieren].life == 0 && lr == 0) { panduanlieren(); } if (game_over()) { Sleep(1000); system("cls"); cout << "游戏结束" << endl; printhhh(); return 0; } while (1) system("pause"); return 0; }
