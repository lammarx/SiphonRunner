#include "GameMenu.h"
// метод настройки текстовых объектов пунктов игрового меню
void GameMenu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos) {
	text.setFont(font);                 // шрифт
	text.setFillColor(menu_text_color); // цвет 
	text.setString(str);                // текст
	text.setCharacterSize(size_font);   // размер шрифта
	text.setPosition(xpos, ypos);       // координаты текстового объекта
	text.setOutlineThickness(3);        // толщина контура обводки текста
	text.setOutlineColor(border_color); // цвет контура обводки текста
}
// Выравнивание пунктов меню по левому по правому по центру 
void GameMenu::AlignMenu(int posx) {
	float nullx = 0;
	for (int i = 0; i < max_menu; i++) {
		switch (posx) {
		case 0:
			nullx = 0; // выравнивание по правому краю от установленных координат 
			break;
		case 1:
			nullx = mainMenu[i].getLocalBounds().width;  // по левому краю
			break;
		case 2:
			nullx = nullx = mainMenu[i].getLocalBounds().width / 2;  // по центру
			break;
		}
		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
	}

}
// Конструктор
GameMenu::GameMenu(sf::RenderWindow& window, float menux, float menuy, int index, sf::String name[], int sizeFont, int step)
	:mywindow(window), menu_X(menux), menu_Y(menuy), size_font(sizeFont), menu_Step(step) {
	// Загрузка шрифта
	if (!font.loadFromFile("Resources\\PressStart2P-Regular.ttf")) exit(32);
	max_menu = index; // Количество єлементов меню 
	mainMenu = new sf::Text[max_menu];     // Динамический массив пунктов меню
	// Выстраиваем элементы меню
	for (int i = 0, ypos = static_cast<int>(menu_Y); i < max_menu; i++, ypos += menu_Step) setInitText(mainMenu[i], name[i], menu_X, ypos);
	mainMenuSelected = 0; // Задаём начальное положения выбраного пункта меню
	// цвет выбраного пункта меню
	mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	initGameTitle();
	initGameBackground();
}
// перемещение выбора меню вверх
void GameMenu::MoveUp() {
	mainMenuSelected--;
	// подсвечиваем выбранный пункт меню
	if (mainMenuSelected >= 0) {
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
		mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
	}
	else {
		mainMenu[0].setFillColor(menu_text_color);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
}
// перемещение выбора меню вниз
void GameMenu::MoveDown() {
	mainMenuSelected++;
	// подсвечиваем выбранный пункт меню
	if (mainMenuSelected < max_menu) {
		mainMenu[mainMenuSelected - 1].setFillColor(menu_text_color);
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
	else{
		mainMenu[max_menu - 1].setFillColor(menu_text_color);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}

}
// рисуем элементы меню в графическом окне
void GameMenu::draw() {
	mywindow.draw(gameMenuBackground);
	mywindow.draw(&pipeline[0], pipeline.size(), sf::LineStrip);
	mywindow.draw(gameMenuTitle);
	// перебираем для отрисовки существующие текстовые объекты пунктов меню 	
	for (int i = 0; i < max_menu; i++) mywindow.draw(mainMenu[i]);
}
// назначение цвета элементам пунктов меню
void GameMenu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor) {
	menu_text_color = menColor;    // цвет пунктов меню
	chose_text_color = ChoColor;  // цвет выбраного пункта меню
	border_color = BordColor;    // цвет контура пунктов меню

	for (int i = 0; i < max_menu; i++) {
		mainMenu[i].setFillColor(menu_text_color);
		mainMenu[i].setOutlineColor(border_color);
	}

	mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}

void GameMenu::initGameTitle() {
	gameMenuTitleTexture.loadFromFile("Resources\\gamelogo.png");
	gameMenuTitle.setTexture(gameMenuTitleTexture);
	gameMenuTitle.setOrigin(226.f, 25.5);
	gameMenuTitle.setPosition(1100.f, 250.f);
	gameMenuTitle.setScale(2.f, 2.f);
}

void GameMenu::initGameBackground() {
	gameMenuBackgroundTexture.loadFromFile("Resources\\GameMenuBackground.png");
	gameMenuBackground.setTexture(gameMenuBackgroundTexture);
	sf::Vertex vertex;
	vertex.color = sf::Color(255, 255, 255, 100);

	if (rand() % 1 == 0) {
		vertex.position.x = static_cast<float>(rand() % 1599 + 1); vertex.position.y = 1.f; pipeDirection = 2;
	}
	else {
		vertex.position.x = 1.f; vertex.position.y = static_cast<float>(rand() % 899 + 1); pipeDirection = 0;
	}
	pipeline.push_back(vertex);
}

void GameMenu::updateBackground() {
	if (pipeline.size() >= 500) {
		pipeline.erase(pipeline.begin());
	}
	
	if (rand() > RAND_MAX - 100) {
		sf::Vertex vertex;
		vertex.color = sf::Color(255, 255, 255, 100);
		vertex.position = pipeline[pipeline.size() - 1].position;
		int tempDirection1 = pipeDirection;
		int tempDirection2 = pipeDirection;
		if (pipeDirection == 0) tempDirection1 = 1; if (pipeDirection == 1) tempDirection1 = 0;
		if (pipeDirection == 2) tempDirection1 = 3; if (pipeDirection == 3) tempDirection1 = 2;
		while (pipeDirection == tempDirection1 || pipeDirection == tempDirection2) {
			pipeDirection = rand() % 3;
		}
		pipeline.push_back(vertex);
	}
	if (pipeline[pipeline.size() - 1].position.x >= 1600.f - 2.f) {
		pipeDirection = 1; 
		sf::Vertex vertex; vertex.color = sf::Color(255, 255, 255, 100); vertex.position = pipeline[pipeline.size() - 1].position; 
		pipeline.push_back(vertex);
	}
	else if (pipeline[pipeline.size() - 1].position.x <= 2.f) {
		pipeDirection = 0;
		sf::Vertex vertex; vertex.color = sf::Color(255, 255, 255, 100); vertex.position = pipeline[pipeline.size() - 1].position;
		pipeline.push_back(vertex);
	}
	else if (pipeline[pipeline.size() - 1].position.y >= 900.f - 2.f) {
		pipeDirection = 3;
		sf::Vertex vertex; vertex.color = sf::Color(255, 255, 255, 100); vertex.position = pipeline[pipeline.size() - 1].position;
		pipeline.push_back(vertex);
	}
	else if (pipeline[pipeline.size() - 1].position.y <= 2.f) {
		pipeDirection = 2;
		sf::Vertex vertex; vertex.color = sf::Color(255, 255, 255, 100); vertex.position = pipeline[pipeline.size() - 1].position;
		pipeline.push_back(vertex);
	}

	if (pipeDirection == 0)
		pipeline[pipeline.size() - 1].position.x += 2;
	else if (pipeDirection == 1)
		pipeline[pipeline.size() - 1].position.x -= 2;
	else if (pipeDirection == 2)
		pipeline[pipeline.size() - 1].position.y += 2;
	else if (pipeDirection == 3)
		pipeline[pipeline.size() - 1].position.y -= 2;

	for (int i = 0; i < pipeline.size(); i++) {
		pipeline[i].position.x -= 0.01f;
	}
}
