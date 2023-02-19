#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class GameMenu
{
	float menu_X;                   // ���������� ���� �� X
	float menu_Y;				    // ���������� ���� �� Y
	int menu_Step;                  // ���������� ����� �������� ����
	int max_menu;                   // ������������ ���������� ������� ����
	int size_font;                  // ������ ������
	int mainMenuSelected;           // ����� �������� ������ ���� 
	sf::Font font;                  // ����� ���� 
	// ������������ ������ ��������� �������� �������� ������� ����
	sf::Text* mainMenu;
	sf::Color menu_text_color = sf::Color(159, 182, 206, 255);    // ���� ������� ����
	sf::Color chose_text_color = sf::Color(235, 145, 22, 255);  // ���� ������ ������ ����
	sf::Color border_color = sf::Color::Black;       // ���� ������� ������ ������� ����

	// ��������� ������ ������� ����
	// ���������: ������ �� ��������� ������, �����, ���������� ������
	void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
	// ������ �� ����������� ����
	sf::RenderWindow& mywindow;

	sf::Texture gameMenuTitleTexture;
	sf::Sprite gameMenuTitle;
	sf::Texture gameMenuBackgroundTexture;
	sf::Sprite gameMenuBackground;

	std::vector<sf::Vertex> pipeline;
	int pipeDirection = rand() % 3;
public:
	// ����������� 
	// ���������: ������ �� ����������� ����, ���������� �������� ���� �� x � y
	// ���������� ������� ����, ������ �������� ������� ����, ������ ������, ��� ����� �������� ����
	GameMenu(sf::RenderWindow& window, float menux, float menuy, int index, sf::String name[], int sizeFont = 60, int step = 80);

	~GameMenu() {
		delete[] mainMenu;
	}

	void draw();        // ������ ����

	void MoveUp();     // ����������� ������ ���� �����

	void MoveDown();   // ����������� ������ ���� ����

	// ���� ��������� �������� ����
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

	void AlignMenu(int posx);   // ������������ ��������� ����

	int getSelectedMenuNumber() { // ���������� ����� ���������� �������� ����
		return mainMenuSelected;
	}

	void updateBackground();

	void initGameTitle();
	void initGameBackground();
};

#endif
