#include "MainWindow.h"

void MainWindow::initVariables() {
	this->window = nullptr;
}

void MainWindow::initWindow() {
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Template window");
	this->window->setFramerateLimit(144);
}

MainWindow::MainWindow() {
	this->initVariables();
	this->initWindow();
}

MainWindow::~MainWindow() {
	delete this->window;
}

const bool MainWindow::running() const {
	return this->window->isOpen();
}

void MainWindow::pollEvents() {
	while (this->window->pollEvent(event)) {

		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close(); break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				this->window->close(); break;
			}
		default:
			break;
		}
	}
}

void MainWindow::updateMousePositions() {
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void MainWindow::update() {

	this->pollEvents();

	this->updateMousePositions();
}

void MainWindow::render() {

	this->window->clear();

	this->window->display();
}
