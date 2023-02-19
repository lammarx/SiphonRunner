#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class GameMenu
{
	float menu_X;                   // Координаты меню по X
	float menu_Y;				    // Координаты меню по Y
	int menu_Step;                  // Расстояние между пунктами меню
	int max_menu;                   // Максимальное количество пунктов меню
	int size_font;                  // Размер шрифта
	int mainMenuSelected;           // Номер текущего пункта меню 
	sf::Font font;                  // Шрифт меню 
	// Динамический массив текстовых объектов названий пунктов меню
	sf::Text* mainMenu;
	sf::Color menu_text_color = sf::Color(159, 182, 206, 255);    // Цвет пунктов меню
	sf::Color chose_text_color = sf::Color(235, 145, 22, 255);  // Цвет выбора пункта меню
	sf::Color border_color = sf::Color::Black;       // Цвет обводки текста пунктов меню

	// Настройка текста пунктов меню
	// Параметры: ссылка на текстовый объект, текст, координаты текста
	void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
	// Ссылка на графическое окно
	sf::RenderWindow& mywindow;

	sf::Texture gameMenuTitleTexture;
	sf::Sprite gameMenuTitle;
	sf::Texture gameMenuBackgroundTexture;
	sf::Sprite gameMenuBackground;

	std::vector<sf::Vertex> pipeline;
	int pipeDirection = rand() % 3;
public:
	// Конструктор 
	// Параметры: ссылка на графическое окно, координаты игрового меню по x и y
	// количество пунктов меню, массив названий пунктов меню, размер шрифта, шаг между пунктами меню
	GameMenu(sf::RenderWindow& window, float menux, float menuy, int index, sf::String name[], int sizeFont = 60, int step = 80);

	~GameMenu() {
		delete[] mainMenu;
	}

	void draw();        // Рисуем меню

	void MoveUp();     // Перемещение выбора меню вверх

	void MoveDown();   // Перемещение выбора меню вниз

	// Цвет элементов игрового меню
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

	void AlignMenu(int posx);   // Выравнивание положения меню

	int getSelectedMenuNumber() { // Возвращает номер выбранного элемента меню
		return mainMenuSelected;
	}

	void updateBackground();

	void initGameTitle();
	void initGameBackground();
};

#endif
